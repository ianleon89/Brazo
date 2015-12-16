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

// ********************************
// Microcontroller Interface (Head)
// ********************************

#ifndef _MICROINTERFACE_H_
#define _MICROINTERFACE_H_

#include <stdint.h>

// ********************************
// LPC pins assigned to LCD WG12864
// ********************************
#define LCD_CSEL_PORT		0
#define CSEL1				15		// CS1 Bit (swap pin assignments with CSEL2 if left/right image is reversed)
#define CSEL2				16		// CS2 Bit

#define LCD_CMD_PORT		0
#define D_I					17		// D/I Bit
#define R_W					8		// R/W Bit
#define EN					9		// EN Bit

#define LCD_DATA_PORT		0
#define DB1					21		// DB1 is not in the same LCD_DATA_PORT nibble

// ******************************
// LPC digital I/O pins Functions
// ******************************
inline void MicroInterface_Init ();
inline void MicroInterface_Bit_WriteLow (uint8_t port, uint8_t pin);
inline void MicroInterface_Bit_WriteHigh (uint8_t port, uint8_t pin);
inline void MicroInterface_Byte_WriteData (uint8_t buf);

// ******
// Macros
// ******
#define EN_DELAY() for (_delayCounter=0; _delayCounter<10; _delayCounter++);

#endif
