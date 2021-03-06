/*
 * Mef_Menu.h
 *
 *  Created on: 26/11/2015
 *      Author: ANDRES
 */

#ifndef MEF_MENU_H_
#define MEF_MENU_H_


#include "Funciones.h"

#define TICKRATE_HZ (1000) /*1 tick por segundo*/
#define Tiempo_Espera (uint32_t)80000000
#define  Max_Mediciones 29
typedef enum {ESTADO_INICIAL,CANCEL,ABAJO,TRES,ARRIBA,CINCO,SEIS,SIETE,ENTER} Teclas_Menu;
typedef enum{PRINCIPAL,MEDICION,REMOTO,VER_ANTERIORES,BORRAR_MEMORIA,SALIR}Menus;



void Incializar_variables_locales();
void ActualizarMef();
void Mef_Init();
void Rutina_Medicion();
void Medir(uint8_t  Sens);
void Rutina_Presenta_Anterior();
void Presenta_Anterior(uint8_t NumMedicion);
void PresentaTMedicion(uint8_t sens);
//void PresentaResultados(void);
//void PresentaGrafico(uint8_t p);
void Rutina_Remoto();
void Rutina_Borrar_Memoria();
void Rutina_Salir();
void Rutina_Principal();
void Seleccion_Menus(int cr);

#endif /* MEF_MENU_H_ */
