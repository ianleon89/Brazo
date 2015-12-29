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
#include <stdio.h>

#include "window.h"
#include "textSlider.h"
#include "button.h"
#include "GLCDgui.h"
#include "GLCDPrimitives.h"
#include "GLCDLowLevel.h"
#include "GLCDColor.h"
#include "SystemFont5x7.h"
#include "GLCDFonts.h"
#include "list.h"
#include "object.h"

#ifndef NULL
#define NULL	0
#endif

void GUI_TextSlider_ButtonDown_OnClick ( void* parameter );
void GUI_TextSlider_ButtonUp_OnClick ( void* parameter );

void GUI_TextSlider_Create (const char* const _windowName, const char* const _name,
							uint8_t _color, uint8_t _fontColor, uint8_t _buttonColor, uint8_t _buttonFontColor,
							uint8_t _percentage,
							uint8_t _xPos, uint8_t _yPos,
							const char* const _buttonUpName,
							const char* const _buttonDownName,
							void (*_OnPercentageChange) (void* voidPointerParams) )
{
	TTextSlider* auxPTextSlider;

	TNode* pNode;
	TWindow* pWindow;
	TObject* pObject;

	uint8_t charWidth;
	uint8_t buttonUpXPos;

	auxPTextSlider = (TTextSlider*) GUI_Malloc ( sizeof(TTextSlider) );

	auxPTextSlider->windowName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxPTextSlider->windowName, _windowName);

	auxPTextSlider->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (auxPTextSlider->name, _name);

	auxPTextSlider->color = _color;
	auxPTextSlider->fontColor = _fontColor;

	auxPTextSlider->percentage = _percentage;

	auxPTextSlider->nextTextSlider = NULL;

	auxPTextSlider->xPos = _xPos;
	auxPTextSlider->yPos = _yPos;

	auxPTextSlider->OnPercentageChange = _OnPercentageChange;

	auxPTextSlider->buttonDown = GUI_Button_CreateNotInWindowList ( auxPTextSlider->windowName, _buttonDownName,
																	12, 12, auxPTextSlider->xPos, auxPTextSlider->yPos,
																	_buttonColor,"", _buttonFontColor,
																	"-",
																	GUI_TextSlider_ButtonDown_OnClick,
																	NULL,
																	NULL,
																	NULL );

	charWidth = System5x7[FONT_FIXED_WIDTH];
	buttonUpXPos = auxPTextSlider->xPos + 12 + (8 * charWidth);

	auxPTextSlider->buttonUp = GUI_Button_CreateNotInWindowList ( auxPTextSlider->windowName, _buttonUpName,
																  12, 12, buttonUpXPos, auxPTextSlider->yPos,
																  _buttonColor,"", _buttonFontColor,
																  "+",
																  GUI_TextSlider_ButtonUp_OnClick,
																  NULL,
																  NULL,
																  NULL );

	// Busco el nodo que tiene la información de la ventana
	pNode = List_SearchNode (&(windowsList), auxPTextSlider->windowName);

	// Obtengo la ventana
	pWindow = (TWindow*) pNode->data;

	// Creo el objeto que voy a agregar en la lista de objetos de la ventana
	pObject = (TObject*) GUI_Malloc ( sizeof(TObject) );
	pObject->objectType = TEXTSLIDER;
	pObject->objectData = (void*) auxPTextSlider;

	// Agrego el objeto a la lista de objetos de la ventana
	List_AddNode (&(pWindow->objectsList), _name, pObject);
}

void GUI_TextSlider_Draw ( TTextSlider* textSliderPointer )
{
	uint8_t fontXPos;
	uint8_t fontYPos;
	uint8_t charWidth;
	uint8_t charHeight;
	uint8_t cantChar;
	char textPercentage[5];

	// Font to use
	charWidth = System5x7[FONT_FIXED_WIDTH];
	charHeight = System5x7[FONT_HEIGHT];

	// Percentage to write
	sprintf (textPercentage, "%d%%", textSliderPointer->percentage);
	cantChar = strlen (textPercentage);

	// Text position
	fontXPos = textSliderPointer->xPos + 12 + ( charWidth*8 - cantChar*charWidth ) / 2;
	fontYPos = textSliderPointer->yPos + (12 - charHeight) / 2;

	// Draw background
	// COMPLETE. Use textSliderPointer->color;

	// Draw percentage
	GLCD_SelectFont(System5x7, textSliderPointer->fontColor);
    GLCD_CursorFreeTo(fontXPos, fontYPos);
    GLCD_FreePuts( textPercentage );

    // Draw buttons
    GUI_Button_Draw ( textSliderPointer->buttonDown );
    GUI_Button_Draw ( textSliderPointer->buttonUp );
}


void GUI_TextSlider_ButtonDown_OnClick ( void* parameter )
{
	TTextSlider* pTextSlider = (TTextSlider*) parameter;
	pTextSlider->percentage = pTextSlider->percentage - 5;
	if (pTextSlider->OnPercentageChange != NULL)
	{
		pTextSlider->OnPercentageChange ( parameter );
	}
}


void GUI_TextSlider_ButtonUp_OnClick ( void* parameter )
{
	TTextSlider* pTextSlider = (TTextSlider*) parameter;
	pTextSlider->percentage = pTextSlider->percentage + 5;
	if (pTextSlider->OnPercentageChange != NULL)
	{
		pTextSlider->OnPercentageChange ( parameter );
	}
}
