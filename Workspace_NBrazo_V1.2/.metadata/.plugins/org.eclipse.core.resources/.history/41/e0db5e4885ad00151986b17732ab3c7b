#include "Graficos.h"

void GUI_init(){
	StartGUI ();
	CreateGUI ();
	GUI_Window_Draw ( "Home" );	//  PANTALLA PRESENTACION
	Tiempito(20);
}


void StartGUI ()
{
	GUI_DefineHeapMalloc ( pvPortMalloc );
	GUI_DefineHeapFree ( vPortFree );
	GUI_StartLibrary ();
}

void Posicion_Flecha(uint8_t cursor1,uint8_t old_cursor1 ){

	GUI_Text_Draw_In_Menu ("  ", WHITE, BLACK, 2,1+10*old_cursor1);
	GUI_Text_Draw_In_Menu ("->", WHITE, BLACK, 2,1+10*cursor1);

}

void CreateGUI ()
{
	// Window "Home"	PRESENTACION
	GUI_Window_Create ( "Home", "None", WHITE, "BIENVENIDO", NULL, NULL, NULL );
	GUI_Text_Create ( "Home", "txtAp1", 24, 20, WHITE, "", BLACK, "  VIBROMETRO" );
	GUI_Button_Create ( "Home", "btnHome1", 12, 52, 40, 40, BLACK, "", WHITE, " Vib 2.0",
						wndHome_btnSettings_OnClik, NULL, NULL, NULL );

	// Window "Credits" PANTALLA MEDICIÓN PREVIA
	GUI_Window_Create ( "Credits", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Credits", "txtInfo6", 5, 1, BLACK, "", WHITE, "   MEDICION " );
	GUI_Text_Create ( "Credits", "txtInfo3", 5, 12, WHITE, "", BLACK, "SENSOR" );
	GUI_Text_Create ( "Credits", "txtInfo3", 5, 22, WHITE, "", BLACK, "T. MEDICION(s)" );
	GUI_Text_Create ( "Credits", "txtInfo3", 5, 32, WHITE, "", BLACK, "SENSIBILIDAD:" );
		GUI_Text_Create ( "Credits", "txtInfo3", 5, 45, WHITE, "", BLACK, "INICIAR => <ENTER> " );
	GUI_Text_Create ( "Credits", "txtInfo3", 5, 55, WHITE, "", BLACK, "VOLVER  => <CANCEL>" );

	// Window "Credit2" PANTALLA CONFIRMA DATALOGGER
	GUI_Window_Create ( "Credit2", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Credit2", "txtInfo6", 5, 1, BLACK, "", WHITE, " CONFIRMA" );
	GUI_Text_Create ( "Credit2", "txtInfo3", 5, 25, WHITE, "", BLACK, "  SI  =>  <ENTER>   " );
	GUI_Text_Create ( "Credit2", "txtInfo3", 5, 45, WHITE, "", BLACK, "  NO  =>  <CANCEL>   " );

	// Window "Credit3" PANTALLA COMUNICACION PC
	GUI_Window_Create ( "Credit3", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Credit3", "txtInfo6", 5, 1, BLACK, "", WHITE, " COMUNICACION A PC" );
	GUI_Text_Create ( "Credit3", "txtInfo3", 5, 50, WHITE, "", BLACK, "SALIR   => <CANCEL> " );

	// Window "Credit4" PANTALLA PRESENTA RESULTADOS
	GUI_Window_Create ( "Credit4", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Credit4", "txtInfo6", 5, 1, BLACK, "", WHITE, " EJES     Z   X   Y" );
	GUI_Text_Create ( "Credit4", "txtInfo3", 1, 20, WHITE, "", BLACK, "S/FILTRO " );
	GUI_Text_Create ( "Credit4", "txtInfo3", 1, 32, WHITE, "", BLACK, "C/FILTRO " );

	// Window "Credit5" PANTALLA fin medicion
		GUI_Window_Create ( "Credit5", "None", WHITE, "", NULL, NULL, NULL );
		GUI_Text_Create ( "Credit5", "txtInfo6", 5, 1, BLACK, "", WHITE, "   GRABAR MEDICION" );
		GUI_Text_Create ( "Credit5", "txtInfo7", 5, 20, WHITE, "", BLACK, "CANT. REGISTROS:    " );
		GUI_Text_Create ( "Credit5", "txtInfo3", 5, 45, WHITE, "", BLACK, "  SI  =>  <ENTER>   " );
		GUI_Text_Create ( "Credit5", "txtInfo3", 5, 55, WHITE, "", BLACK, "  NO  =>  <CANCEL>   " );

	// Window "Menu"  Pantalla Principal
	GUI_Window_Create ( "Menu", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Menu", "txtInfo6", 5, 1, BLACK, "", WHITE, "       MENU" );
	GUI_Text_Create ( "Menu", "txto44", 20, 11, WHITE, "", BLACK, "MEDICION      " );
	GUI_Text_Create ( "Menu", "txto45", 20, 21, WHITE, "", BLACK, "REMOTO" );
	GUI_Text_Create ( "Menu", "txto46", 20, 31, WHITE, "", BLACK, "VER ANTERIORES" );
	GUI_Text_Create ( "Menu", "txto46", 20, 41, WHITE, "", BLACK, "BORRAR MEMORIA" );
	GUI_Text_Create ( "Menu", "txto46", 20, 51, WHITE, "", BLACK, "SALIR         " );

	// Window "Example"	Pantalla apagado
	GUI_Window_Create ( "Example", "", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Example", "", 25, 23, WHITE, "", BLACK, " APAGANDO " );
	GUI_Text_Create ( "Example", "", 25, 43, WHITE, "", BLACK, "  NS 291 " );

	// Window "Dimmer"	Pantalla elegir tiempo medición
	GUI_Window_Create ( "Dimmer", "", WHITE, "" ,NULL, NULL, NULL );
	GUI_Text_Create ( "Dimmer", "txt0", 3, 1, BLACK, "", WHITE, "COMIENZA MEDICION EN" );

	// Window "ATENCION"	Pantalla QUE AVISA MEMORIA LLENA
	GUI_Window_Create ( "Atencion", "", WHITE, "" ,NULL, NULL, NULL );
	GUI_Text_Create ( "Atencion", "txt0", 3, 1, BLACK, "", WHITE, "      ATENCION" );
	GUI_Text_Create ( "Atencion", "txto46", 10, 31, WHITE, "", BLACK, "MEMORIA COMPLETA   " );

	// Window "GrafRes"	Pantalla grafico en dicibeles
	GUI_Window_Create ( "GrafRes", "", WHITE, "" ,NULL, NULL, NULL );
	GUI_Text_Create ( "GrafRes", "txt0", 3, 1, BLACK, "", WHITE, "BANDAS OCTAVAS (dB)" );
	GUI_Text_Create ( "GrafRes", "txt8", 1, 20, WHITE, "", BLACK, "120" );
	GUI_Text_Create ( "GrafRes", "txt8", 6, 30, WHITE, "", BLACK, "80" );
	GUI_Text_Create ( "GrafRes", "txt8", 6, 40, WHITE, "", BLACK, "40" );
	GUI_Text_Create ( "GrafRes", "txt8", 113, 55, WHITE, "", BLACK, "Hz" );
	GUI_Text_Create ( "GrafRes", "txt8", 24, 55, WHITE, "", BLACK, "1" );
	GUI_Text_Create ( "GrafRes", "txt8", 53, 55, WHITE, "", BLACK, "4" );
	GUI_Text_Create ( "GrafRes", "txt8", 73, 55, WHITE, "", BLACK, "10" );
	GUI_Text_Create ( "GrafRes", "txt8", 93, 55, WHITE, "", BLACK, "25" );
	// Window "GrafRes2"	Pantalla grafico en dicibeles
	GUI_Window_Create ( "GrafRes2", "", WHITE, "" ,NULL, NULL, NULL );
	GUI_Text_Create ( "GrafRes2", "txt0", 3, 1, BLACK, "", WHITE, "BANDAS OCTAVAS (dB)" );
	GUI_Text_Create ( "GrafRes2", "txt8", 1, 20, WHITE, "", BLACK, "120" );
	GUI_Text_Create ( "GrafRes2", "txt8", 6, 30, WHITE, "", BLACK, "80" );
	GUI_Text_Create ( "GrafRes2", "txt8", 6, 40, WHITE, "", BLACK, "40" );
	GUI_Text_Create ( "GrafRes2", "txt8", 113, 55, WHITE, "", BLACK, "Hz" );
	GUI_Text_Create ( "GrafRes2", "txt8", 24, 55, WHITE, "", BLACK, "2" );
	GUI_Text_Create ( "GrafRes2", "txt8", 53, 55, WHITE, "", BLACK, "16" );
	GUI_Text_Create ( "GrafRes2", "txt8", 73, 55, WHITE, "", BLACK, "63" );
	GUI_Text_Create ( "GrafRes2", "txt8", 93, 55, WHITE, "", BLACK, "250" );
	// Window "Anterior"	Pantalla para graficar tercios de octava
	GUI_Window_Create ( "Anterior", "None", WHITE, "", NULL, NULL, NULL );
	GUI_Text_Create ( "Anterior", "txtInfo6", 3, 1, BLACK, "", WHITE, "VER MEDICION PREVIA" );
	GUI_Text_Create ( "Anterior", "txtInfo7", 5, 20, WHITE, "", BLACK, "MED. NUMERO:" );
	GUI_Text_Create ( "Anterior", "txtInfo3", 5, 45, WHITE, "", BLACK, "  SI  =>  <ENTER>   " );
	GUI_Text_Create ( "Anterior", "txtInfo3", 5, 55, WHITE, "", BLACK, "  NO  =>  <CANCEL>   " );

}

void wndHome_btnSettings_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Menu" );
}

void wndHome_picFiuba_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Credits" );
}

void wndCredits_btnBack_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Home" );
}

void wndMenu_btnExample_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Example" );
}

void wndMenu_btnDimmer_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Dimmer" );
}

void wndMenu_btnBack_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Home" );
}

void wndExample_btnBack_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Menu" );
}


