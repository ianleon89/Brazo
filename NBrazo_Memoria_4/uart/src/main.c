/***********************************************************************
 * $Id::                                                               $
 *
 * Project:	uart: Simple UART echo for LPCXpresso 1700
 * File:	uarttest.c
 * Description:
 * 			LPCXpresso Baseboard uses pins mapped to UART3 for
 * 			its USB-to-UART bridge. This application simply echos
 * 			all characters received.
 *
 ***********************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **********************************************************************/

/*****************************************************************************
 *   History
 *   2010.07.01  ver 1.01    Added support for UART3, tested on LPCXpresso 1700
 *   2009.05.27  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#include "LPC17xx.h"
#include "type.h"
#include "uart.h"
#include <string.h>
#include <stdio.h>

extern volatile uint32_t UART3Count;
extern volatile uint8_t UART3Buffer[BUFSIZE];

char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}


/*****************************************************************************
**   Main Function  main()
This program has been test on LPCXpresso 1700.
*****************************************************************************/
int main (void)
{
	const char* welcomeMsg = "SQue programa5:W";
	const char* saltolinea = "\n";
	const char* carreturn = "\r";
	const char* coma = ",";
	char mens3[20];
	uint16_t m;
	uint16_t vector[10]={1,2,3,4,5,6,7,8,9,10};
	UARTInit(3, 9600);	/* baud rate setting */
	UARTSend(3, (uint8_t *)welcomeMsg , strlen(welcomeMsg) );

	UARTSend(3, (uint8_t *)saltolinea , strlen(saltolinea) );
	UARTSend(3, (uint8_t *)carreturn , strlen(carreturn) );
	UART3Count = 0;
/*	strcpy(coso,cosoT);
	comparancia=strcmp(coso,buffito);*/
	for(m=0;m<5;m++){
	    itoa(vector[m],mens3);
		UARTSend(3, (uint8_t *)mens3 , strlen(mens3) );
		UARTSend(3, (uint8_t *)coma , strlen(coma) );
	}
	UARTSend(3, (uint8_t *)saltolinea , strlen(saltolinea) );
	UARTSend(3, (uint8_t *)carreturn , strlen(carreturn) );
	for(m=5;m<10;m++){
	    itoa(vector[m],mens3);
		UARTSend(3, (uint8_t *)mens3 , strlen(mens3) );
		UARTSend(3, (uint8_t *)coma , strlen(coma) );
	}
//    mens1=mens3;
	/* Loop forever */
	while (1)
	{
		if ( UART3Count != 0)
		{
//			letrita=(uint8_t *)UART3Buffer;
//			coso=UART3Buffer;
			LPC_UART3->IER = IER_THRE | IER_RLS;				/* Disable RBR */
/*			if(m==0){
				UARTSend(3, (uint8_t *)mensaje1, strlen(mensaje1) );
				m++;
			}
			else if(m==1){
				UARTSend(3, (uint8_t *)mensaje2, strlen(mensaje2) );
				m++;
			}
			else{
				UARTSend(3, (uint8_t *)mensaje3, strlen(mensaje3) );
			}*/
			UARTSend(3, (uint8_t *)UART3Buffer, UART3Count );
			UART3Count = 0;
			LPC_UART3->IER = IER_THRE | IER_RLS | IER_RBR;		/* Re-enable RBR */
		}
	}
}

/*****************************************************************************
**                            End Of File
*****************************************************************************/
