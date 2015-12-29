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

#ifndef PICTURE_H_
#define PICTURE_H_

#include <stdint.h>

// *********************
// Structures Definition
// *********************
struct typePicture
{
	const char* windowName;
	const char* name;
	const uint8_t* bitmap;
	uint16_t xPos;
	uint16_t yPos;
	uint16_t width;
	uint16_t height;
	uint8_t color;
	void (*OnClickHandler) (void* voidPointerParams);
};
typedef struct typePicture TPicture;

// *******
// Methods
// *******
TPicture* GUI_Picture_Create ( const char* const _windowName, const char* const _name,
							  uint16_t _xPos, uint16_t _yPos,
							  uint16_t _width, uint16_t _height,
							  const uint8_t* _bitmap, uint8_t _color,
							  void (*OnClickHandler) (void* voidPointerParams) );

void GUI_Picture_Draw ( TPicture* pPicture );

#endif /* PICTURE_H_ */
