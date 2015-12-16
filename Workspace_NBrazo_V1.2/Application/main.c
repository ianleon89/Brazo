/*
 	 ACELEROMETRO CON DOS SENSIBILIDADES. COMPILADO EL 1/10/15
 	 	 	 NS 281 y copiado el 16/11/15 NS 291
 */



#include "main.h"


void main(void)
{


	SystemInit();
	Iniciar_sistema();
	Tiempito(20);
	UARTInit(1, 115200);
    LeeMemoria();
	GUI_Window_Draw ( "Menu" );	// PANTALLA PRINCIPAL
	Mef_Init();

	while(1){

		ActualizarMef();

	}

}




