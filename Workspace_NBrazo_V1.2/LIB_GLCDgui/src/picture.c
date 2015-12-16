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

#include "picture.h"
#include "object.h"
#include "window.h"
#include "GLCDColor.h"
#include "GLCDPrimitives.h"

TPicture* GUI_Picture_Create ( const char* const _windowName, const char* const _name,
							  uint16_t _xPos, uint16_t _yPos,
							  uint16_t _width, uint16_t _height,
							  const uint8_t* _bitmap, uint8_t _color,
							  void (*_OnClickHandler) (void* voidPointerParams) )
{
	TPicture* pPicture;

	TNode* pNode;
	TWindow* pWindow;
	TObject* pObject;

	pPicture = (TPicture*) GUI_Malloc ( sizeof(TPicture) );

	pPicture->windowName = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (pPicture->windowName, _windowName);

	pPicture->name = (char*) GUI_Malloc ( sizeof(char) * 12 );
	strcpy (pPicture->name, _name);

	pPicture->xPos = _xPos;
	pPicture->yPos = _yPos;

	pPicture->width = _width;
	pPicture->height = _height;

	pPicture->color = _color;

	pPicture->bitmap = _bitmap;

	pPicture->OnClickHandler = _OnClickHandler;

	// Busco el nodo que tiene la información de la ventana
	pNode = List_SearchNode (&(windowsList), pPicture->windowName);

	// Obtengo la ventana
	pWindow = (TWindow*) pNode->data;

	// Creo el objeto que voy a agregar en la lista de objetos de la ventana
	pObject = (TObject*) GUI_Malloc ( sizeof(TObject) );
	pObject->objectType = PICTURE;
	pObject->objectData = (void*) pPicture;

	// Agrego el objeto a la lista de objetos de la ventana
	List_AddNode (&(pWindow->objectsList), _name, pObject);

	return pPicture;

}

void GUI_Picture_Draw ( TPicture* pPicture )
{
    uint8_t xi, xf, yi, yf;

    // Draw de bitmap
    GLCDPrimitives_DrawBitmap (pPicture->bitmap, pPicture->xPos, pPicture->yPos, pPicture->color);

	// Draw the bitmap limiters lines
    xi = pPicture->xPos;
    xf = pPicture->xPos + pPicture->width;
    yi = pPicture->yPos;
    yf = pPicture->yPos + pPicture->height;
	GLCDPrimitives_DrawLine (xi, yi, xf, yi, BLACK);
	GLCDPrimitives_DrawLine (xf, yi, xf, yf, BLACK);
	GLCDPrimitives_DrawLine (xf, yf, xi, yf, BLACK);
	GLCDPrimitives_DrawLine (xi, yf, xi, yi, BLACK);
}
