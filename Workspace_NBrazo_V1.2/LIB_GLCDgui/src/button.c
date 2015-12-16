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
#include "button.h"
#include "GLCDgui.h"
#include "GLCDPrimitives.h"
#include "GLCDLowLevel.h"
#include "GLCDColor.h"
#include "SystemFont5x7.h"
#include "GLCDFonts.h"
#include "object.h"

#define FALSE 	0
#define TRUE 	1

#ifndef NULL
#define NULL	0
#endif

TButton* GUI_Button_Create (const char* const _windowName, const char* const _name, uint16_t _height, uint16_t _width, uint16_t _xPos,
						uint16_t _yPos, uint8_t _color, const char* const _fontName, uint8_t _fontColor,
						const char* const _text,
						void (*_OnClickHandler) (void* voidPointerParams),
						void (*_OnDoubleClickHandler) (void* voidPointerParams),
						void (*_OnDragHandler) (void* voidPointerParams),
						void (*_OnDropHandler) (void* voidPointerParams) )
{
	TButton* auxButton;

	TNode* pNode;
	TWindow* pWindow;
	TObject* pObject;

	auxButton = (TButton*) GUI_Malloc ( sizeof(TButton) );

	auxButton->windowName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxButton->windowName, _windowName);

	auxButton->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxButton->name, _name);

	auxButton->height = _height;
	auxButton->width = _width;
	auxButton->xPos = _xPos;
	auxButton->yPos = _yPos;
	auxButton->color = _color;
	auxButton->fontName = _fontName;
	auxButton->fontColor = _fontColor;

	auxButton->text = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxButton->text, _text, 12);

	auxButton->OnClickHandler = _OnClickHandler;
	auxButton->OnDoubleClickHandler = _OnDoubleClickHandler;
	auxButton->OnDragHandler = _OnDragHandler;
	auxButton->OnDropHandler = _OnDropHandler;

	// Busco el nodo que tiene la información de la ventana
	pNode = List_SearchNode (&(windowsList), auxButton->windowName);

	// Obtengo la ventana
	pWindow = (TWindow*) pNode->data;

	// Creo el objeto que voy a agregar en la lista de objetos de la ventana
	pObject = (TObject*) GUI_Malloc ( sizeof(TObject) );
	pObject->objectType = BUTTON;
	pObject->objectData = (void*) auxButton;

	// Agrego el objeto a la lista de objetos de la ventana
	List_AddNode (&(pWindow->objectsList), _name, pObject);

	return auxButton;
}

TButton* GUI_Button_CreateNotInWindowList (const char* const _windowName, const char* const _name,
										   uint16_t _height, uint16_t _width, uint16_t _xPos, uint16_t _yPos,
										   uint8_t _color, const char* const _fontName, uint8_t _fontColor,
										   const char* const _text,
										   void (*_OnClickHandler) (void* voidPointerParams),
										   void (*_OnDoubleClickHandler) (void* voidPointerParams),
										   void (*_OnDragHandler) (void* voidPointerParams),
										   void (*_OnDropHandler) (void* voidPointerParams) )
{
	TButton* auxButton;

	auxButton = (TButton*) GUI_Malloc ( sizeof(TButton) );

	auxButton->windowName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxButton->windowName, _windowName);

	auxButton->height = _height;
	auxButton->width = _width;
	auxButton->xPos = _xPos;
	auxButton->yPos = _yPos;
	auxButton->color = _color;
	auxButton->fontName = _fontName;
	auxButton->fontColor = _fontColor;

	auxButton->text = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strncpy (auxButton->text, _text, 12);

	auxButton->OnClickHandler = _OnClickHandler;
	auxButton->OnDoubleClickHandler = _OnDoubleClickHandler;
	auxButton->OnDragHandler = _OnDragHandler;
	auxButton->OnDropHandler = _OnDropHandler;

	return auxButton;
}


void GUI_Button_Draw ( TButton* pButton )
{
	uint8_t fontXPos;
	uint8_t fontYPos;
	size_t cantChar;
	uint8_t charWidth;
	uint8_t charHeight;

	GLCDPrimitives_FillRect (pButton->xPos, pButton->yPos, pButton->width, pButton->height, pButton->color);

	// Button name position
	cantChar = strlen(pButton->text);
	charWidth = System5x7[FONT_FIXED_WIDTH];
	charHeight = System5x7[FONT_HEIGHT];
	fontXPos = pButton->xPos + (pButton->width - (charWidth+1) * cantChar) / 2;
	fontYPos = pButton->yPos + (pButton->height - charHeight) / 2;

	// Draw button name
	GLCD_SelectFont(System5x7, pButton->fontColor);
    GLCD_CursorFreeTo(fontXPos, fontYPos);
    GLCD_FreePuts( pButton->text );
}
