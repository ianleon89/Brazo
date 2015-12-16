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

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <stdint.h>
#include "button.h"
#include "textSlider.h"
#include "list.h"
#include "GLCDguiEvent.h"

struct Window
{
	const char* name;
	const char* fatherName;
	const char* text;
	uint8_t isActive;
	uint16_t color;
	TList objectsList;
	void (*OnLoadHandler) (void* voidPointerParams);
	void (*OnClickHandler) (void* voidPointerParams);
	void (*OnDoubleClickHandler) (void* voidPointerParams);
};
typedef struct Window TWindow;

TList windowsList;
TWindow* pActiveWindow;

// ****************
// Public functions
// ****************
void GUI_Window_Create ( const char* const name, const char* const fatherName, uint16_t color,
						 const char* const _text,
						 void (*OnLoadHandler) (void* voidPointerParams),
						 void (*OnClickHandler) (void* voidPointerParams),
						 void (*OnDoubleClickHandler) (void* voidPointerParams) );

void GUI_Window_Draw ( const char* const windowName );

void GUI_Window_RedrowActiveWindow ();

void GUI_Window_RaiseEvent (GLCDgui_TEvent* event);

void* GUI_Window_SearchObject (const char* const objectName);

#endif
