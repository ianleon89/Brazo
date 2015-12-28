/*
 * Funciones.h
 *
 *  Created on: 01/12/2015
 *      Author: ANDRES
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "freq.h"
#include "adc.h"
#include "debug.h"
//#include "small_systick.h"
#include <stdint.h>
#include "uart.h"
#include "Graficos.h"
//#include "type.h"
#include <string.h>
#include "rtc.h"
#include "iap_driver.h"
#include <math.h>
#include "cr_dsplib.h"


#include "definitions.h"

#include <stdint.h>
#include <GLCDPrimitives.h>
#include <GLCDLowLevel.h>
#include <GLCDColor.h>
#include "rtc.h"
#include "iap_driver.h"


int Teclado(void);
void IniciarPromedio(void);
void IniciarVariables(void);
void EsperaTecla(void);
uint16_t Getter_Variables_uint16(int selec);
char * Getter_Array_char(int selec);
float ** Getter_Matrix_Float(int selec);
volatile int16_t ** Getter_Matrix_Volatile(int selec);
void GLCD_Bmp (uint32_t *bmp);
char* itoa(int i, char b[]);
void MandarVector(void);
void LeeFechaHora(uint16_t p);
void MandarVector2(uint8_t sens);
void LevantaMedicion(uint32_t p,uint8_t Sensibilidad);
void CalculoRMS(uint8_t p,uint8_t Sensor,uint8_t );
void AnalisisFrec(uint8_t p,uint8_t sens);
void CalculaDecibeles(uint32_t p,uint8_t);
void LargaMedicion(uint16_t TMedicion,uint8_t Sensor,uint8_t );
void CompactaTemp(uint8_t Sensor,uint8_t Sensibilidad);
void Grabacion(uint8_t sens,uint8_t Sensibilidad);
void BorraYGraba(void);
void LeeMemoria(void);
void BorraMemoria();
void Concatena(void);
void EnviaInfo(void);
void DesculaFH(void);
void RecibeFechaHora();
void ConstruyeFH(void);
void vApplicationMallocFailedHook ( void );
void vApplicationStackOverflowHook ( xTaskHandle *pxTask, signed char *pcTaskName );
void vApplicationIdleHook ( void );
void vApplicationTickHook ( void );
static void vTest_PerformFFT(void);
void ConstruyeFH(void);
void Tiempito(int Bilardo);
void PoneFechaHora(void);
void Inicializar_pines(int selec);
void Iniciar_sistema();
void PresentaResultados(uint8_t Sensor);
void PresentaGrafico(uint8_t p,uint8_t Sensor);
void MiraUART1(uint8_t Sensor);
void wndExample_btnChange_OnClik(void* paramater);
void wndDimmer_btnBack_OnClik ( void* parameter );
void EINT3_IRQHandler (void);
void ConfigExternalInterrupt ( );
void wndDimmer_btnBack_OnClik ( void* parameter );
void Apaga_Salida_Seisg();
void Apaga_Salida_Unopcincog();

#endif /* FUNCIONES_H_ */
