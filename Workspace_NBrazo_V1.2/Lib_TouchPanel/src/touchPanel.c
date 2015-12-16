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

// Includes
#include "touchPanel.h"
// lpc17xx includes
#include "adc.h"
#include "extern.h"
#include "lpc17xx_adc.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"

void StartTouchPanel ()
{
	// Pins Config
	PinsConfig_DetectActivity();
	touchPanel_pointsCounter = 0;
}

void PinsConfig_DetectActivity()
{
	PINSEL_CFG_Type pinConfig;

	// Check activity on the screen detect
	// X+ = GND; X- = HiZ; Y+ = HiZ; Y- = Pull up in
	// Need X+, X-, Y+ and Y- as GPIO
	// X+

	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = XMAS_PORT;
	pinConfig.Pinnum = XMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// X-
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = XMENOS_PORT;
	pinConfig.Pinnum = XMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// Y+
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = YMAS_PORT;
	pinConfig.Pinnum = YMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// Y-
	pinConfig.Funcnum = PINSEL_FUNC_0;
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinConfig.Pinmode =  PINSEL_PINMODE_PULLUP;
	pinConfig.Portnum = YMENOS_PORT;
	pinConfig.Pinnum = YMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);

	// X+ as output for drive X+ = GND
	GPIO_SetDir (XMAS_PORT, (1<<XMAS_PIN), 1);
	// X- and Y+ as input to get High Z
	GPIO_SetDir(XMENOS_PORT, (1<<XMENOS_PIN), 0);
	GPIO_SetDir(YMAS_PORT, (1<<YMAS_PIN), 0);
	// Y- as input
	GPIO_SetDir(YMENOS_PORT, (1<<YMENOS_PIN), 0);

	// X+ = GND
	GPIO_ClearValue (XMAS_PORT, (1<<XMAS_PIN));


}

void PinsConfig_DetectYCoordinate()
{
	PINSEL_CFG_Type pinConfig;

	// Get Y-Coordinate
	// X+ = GND; X- = VCC; Y+ = HiZ; Y- = ADC (experimental)
	// Need X+, X- and Y+ as GPIO (General P Input Output). Need Y- connected as an ADC input
	// X+
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = XMAS_PORT;
	pinConfig.Pinnum = XMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// X-
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = XMENOS_PORT;
	pinConfig.Pinnum = XMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// Y+
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = YMAS_PORT;
	pinConfig.Pinnum = YMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);

	// X+ y X- as output for drive X+ = GND and X- = VCC
	GPIO_SetDir (XMAS_PORT, (1<<XMAS_PIN), 1);
	GPIO_SetDir (XMENOS_PORT, (1<<XMENOS_PIN), 1);
	// Y+ as input to get High Z
	GPIO_SetDir(YMAS_PORT, (1<<YMAS_PIN), 0);
	// X+ = GND and X- = VCC
	GPIO_ClearValue (XMAS_PORT, (1<<XMAS_PIN));
	GPIO_SetValue (XMENOS_PORT, (1<<XMENOS_PIN));

	// Y-
	pinConfig.Funcnum = PINSEL_FUNC_1;
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE;
	pinConfig.Portnum = YMENOS_PORT;
	pinConfig.Pinnum = YMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);
}

void PinsConfig_DetectXCoordinate()
{
	PINSEL_CFG_Type pinConfig;

	// Get X-Coordinate
	// X+ = HiZ; X- = ADC; Y+ = GND; Y- = VCC (experimental)
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = XMAS_PORT;
	pinConfig.Pinnum = XMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// Y+
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = YMAS_PORT;
	pinConfig.Pinnum = YMAS_PIN;
	PINSEL_ConfigPin (&pinConfig);
	// Y-
	pinConfig.Funcnum = PINSEL_FUNC_0; // Choose the default function (GIOP)
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL; // Not in open drain mode (open drain generally used for output)
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE; // Generally apply when the pin is an input
	pinConfig.Portnum = YMENOS_PORT;
	pinConfig.Pinnum = YMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);

	// Y+ and Y- as output for drive Y+ = GND and Y- = VCC
	GPIO_SetDir (YMAS_PORT, (1<<YMAS_PIN), 1);
	GPIO_SetDir (YMENOS_PORT, (1<<YMENOS_PIN), 1);
	// X+ as input to get High Z
	GPIO_SetDir(XMAS_PORT, (1<<XMAS_PIN), 0);
	// Y+ = GND and Y- = VCC
	GPIO_ClearValue (YMAS_PORT, (1<<YMAS_PIN));
	GPIO_SetValue (YMENOS_PORT, (1<<YMENOS_PIN));

	// X-
	pinConfig.Funcnum = PINSEL_FUNC_1;
	pinConfig.OpenDrain = PINSEL_PINMODE_NORMAL;
	pinConfig.Pinmode =  PINSEL_PINMODE_TRISTATE;
	pinConfig.Portnum = XMENOS_PORT;
	pinConfig.Pinnum = XMENOS_PIN;
	PINSEL_ConfigPin (&pinConfig);

}

uint8_t TouchPanel_Read ( TouchPanel_TEvent* event )
{
	uint8_t ADValue;

	ADValue = FIO_ByteReadValue (0, 3);
	ADValue = ADValue & 0x01;

	if (ADValue == 0)
	{
		// Touch panel is activate
		touchPanel_eventPoints[touchPanel_pointsCounter].state = TOUCHED;
		// Get x coordinate
		PinsConfig_DetectXCoordinate();
		touchPanel_eventPoints[touchPanel_pointsCounter].xCoordinate = (ADC0Read(3) - 530) * 127 / ((3500 - 530));
		// Get y coordinate
		PinsConfig_DetectYCoordinate();
		touchPanel_eventPoints[touchPanel_pointsCounter].yCoordinate = (ADC0Read(1) - 900) * 63 / ((3100-900));
	}
	else
	{
		// Touch panel is not activate
		touchPanel_eventPoints[touchPanel_pointsCounter].state = NOTOUCHED;
	}

	if (touchPanel_pointsCounter == 1)
	{
		touchPanel_eventPoints[0].state;
		touchPanel_eventPoints[0].xCoordinate;
		touchPanel_eventPoints[0].yCoordinate;
		touchPanel_eventPoints[1].state;
		touchPanel_eventPoints[1].xCoordinate;
		touchPanel_eventPoints[1].yCoordinate;

		if ( (touchPanel_eventPoints[0].state == TOUCHED && touchPanel_eventPoints[1].state == NOTOUCHED)
			 ||
			 (touchPanel_eventPoints[0].state == TOUCHED && touchPanel_eventPoints[1].state == TOUCHED) )
		{
			event->eventType = CLICK;
			event->xCoordinate = touchPanel_eventPoints[0].xCoordinate;
			event->yCoordinate = touchPanel_eventPoints[0].yCoordinate;
			touchPanel_pointsCounter = 0;
			PinsConfig_DetectActivity ();
			return 1;
		}
	}

	if (touchPanel_pointsCounter > 2)
	{
		touchPanel_eventPoints[0].state;
		touchPanel_eventPoints[0].xCoordinate;
		touchPanel_eventPoints[0].yCoordinate;
		touchPanel_eventPoints[1].state;
		touchPanel_eventPoints[1].xCoordinate;
		touchPanel_eventPoints[1].yCoordinate;
		event->eventType = NOEVENT;
		touchPanel_pointsCounter = 0;
		PinsConfig_DetectActivity ();
		return 1;
	}

	PinsConfig_DetectActivity ();

	touchPanel_pointsCounter++;

	return 0;
}
