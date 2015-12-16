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

#ifndef _TOUCH_PANEL_H_
#define _TOUCH_PANEL_H_

#include <stdint.h>

#define XMAS_PORT		0
#define XMAS_PIN		25
#define XMENOS_PORT		0
#define XMENOS_PIN		26
#define YMAS_PORT		0
#define YMAS_PIN		23
#define YMENOS_PORT		0
#define YMENOS_PIN		24

enum TouchPanel_EnumEvents
{
	CLICK = 0,
	DOUBLECLICK = 1,
	SCROLL_LEFTTORIGHT = 2,
	SCROLL_RIGHTTOLEFT = 3,
	DRAG = 4,
	DROP = 5,
	NOEVENT = 6
};
typedef enum TouchPanel_EnumEvents TouchPanel_EEvents;

struct TouchPanel_TypeEvent
{
	uint16_t xCoordinate;
	uint16_t yCoordinate;
	TouchPanel_EEvents eventType;
};
typedef struct TouchPanel_TypeEvent TouchPanel_TEvent;

enum TouchPanel_EnumState
{
	TOUCHED = 0,
	NOTOUCHED = 1
};
typedef enum TouchPanel_EnumState TouchPanel_EState;

struct TouchPanel_TypePoint
{
	uint16_t xCoordinate;
	uint16_t yCoordinate;
	TouchPanel_EState state;
};
typedef struct TouchPanel_TypePoint TouchPanel_TPoint;

volatile TouchPanel_TPoint touchPanel_eventPoints[10];
volatile uint8_t touchPanel_pointsCounter;

void StartTouchPanel ();

// Pins configuration
// Configure pins for detect activity on the touch panel
void PinsConfig_DetectActivity ();
// Configure pins for read y coordinate on the touch panel
void PinsConfig_DetectYCoordinate ();
// configure pins for read x coordinate on the touch panel
void PinsConfig_DetectXCoordinate ();

// Process touch panel
uint8_t TouchPanel_Read ( TouchPanel_TEvent* event );

#endif // _TOUCH_PANEL_H_
