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

#include "object.h"
#include "button.h"
#include "textSlider.h"
#include "text.h"
#include "picture.h"
#include "GLCDguiEvent.h"

#ifndef NULL
#define NULL 0
#endif

void GUI_DrawObject ( TObject* object )
{
	EObjectType type;
	type = object->objectType;

	switch (object->objectType)
	{
		case BUTTON:
			GUI_Button_Draw ( (TButton*) object->objectData );
		break;

		case TEXTSLIDER:
			GUI_TextSlider_Draw ( (TTextSlider*) object->objectData );
		break;

		case TEXT:
			GUI_Text_Draw ( (TText*) object->objectData );
		break;

		case PICTURE:
			GUI_Picture_Draw ( (TPicture*) object->objectData );
		break;
	}
}

uint8_t GUI_Object_RaiseEvent ( TObject* object, GLCDgui_TEvent* event )
{
	EObjectType type;
	TTextSlider* pTextSlider;
	TButton* pButton;
	TPicture* pPicture;
	uint16_t _xCoor;
	uint16_t _yCoor;

	_xCoor = event->xCoordinate;
	_yCoor = event->yCoordinate;

	type = object->objectType;

	switch (object->objectType)
	{
		case BUTTON:
			pButton = (TButton*) object->objectData;
			if ( (_xCoor > pButton->xPos) && (_xCoor < pButton->xPos + pButton->width) )
			{
				if ( (_yCoor > pButton->yPos) && (_yCoor < pButton->yPos + pButton->height) )
				{
					if (pButton->OnClickHandler != NULL)
					{
						pButton->OnClickHandler ( pButton );
						return 1;
					}
					return 0;
				}
			}
		break;

		case TEXTSLIDER:
			pTextSlider = (TTextSlider*) object->objectData;
			pButton = pTextSlider->buttonDown;
			if ( (_xCoor > pButton->xPos) && (_xCoor < pButton->xPos + pButton->width) )
			{
				if ( (_yCoor > pButton->yPos) && (_yCoor < pButton->yPos + pButton->height) )
				{
					pButton->OnClickHandler ( pTextSlider );
					return 1;
				}
			}
			pButton = pTextSlider->buttonUp;
			if ( (_xCoor > pButton->xPos) && (_xCoor < pButton->xPos + pButton->width) )
			{
				if ( (_yCoor > pButton->yPos) && (_yCoor < pButton->yPos + pButton->height) )
				{
					pButton->OnClickHandler ( pTextSlider );
					return 1;
				}
			}
		break;

		case TEXT:
			return 0; //TEXT don't have events
		break;

		case PICTURE:
			pPicture = (TPicture*) object->objectData;
			if ( (_xCoor > pPicture->xPos) && (_xCoor < pPicture->xPos + pPicture->width) )
			{
				if ( (_yCoor > pPicture->yPos) && (_yCoor < pPicture->yPos + pPicture->height) )
				{
					if (pPicture->OnClickHandler != NULL)
					{
						pPicture->OnClickHandler ( pPicture );
						return 1;
					}
					return 0;
				}
			}
		break;
	}
	return 0;
}
