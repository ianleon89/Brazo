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

#ifndef _TEXT_SLIDER_H_
#define _TEXT_SLIDER_H_

#include <stdint.h>
#include "button.h"
// *********************
// Structures Definition
// *********************
struct TextSlider
{
	const char* windowName;
	const char* name;
	TButton* buttonUp;
	TButton* buttonDown;
	uint8_t color;
	uint8_t fontColor;
	uint8_t percentage;
	uint16_t xPos;
	uint16_t yPos;
	struct TTextSlider* nextTextSlider;
	void (*OnPercentageChange) (void* voidPointerParams);
};
typedef struct TextSlider TTextSlider;

// *******
// Methods
// *******
void GUI_TextSlider_Create (const char* const _windowName, const char* const _name,
							uint8_t _color, uint8_t _fontColor, uint8_t _buttonColor, uint8_t _buttonFontColor,
							uint8_t _percentage,
							uint8_t _xPos, uint8_t _yPos,
							const char* const _buttonUpName,
							const char* const _buttonDownName,
							void (*_OnPercentageChange) (void* voidPointerParams) );

void GUI_TextSlider_Draw ( TTextSlider* buttonPointer );

#endif
