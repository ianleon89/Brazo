/*
   ********************* Authors *********************
   ***** Laboratorio de Sistemas Embebidos (LSE) *****
   *****    http://laboratorios.fi.uba.ar/lse    *****
   ******************* 20/12/2011 ********************
     Ezequiel Espósito <ezequiel.esposito@gmail.com>
         Alan Kharsansky <akharsa@gmail.com>
       Federico Roasio <federoasio@gmail.com>
     Daniel Schermuk <daniel.schermuk@gmail.com>
   ***************************************************
*/

#include <string.h>
#include "window.h"
#include "GLCDgui.h"
#include "GLCDPrimitives.h"
#include "GLCDLowLevel.h"
#include "GLCDColor.h"
#include "SystemFont5x7.h"
#include "GLCDFonts.h"
#include "object.h"
#include "GLCDguiEvent.h"

#ifndef NULL
#define NULL	0
#endif

void GUI_Window_Create (const char* const _name, const char* const _fatherName, uint16_t _color,
						const char* const _text,
						void (*_OnLoadHandler) (void* voidPointerParams),
						void (*_OnClickHandler) (void* voidPointerParams),
						void (*_OnDoubleClickHandler) (void* voidPointerParams) )
{
	TWindow* auxWindow;
	auxWindow = (TWindow*) GUI_Malloc ( sizeof(TWindow) );

	auxWindow->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxWindow->name, _name, 12);

	auxWindow->text = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxWindow->text, _text, 12);

	auxWindow->fatherName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxWindow->fatherName, _fatherName, 12);

	auxWindow->color = _color;

	auxWindow->OnLoadHandler = _OnLoadHandler;
	auxWindow->OnClickHandler = _OnClickHandler;
	auxWindow->OnDoubleClickHandler = _OnDoubleClickHandler;

	List_Init (&(auxWindow->objectsList));

	// Agrego la venta a la lista de ventanas
	List_AddNode (&windowsList, _name, auxWindow);
}

void GUI_Window_Draw ( const char* const windowName )
{
	TNode* pNode;
    TWindow* window;
    TList* pObjectsList;
    TNode* pAuxNode;

    uint8_t xi, xf, yi, yf;

    pNode = List_SearchNode (&windowsList, windowName);
    window = (TWindow*) pNode->data;

    // Clean the display
    GLCDPrimitives_ClearScreen ( window->color );

    // Window limiters lines
    xi = 0;
    xf = GLCDLowLevel_DISPLAY_WIDTH - 1;
    yi = 0;
    yf = GLCDLowLevel_DISPLAY_HEIGHT - 1;

    if (window->color == WHITE)
    {
    	GLCDPrimitives_DrawLine (xi, yi, xf, yi, BLACK);
    	GLCDPrimitives_DrawLine (xf, yi, xf, yf, BLACK);
    	GLCDPrimitives_DrawLine (xf, yf, xi, yf, BLACK);
    	GLCDPrimitives_DrawLine (xi, yf, xi, yi, BLACK);
        // Draw window name
        GLCDPrimitives_FillRect (xi, yi, GLCDLowLevel_DISPLAY_WIDTH, 8, BLACK);

    	GLCD_SelectFont(System5x7, WHITE);
    	GLCD_CursorFreeTo(1,1);
    	GLCD_FreePuts( window->text );
    }
    else
    {
    	GLCDPrimitives_DrawLine (xi, yi, xf, yi, WHITE);
    	GLCDPrimitives_DrawLine (xf, yi, xf, yf, WHITE);
    	GLCDPrimitives_DrawLine (xf, yf, xi, yf, WHITE);
    	GLCDPrimitives_DrawLine (xi, yf, xi, yi, WHITE);
        // Draw window name
        GLCDPrimitives_FillRect (xi, yi, GLCDLowLevel_DISPLAY_WIDTH, 8, WHITE);

    	GLCD_SelectFont(System5x7, BLACK);
    	GLCD_CursorFreeTo(1,1);
    	GLCD_FreePuts( windowName );
    }

    // Recorro la lista de objetos y los dibujo
    pObjectsList = &(window->objectsList);
    pAuxNode = pObjectsList->first;
    if ( pAuxNode != NULL )
    {
    	GUI_DrawObject ( (TObject*) pAuxNode->data );
    	while (pAuxNode->next != NULL)
    	{
    		pAuxNode = pAuxNode->next;
    		GUI_DrawObject ( (TObject*) pAuxNode->data );
    	}
    }

    // Set active window
    pActiveWindow = window;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (window->OnLoadHandler != NULL)
    {
    	//Disparar el evento
    	window->OnLoadHandler ( NULL );
    }
}

void GUI_Window_RedrowActiveWindow ()
{
	GUI_Window_Draw ( pActiveWindow->name );
}

void GUI_Window_RaiseEvent (GLCDgui_TEvent* event)
{
	TList* pObjectsList;
	TNode* pAuxNode;
	uint8_t objectDetected = 0;

	switch (event->eventType)
	{
		case GLCD_CLICK:
			// Recorro la lista de objetos y si el evento le pertenece a algún objeto lo disparo
			pObjectsList = &(pActiveWindow->objectsList);
			pAuxNode = pObjectsList->first;
			if ( pAuxNode != NULL )
			{
				objectDetected = GUI_Object_RaiseEvent ( (TObject*) pAuxNode->data, event );
				while ( objectDetected == 0 && pAuxNode->next != NULL )
				{
					pAuxNode = pAuxNode->next;
					objectDetected = GUI_Object_RaiseEvent ( (TObject*) pAuxNode->data, event );
				}
			}
		break;

		case GLCD_SCROLL_LEFTTORIGHT:
			GUI_Window_Draw (pActiveWindow->fatherName);
		break;
	}
}

void* GUI_Window_SearchObject (const char* const objectName)
{
	TNode* pAuxWindowNode = NULL;
	TNode* pAuxObjectNode = NULL;
	TWindow* pAuxWindow;
	TObject* pObject;

	pAuxWindowNode = windowsList.first;

	if (pAuxWindowNode != NULL)
	{
		pAuxWindow = (TWindow*)(pAuxWindowNode->data);
		pAuxObjectNode = List_SearchNode (&(pAuxWindow->objectsList), objectName);
		while ( pAuxObjectNode == NULL && pAuxWindowNode->next != NULL )
		{
			pAuxWindowNode = pAuxWindowNode->next;
			pAuxWindow = (TWindow*)(pAuxWindowNode->data);
			pAuxObjectNode = List_SearchNode (&(pAuxWindow->objectsList), objectName);
		}
	}

	if ( pAuxObjectNode != NULL )
	{
		pObject = pAuxObjectNode->data;
		return pObject->objectData;
	}
	else
	{
		return NULL;
	}
}
