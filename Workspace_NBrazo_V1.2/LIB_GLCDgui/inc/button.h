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

#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <stdint.h>

// *********************
// Structures Definition
// *********************
struct Button
{
	const char* windowName;
	const char* name;
	uint16_t height;
	uint16_t width;
	uint16_t xPos;
	uint16_t yPos;
	uint8_t color;
	const char* fontName;
	uint8_t fontColor;
	char* text;
	void (*OnClickHandler) (void* voidPointerParams);
	void (*OnDoubleClickHandler) (void* voidPointerParams);
	void (*OnDragHandler) (void* voidPointerParams);
	void (*OnDropHandler) (void* voidPointerParams);
};
typedef struct Button TButton;

// *******
// Methods
// *******
TButton* GUI_Button_Create (const char* const _windowName, const char* const _name, uint16_t _height, uint16_t _width, uint16_t _xPos,
						uint16_t _yPos, uint8_t _color, const char* const _fontName, uint8_t _fontColor,
						const char* const _text,
						void (*OnClickHandler) (void* voidPointerParams),
						void (*OnDoubleClickHandler) (void* voidPointerParams),
						void (*OnDragHandler) (void* voidPointerParams),
						void (*OnDropHandler) (void* voidPointerParams) );

TButton* GUI_Button_CreateNotInWindowList (const char* const _windowName, const char* const _name,
										   uint16_t _height, uint16_t _width, uint16_t _xPos, uint16_t _yPos,
										   uint8_t _color, const char* const _fontName, uint8_t _fontColor,
										   const char* const _text,
										   void (*_OnClickHandler) (void* voidPointerParams),
										   void (*_OnDoubleClickHandler) (void* voidPointerParams),
										   void (*_OnDragHandler) (void* voidPointerParams),
										   void (*_OnDropHandler) (void* voidPointerParams) );

void GUI_Button_Draw ( TButton* buttonPointer );

#endif
