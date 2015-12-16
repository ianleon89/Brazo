/*
 * Graficos.h
 *
 *  Created on: 30/11/2015
 *      Author: ANDRES
 */

#ifndef GRAFICOS_H_
#define GRAFICOS_H_

#include <stdint.h>
#include "definitions.h"
#include <GLCDPrimitives.h>
#include <GLCDLowLevel.h>
#include <GLCDColor.h>


void GUI_init();
void StartGUI ();


void CreateGUI ();


void wndHome_btnSettings_OnClik ( void* parameter );


void wndHome_picFiuba_OnClik ( void* parameter );

void wndCredits_btnBack_OnClik ( void* parameter );


void wndMenu_btnExample_OnClik ( void* parameter );


void wndMenu_btnDimmer_OnClik ( void* parameter );


void wndMenu_btnBack_OnClik ( void* parameter );


void wndExample_btnBack_OnClik ( void* parameter );
void Posicion_Flecha(uint8_t cursor1,uint8_t old_cursor1);


#endif /* GRAFICOS_H_ */
