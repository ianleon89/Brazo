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

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdint.h>
#include <GLCDguiEvent.h>

// ****************
// Enum Definitions
// ****************
enum EnumObjetcType
{
	BUTTON,
	TEXTSLIDER,
	TEXT,
	PICTURE
};
typedef enum EnumObjetcType EObjectType;

// *********************
// Structures Definition
// *********************
struct TypeObject
{
	EObjectType objectType;
	void* objectData;
};
typedef struct TypeObject TObject;

void GUI_DrawObject ( TObject* object );

uint8_t GUI_Object_RaiseEvent ( TObject* object, GLCDgui_TEvent* event);

#endif /* OBJECT_H_ */
