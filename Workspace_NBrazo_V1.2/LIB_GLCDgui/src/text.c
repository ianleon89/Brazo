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
#include "text.h"
#include "object.h"
#include "window.h"
#include "GLCDFonts.h"
#include "SystemFont5x7.h"
#include "GLCDgui.h"

TText* GUI_Text_Create ( const char* const _windowName, const char* const _name,
						   uint16_t _xPos, uint16_t _yPos, uint8_t _color,
						   const char* const _fontName, uint8_t _fontColor,
						   const char* const _text )
{
	TText* auxText;

	TNode* pNode;
	TWindow* pWindow;
	TObject* pObject;

	auxText = (TText*) GUI_Malloc ( sizeof(TText) );

	auxText->windowName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxText->windowName, _windowName);

	auxText->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxText->name, _name);

	auxText->xPos = _xPos;
	auxText->yPos = _yPos;

	auxText->color = _color;

	auxText->fontName = _fontName;
	auxText->fontColor = _fontColor;

	auxText->text = (char*) GUI_Malloc ( sizeof(char) * strlen(_text) );
	strncpy (auxText->text, _text, strlen(_text));

	// Busco el nodo que tiene la información de la ventana
	pNode = List_SearchNode (&(windowsList), auxText->windowName);

	// Obtengo la ventana
	pWindow = (TWindow*) pNode->data;

	// Creo el objeto que voy a agregar en la lista de objetos de la ventana
	pObject = (TObject*) GUI_Malloc ( sizeof(TObject) );
	pObject->objectType = TEXT;
	pObject->objectData = (void*) auxText;

	// Agrego el objeto a la lista de objetos de la ventana
	List_AddNode (&(pWindow->objectsList), _name, pObject);

	return auxText;
}

void GUI_Text_Draw ( TText* pText )
{
	// Draw button name
	GLCD_SelectFont(System5x7, pText->fontColor);
	GLCD_CursorFreeTo(pText->xPos, pText->yPos);
	GLCD_FreePuts( pText->text );
}

void GUI_Text_Draw_In_Dimmer ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "Dimmer");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
/*    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawVertLine(52 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(21 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(94 ,10, 40, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,23, 127, BLACK);
    GLCDPrimitives_DrawHoriLine(52 ,50, 75, BLACK);*/
    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}

void GUI_Text_Draw_In_Menu ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "Menu");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
/*    GLCDPrimitives_DrawVertLine(52 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(21 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(94 ,10, 40, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,23, 127, BLACK);
    GLCDPrimitives_DrawHoriLine(52 ,50, 75, BLACK);	*/
    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}

void GUI_Text_Draw_In_Credits ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "Credits");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,42, 127, BLACK);

    /*    GLCDPrimitives_DrawVertLine(52 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(21 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(94 ,10, 40, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,23, 127, BLACK);
    GLCDPrimitives_DrawHoriLine(52 ,50, 75, BLACK);	*/
    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}

void GUI_Text_Draw_In_Credit4 ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "Credits");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,40, 127, BLACK);

    /*    GLCDPrimitives_DrawVertLine(52 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(21 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(94 ,10, 40, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,23, 127, BLACK);
    GLCDPrimitives_DrawHoriLine(52 ,50, 75, BLACK);	*/
    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}

void GUI_Text_Draw_In_Credits5 ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "Credits");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,40, 127, BLACK);

    /*    GLCDPrimitives_DrawVertLine(52 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(21 ,10, 53, BLACK);
    GLCDPrimitives_DrawVertLine(94 ,10, 40, BLACK);
    GLCDPrimitives_DrawHoriLine(0 ,23, 127, BLACK);
    GLCDPrimitives_DrawHoriLine(52 ,50, 75, BLACK);	*/
    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }
}

void GUI_Text_Draw_In_GrafRes ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;


    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "GrafRes");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    for (r=1;r<5;r++){
    	GLCDPrimitives_DrawVertLine(_xPos+r ,_yPos,53-_yPos, BLACK);
    }
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawVertLine(124 ,13, 40, BLACK);	// Margen derecho rect
    GLCDPrimitives_DrawVertLine(22 ,13, 40, BLACK);		// Margen izquierdo rect
    GLCDPrimitives_DrawHoriLine(22 ,53, 102, BLACK);	// Bottom grafico
    GLCDPrimitives_DrawHoriLine(22 ,13, 102, BLACK);	// Top grafico
 //   GLCDPrimitives_DrawHoriLine(18 ,13, 2, BLACK);
    GLCDPrimitives_DrawHoriLine(20 ,23, 2, BLACK);
    GLCDPrimitives_DrawHoriLine(20 ,33, 2, BLACK);
    GLCDPrimitives_DrawHoriLine(20 ,43, 2, BLACK);
//    GLCDPrimitives_DrawHoriLine(18 ,53, 2, BLACK);
    GLCDPrimitives_DrawVertLine(28 ,53, 2, BLACK);	// Escala dB
    GLCDPrimitives_DrawVertLine(58 ,53, 2, BLACK);	// Escala dB
    GLCDPrimitives_DrawVertLine(78 ,53, 2, BLACK);	// Escala dB
    GLCDPrimitives_DrawVertLine(98 ,53, 2, BLACK);	// Escala dB

    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}
/*
void GUI_Text_Draw_In_GrafRes_Copia ( const char* const _text, uint8_t _color,uint8_t _fontColor,
           uint16_t _xPos, uint16_t _yPos )
{


    TNode* pNode;
    TWindow* pWindow;

    /// codigo agregado... Borra con un rectangulo antes de reimprimir/////////
    int r;

    for (r=0;r<9;r++){
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos, 6*(strlen(_text))+1, _color);
        GLCDPrimitives_DrawHoriLine(_xPos ,_yPos+r, 6*(strlen(_text)), _color);
    }
    ///////////////////////////////////////////////////////////////////////////

    // Busco el nodo que tiene la información de la ventana
    pNode = List_SearchNode (&(windowsList), "GrafRes");

    // Obtengo la ventana
    pWindow = (TWindow*) pNode->data;


    GLCD_SelectFont(System5x7, _fontColor);
    GLCD_CursorFreeTo(_xPos+1,_yPos+1);
    GLCD_FreePuts( _text);
    GLCDPrimitives_DrawVertLine(0 ,0, 63, BLACK);
    GLCDPrimitives_DrawVertLine(20 ,15, 35, BLACK);
    GLCDPrimitives_DrawHoriLine(20 ,50, 127, BLACK);

    // Set active window
    pActiveWindow = pWindow;

    // Send data to the GLCD
    GLCDLowLevel_SwapBuffer ();

    if (pWindow->OnLoadHandler != NULL)
    {
        //Disparar el evento
        pWindow->OnLoadHandler ( NULL );
    }

}
*/
