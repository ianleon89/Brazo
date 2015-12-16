#include "Funciones.h"


/*        */


#define CONFIG_FLASH_OFFSET            0x20000//0xf000
#define CONFIG_FLASH_SECTOR            18//(CONFIG_FLASH_OFFSET >> 12)
#define CONFIG_FLASH_SECTOR_SIZE    1

#define READ_FLASH(object, adr) (*((object volatile *) (adr)))

#define LARGO 980
//#define CAMPO 50


RTCTime local_time, alarm_time, current_time;
__e_iap_status iap_status;

/* Enumerate number of FFT points to be tested */
#define NPOINTS_64			64
#define NPOINTS_256			256
#define NPOINTS_1024		1024
#define NPOINTS_4096		4096

/* Define which function to test */
//#define NPOINTS				NPOINTS_256
#define NPOINTS				NPOINTS_1024

/* Test functions */
static void vTest_PerformFFT(void);

/* Storage for FFT input and output values. Complex values are used consisting
   of real and imaginary parts, hence the buffers are twice the number of
   points */
static short *psi_Input  = (short *)0x2007C000; /* AHB SRAM0 */
static short *psi_Output = (short *)0x20080000; /* AHB SRAM1 */
	/* counts 10ms timeTicks */
//uint32_t DelayStart_SysTickCount;
int k,j,q,w;
uint16_t m,c, promedio[3],LongitudTotal,CantMediciones;
uint32_t diferencia,lectura;
volatile int16_t ValorOctava[3][20],AceleDecibel[3][20],AcelEficaz[3][2];
//volatile int16_t vector[3][1026],Fourier[1026], OctavaPromedio[3][20];
volatile int16_t vector[3][1026],Fourier[1026];
float AceEnvio[3][2];
float TBS, TBH, TG, HR, TGBHIn, TGBHOut;
float aceler;
uint16_t AN, ME, DI, HO, MI, SE;
uint8_t FH[15];
uint8_t MemoriaVacia;

//const float Octavas[20]={1,1.25,1.6,2,2.5,3.2,4,5,6.3,8,10,12.5,16,20,25,31,40,50,64,80};
const float Octavas[31]={1,1.25,1.6,2,2.5,3.2,4,5,6.3,8,10,12.5,16,20,25,31,40,50,64,80,100,125,160,200,250,320,400,500,630,800,1000};
const uint8_t NumCanal[3]={0,1,2};
uint16_t Divisor, NumeroOctavas, IndiceOctava;
uint8_t MedTie, NumEje;
uint16_t Dia, Mes, Year, Hora, Minutos, Segundos;  // Para seteo

const float FacTiempo[2]={2.57,0.9009};
const float AnchoBanda[2]={1.414,1.123};
const uint8_t NumMuestras[2]={35,100};
//const float FacEsc[3]={20.3,18.2,19.6};
//const float FacEsc[6]={3.6,3.6,3.6,32,32,32};
const float FacEsc[6]={3.6,3.6,3.6,16,16,16};
const uint8_t LongReg=68;


const float W[4][31]={
0.4825,0.4846,0.4935,0.5308,0.6335,
0.8071,0.9648,1.039,1.054,1.037,
0.9884,0.8989,0.7743,0.6373,0.5103,
0.4031,0.316,0.2451,0.1857,0.1339,
0.1,0.0989,0.0743,0.0373,0.0103,
0.0031,0.0016,0.0005,0.0004,0.0003,
0.0001,
1.011,1.007,0.9707,0.8913,0.7733,
0.6398,0.5143,0.4081,0.3226,0.255,
0.2017,0.1597,0.1266,0.1004,0.0796,
0.0630,0.0496,0.0387,0.0295,0.0213,
0.0113,0.0097,0.0066,0.0055,0.0044,
0.0030,0.0025,0.0025,0.0020,0.0013,
0.0013,
0.07,0.08,0.09,0.1,0.15,
0.2,0.3,0.545,0.7272,0.8731,
0.9514,0.9576,0.8958,0.782,0.6471,
0.5192,0.4111,0.3244,0.256,0.2024,
0.1602,0.127,0.1007,0.07988,0.06338,
0.05026,0.0398,0.03137,0.02447,0.01862,
0.01346,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


extern volatile uint32_t UART1Count;
extern volatile uint8_t UART1Buffer[BUFSIZE];
volatile uint32_t inicio,final;
const char* coma = ",";
char  FechaHora[20],aux[10];

unsigned char cadena[2*LARGO];
static char stringMemory[4*LARGO];
char estafeta[50];
char coso[2];
uint8_t  NumFiltro, NumRepe;
uint8_t NumMedicion;

/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/



/*Getters variables*/
uint16_t Getter_Variables_uint16(int selec){

	switch(selec){
		case 0:{

			return 0;

		}
		break;
		case 1:{
		return Divisor;

		}
		break;

		case 2:{
		return NumeroOctavas;

		}
		break;
		case 3:{

		return IndiceOctava;

		}
		break;
		case 4:{
		return LongitudTotal;

		}
		break;
		case 5:{
		return CantMediciones;

		}
		break;

	}

}


uint8_t Getter_Variables_uint8(int selec){
	NumFiltro, NumRepe;
	uint8_t NumMedicion;
	switch(selec){
		case 0:{

			return NumFiltro;

		}
		break;
		case 1:{
		return NumMedicion;

		}
		break;

		case 2:{
		return NumRepe;

		}
		break;/*
		case 3:{

		return NumMedicion;

		}
		break;
		case 4:{
		return LongitudTotal;

		}
		break;
		case 5:{
		return CantMediciones;

		}
		break;
*/
	}

}

char * Getter_Array_char(int selec){
	char mens3[20];
	switch(selec){

		case 0:{

			return mens3;
		}
		break;
		case 1:{

			return coso;
		}
		break;
		case 2:{

			return stringMemory;
		}
		break;
		case 3:{
			return aux;
		}
		break;

	}



}
/*
float ** Getter_Matrix_Float(int selec){

	switch(selec){
		case 0:{
			return AceEnvio;

		}
		break;
	}
}

volatile int16_t ** Getter_Matrix_Volatile(int selec){

	switch(selec){
		case 0:{
			return AceleDecibel;

		}
		break;
	}

}
*/

void PresentaResultados(uint8_t Sensor){

//	GUI_Text_Draw_In_Credit4 ("SENSOR CUERPO ENTERO", WHITE, BLACK, 55+25*w,19 + 12*q);
	int A,B;
	char mens3[20];

		if(Sensor){
			strcpy(mens3,"SENSOR CUERPO ENTERO");
		}
		else{
			strcpy(mens3,"    SENSOR BRAZ0    ");
		}
		GUI_Text_Draw_In_Credit4 (mens3, WHITE, BLACK, 1,50);
		for(q=0;q<2;q++){
			for(w=0;w<3;w++){
				A=(int)(AceEnvio[w][q]/100);
				B=(int)((AceEnvio[w][q]-A*100)/10);
				if(AceEnvio[w][q]<100){
					strcpy(mens3,"0.");
					itoa(B,aux);
					strcat(mens3,aux);
				}else{
					strcpy(mens3,"");
					itoa(A,aux);
					strcat(mens3,aux);
					strcat(mens3,".");
					itoa(B,aux);
					strcat(mens3,aux);
				}
				GUI_Text_Draw_In_Credit4 (mens3, WHITE, BLACK, 55+25*w,19 + 12*q);
			}
		}

}
void PresentaGrafico(uint8_t p,uint8_t Sensor){
	uint16_t dbInt, dbA, dife, NumBarras, XBarra;
	int w;
	//AceleDecibel=Getter_Matrix_Volatile(0);

	if(Sensor){
		NumBarras=20;
		XBarra=5;
		GUI_Window_Draw ( "GrafRes" );	//  PANTALLA PRESENTACION
	}
	else{
		NumBarras=10;
		XBarra=9;
		GUI_Window_Draw ( "GrafRes2" );	//  PANTALLA PRESENTACION
	}
	for(w=0;w<NumBarras;w++){
		dbA=(10*AceleDecibel[p][w])/4;
		dbInt=AceleDecibel[p][w]/4;
		dife=dbA-10*dbInt;
		if(dife>5) dbInt++;
		GUI_Text_Draw_In_GrafRes("", WHITE, BLACK,23+XBarra*w,53-dbInt);
		if(!Sensor) GUI_Text_Draw_In_GrafRes("", WHITE, BLACK,27+XBarra*w,53-dbInt);
	}
}





/**/

int Teclado(void){
	uint16_t val,val1;
	val=0;
	LPC_GPIO2->FIOMASK = (~(15<<3));
	lectura=LPC_GPIO2->FIOPIN;
	val1 = (lectura >>3);
	val = 15-val1;
	return(val);
}

void IniciarPromedio(void){
	int k;
    for(k=0;k<3;k++){
        for(j=0;j<20;j++){
        	AceleDecibel[k][j]=0;
        }
    }
}

void IniciarVariables(void){
    for(k=0;k<3;k++){
        for(j=0;j<1026;j++){
        	vector[k][j]=0;
        }
    }
    for(k=0;k<3;k++){
        for(j=0;j<20;j++){
        	ValorOctava[k][j]=0;
        }
    }

   // CantMediciones=0;	// CUANDO GRABE HAY QUE SACARLO
   // NumMedicion=0;
   // Divisor=1;
 //   Sensibilidad=0;
 //   UART1Count = 0;
   // q=0;
   // MemoriaVacia=1;
   // MedTie=0;


}

void EsperaTecla(void){
uint8_t sigo;
	sigo=1;
	while(sigo){
		if(Teclado()) sigo=0;
	}
}




void GLCD_Bmp (unsigned char *bmp) {
  unsigned int   j;
  unsigned short *bitmap_ptr = (unsigned short *)bmp;
  j=0;
  strcpy(cadena,"");
  while((bitmap_ptr != NULL) && (j<2*LARGO)){
	  cadena[j++]=*bitmap_ptr++;
  }
  if(strlen(cadena)>2) {
	  MemoriaVacia=0;
  }
  else{
	  MemoriaVacia=1;
  }

  LongitudTotal=strlen(cadena);
  CantMediciones=LongitudTotal/LongReg;
}


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






void MandarVector(void)
{
	char mens3[20];
	UARTSend(1, (uint8_t *)"S" ,1 );

	for(q=0;q<3;q++){
		for(m=0;m<NPOINTS;m++){
			itoa(vector[0][m],mens3);
			coso[0]=13;
			coso[1]=10;
			strcat(mens3,coso);
			UARTSend(1, (uint8_t *)mens3 , strlen(mens3) );
		}
	}
	for(q=0;q<3;q++){
		for(m=0;m<20;m++){
			itoa(ValorOctava[q][m],mens3);
			coso[0]=13;
			coso[1]=10;
			strcat(mens3,coso);
			UARTSend(1, (uint8_t *)mens3 , strlen(mens3) );
		}
	}
	for(m=0;m<2;m++){
	    itoa(AceEnvio[0][m],mens3);
	    coso[0]=13;
	    coso[1]=10;
	    strcat(mens3,coso);
		UARTSend(1, (uint8_t *)mens3 , strlen(mens3) );
	}

	UARTSend(1, (uint8_t *)"W" ,1 );
}

void LeeFechaHora(uint16_t p){
	uint8_t f;
	char mens3[20];
	strcpy(mens3,"");
	strcpy(FechaHora,"");
	for(f=0;f<2;f++){
		itoa(cadena[p*LongReg+f],mens3);
		strcat(FechaHora,mens3);
		strcat(FechaHora,"/");
	}
	itoa(cadena[p*LongReg+2],mens3);
	strcat(FechaHora,mens3);
	strcat(FechaHora," ");
	for(f=3;f<5;f++){
		itoa(cadena[p*LongReg+f],mens3);
		strcat(FechaHora,mens3);
		strcat(FechaHora,":");
	}
	itoa(cadena[p*LongReg+5],mens3);
	strcat(FechaHora,mens3);
}
void MandarVector2(uint8_t Sensor)
{
	uint16_t fincito, enviadito;
	fincito=9999;
	coso[0]=13;
	coso[1]=10;
	char mens3[20];

	UARTSend(1, (uint8_t *)"S" ,1 );
	itoa(CantMediciones,mens3);
	strcat(mens3,coso);
	UARTSend(1, (uint8_t *)mens3 , strlen(mens3) );// Envía Cant. Mediciones

	for(k=0;k<CantMediciones;k++){
		LeeFechaHora(k);
		UARTSend(1, (uint8_t *)FechaHora , strlen(FechaHora) ); // Envía FechaHora
		UARTSend(1, (uint8_t *)coso, 2 );
	}
	for(k=0;k<CantMediciones;k++){
		Sensor=	cadena[(k+1)*LongReg-2]-10; 		// Envía tipo sensor
		itoa(Sensor,mens3);
		UARTSend(1, (uint8_t *)mens3 , strlen(mens3));
		UARTSend(1, (uint8_t *)coso, 2 );
	}
	for(k=0;k<CantMediciones;k++){
		Divisor=cadena[(k+1)*LongReg-1]-10;
		for(q=0;q<60;q++){
			strcpy(mens3,"");
			enviadito=Divisor*cadena[k*LongReg+q+6]-1;
			itoa(enviadito,mens3);
			UARTSend(1, (uint8_t *)mens3 , strlen(mens3));	// Envia los tercios
			UARTSend(1, (uint8_t *)coso, 2 );
		}
	}
	itoa(fincito,mens3);
	UARTSend(1, (uint8_t *)mens3 , strlen(mens3) );
	UARTSend(1, (uint8_t *)coso, 2 );
	UARTSend(1, (uint8_t *)"W" ,1 );
}
void LevantaMedicion(uint32_t p,uint8_t Sensor){
	int QueSapa, Factor;
	QueSapa=cadena[p*LongReg+66]-10;
//	Sensor=cadena[p*LongReg+66]-10;
	/*
	if(QueSapa==0) {Sensor=0; Sensibilidad=0; Factor=4;}
	if(QueSapa==1) {Sensor=1; Sensibilidad=0; Factor=4;}
	if(QueSapa==5) {Sensor=0; Sensibilidad=1; Factor=1;}
	if(QueSapa==6) {Sensor=1; Sensibilidad=1; Factor=1;}
	Divisor=cadena[p*LongReg+67]-10;*/
	for(q=0;q<3;q++){
		for(m=0;m<20;m++){
			ValorOctava[q][m]=cadena[p*LongReg+6+20*q+m]*Divisor-1;
		}
	}
	q=0;
}

void CalculoRMS(uint8_t p, uint8_t Sensor,uint8_t Sensibilidad){        //
   int auxi1;
   float auxi2, auxi3, numerito1, numerito2;
  if(Sensor==1 && p==0) NumFiltro=0;
  if(Sensor==1 && p==1) NumFiltro=1;
  if(Sensor==1 && p==2) NumFiltro=1;
  if(Sensor==0) NumFiltro=2;
  numerito1=0;
  numerito2=0;
  NumeroOctavas=10*(Sensor-1)+20;
  IndiceOctava=k*(3-2*Sensor)+3*(1-Sensor);
  for (k=0;k<NumeroOctavas;k++)
	  {
        IndiceOctava=k*(3-2*Sensor)+3*(1-Sensor);
		numerito1 = numerito1 + (float)(ValorOctava[p][k]*ValorOctava[p][k]);
		numerito2 = numerito2 + (float)(W[NumFiltro][IndiceOctava]*ValorOctava[p][k]*W[NumFiltro][IndiceOctava]*ValorOctava[p][k]);
	  }
  auxi2=0.71*sqrt(numerito1)/FacEsc[3*Sensibilidad+p];   // divido por 76 para expresar en [m/seg2]
  AceEnvio[p][0]=auxi2*100.0;
  auxi1=(int)floor(auxi2);
  AcelEficaz[p][0]=auxi1;
  auxi3=auxi2-floor(auxi2);
  if(auxi3>0.5) AcelEficaz[p][0]=auxi1+1;

  auxi2=0.71*sqrt(numerito2)/FacEsc[3*Sensibilidad+p];   // divido por 76 para expresar en [m/seg2]
  AceEnvio[p][1]=auxi2*100.0;
  auxi1=(int)floor(auxi2);
  AcelEficaz[p][1]=auxi1;
  auxi3=auxi2-floor(auxi2);
  if(auxi3>0.5) AcelEficaz[p][1]=auxi1+1;
}

void AnalisisFrec(uint8_t p,uint8_t Sensor){
int iMagnitude, Condicion1,  j, k;
float numerito1, numerito2, tiempazo;
	for(j = 0; j < NPOINTS; j++)
	{
		psi_Input[2 * j] = (short int)vector[p][j];
		// Immaginary part of value n
		psi_Input[(2 * j) + 1] = 0;
	}

	// Perform defined FFT function
	vTest_PerformFFT();

	for(j = 0; j < NPOINTS; j++)
	{
		iMagnitude = (int)sqrt((pow(psi_Output[2 * j], 2) +
						   pow(psi_Output[(2 * j) + 1], 2)));

		Fourier[j]= iMagnitude;		// AGREGADO
	}

	   Condicion1=0;
	   k=0;
	   m=1;
	   NumeroOctavas=10*(Sensor-1)+20;
	   for (k=0;k<NumeroOctavas;k++)  // Inicializa en cero
	     {
	         Condicion1=0;
	         IndiceOctava=k*(3-2*Sensor)+3*(1-Sensor);
	         do{
	        	 if(Fourier[m]>8){	// despues vemos si se mejora
//		        	 if(Fourier[m]>FacEsc[p]/3){
		            ValorOctava[p][k]+=Fourier[m];
	        	 }
	            m++;
//	            numerito1=(float)(m*0.9009);
	            numerito1=(float)(m*FacTiempo[Sensor]);
	            numerito2=Octavas[IndiceOctava]*AnchoBanda[Sensor];
	            if(numerito1>numerito2) Condicion1=1;
	            if(m>1000) Condicion1=1;
	         }while(!Condicion1);
	     }
}
void CalculaDecibeles(uint32_t p,uint8_t Sensibilidad){
	for (k=0;k<20;k++){
		AceleDecibel[p][k]=0;
	}
	for (k=0;k<20;k++)
    {
		aceler=((float)ValorOctava[p][k])/FacEsc[3*Sensibilidad+p];
        if(ValorOctava[p][k]>0) AceleDecibel[p][k]=120+(long)(20*log10(aceler));
    }
}
void LargaMedicion(uint16_t TMedicion,uint8_t Sensor,uint8_t Sensibilidad){
	uint32_t i,auxiliar1,auxiliar2;
	uint16_t tiempi;
//    LPC_GPIO0->FIOSET = (1 << 22); // Turn LED2 on
	IniciarPromedio();
    tiempi=(int)(TMedicion/3);
    switch(MedTie){
    case 0:
    	tiempi=1;
    	break;
    case 1:
    	tiempi=7;
    	break;
    case 2:
    	tiempi=30;
    	break;
    default:
    	tiempi=1;
    	break;
    }
//	tiempi=1;
    for(w=0;w<tiempi;w++){
    	IniciarVariables();
    	for(k=0;k<3;k++){
			for(i=0;i<NPOINTS;i++)
			{
				auxiliar1=0;
				for(j=0;j<NumMuestras[Sensor];j++){
					auxiliar1 += ADC0Read(NumCanal[k]);	//Convert AD to Frequency
					for(m=0;m<3;m++);
				};
				vector[k][i]=(int)(auxiliar1/NumMuestras[Sensor]);
			}
		}
		for(k=0;k<3;k++){
			auxiliar2=0;
			for(i=0;i<NPOINTS;i++){
				auxiliar2+=vector[k][i];
			}
			promedio[k]=(int)(auxiliar2/NPOINTS);

			for(i=0;i<NPOINTS;i++){
				vector[k][i]-=promedio[k];
			}
			AnalisisFrec(k,Sensor);
		}
		for(k=0;k<3;k++){
			for(j=0;j<20;j++){
				AceleDecibel[k][j]+=ValorOctava[k][j];
			}
		}
    }	// fin repeticion para tiempos 3, 20 y 120
    //FIXME anadir esto a drivers

	LPC_GPIO3->FIOSET = (1 << 25); // Turn salida on +/- 6G
	for(k=0;k<3;k++){
		for(j=0;j<20;j++){
			ValorOctava[k][j]=(int)(AceleDecibel[k][j]/tiempi);
		}
	}

    for(j=0;j<3;j++){
    	CalculaDecibeles(j,Sensibilidad);
        CalculoRMS(j,Sensor,Sensibilidad);
    }
}

void CompactaTemp(uint8_t Sensor,uint8_t Sensibilidad){
	uint16_t ind;
	Divisor=1;
	for(q=0;q<3;q++){
		for(m=0;m<20;m++){
			if(ValorOctava[q][m]>255) Divisor=2;
		}
	}
	q=0;
	for(q=0;q<3;q++){
		for(m=0;m<20;m++){
			ind=q*20+m+6;
			cadena[LongitudTotal+ind]=(int)(1+(ValorOctava[q][m]/Divisor));
		}
	}
	k=ind;
	cadena[LongitudTotal+ind+1]=Sensor+5*Sensibilidad+10;
	cadena[LongitudTotal+ind+2]=Divisor+10;
	cadena[LongitudTotal+ind+3]='\0';
	k=strlen(cadena);
}

void Grabacion(uint8_t Sensor,uint8_t Sensibilidad){
	ConstruyeFH();
	CompactaTemp(Sensor,Sensibilidad);
	Concatena();
	BorraYGraba();
	LeeMemoria();
}
void BorraYGraba(void){
	/* Prepare for Erase the sector */
	iap_status = (__e_iap_status) iap_prepare_sector(CONFIG_FLASH_SECTOR,
			(CONFIG_FLASH_SECTOR + CONFIG_FLASH_SECTOR_SIZE));
//	if (iap_status != CMD_SUCCESS) UARTSend(1, (uint8_t *)"Error 1", 7 );
	/* Erase the sector */
	iap_status = (__e_iap_status) iap_erase_sector(CONFIG_FLASH_SECTOR,
			(CONFIG_FLASH_SECTOR + CONFIG_FLASH_SECTOR_SIZE));
//	if (iap_status != CMD_SUCCESS) UARTSend(1, (uint8_t *)"Error 2", 7 );
	/* Prepare the sector for writing */
	iap_status = (__e_iap_status) iap_prepare_sector(CONFIG_FLASH_SECTOR,
			(CONFIG_FLASH_SECTOR + CONFIG_FLASH_SECTOR_SIZE));
//	if (iap_status != CMD_SUCCESS) UARTSend(1, (uint8_t *)"Error 3", 7 );
	/* write data to flash */
	//iap_status = (__e_iap_status) iap_copy_ram_to_flash(&demo_messg, (void *)CONFIG_FLASH_OFFSET, 4096);//256);
	iap_status = (__e_iap_status) iap_copy_ram_to_flash(&stringMemory, (void *)CONFIG_FLASH_OFFSET, 4096);

//	if (iap_status != CMD_SUCCESS) UARTSend(1, (uint8_t *)"Error 4", 7 );
}

void LeeMemoria(void){
	GLCD_Bmp((uint8_t *)( CONFIG_FLASH_OFFSET));//+CONFIG_FLASH_SECTOR ));
}

void BorraMemoria(){
	//for()
//	strcpy(cadena,"");
	for(c=0; c<strlen(cadena); c++) {

		cadena[c]='\0';
	}
	for(c=0; c<strlen(stringMemory); c++) {

		stringMemory[c]='\0';
		//cadena[c];
	}

}

void Concatena(void){
	for(c=0; c<2*LARGO; c++) stringMemory[2*c] = cadena[c];
}

void EnviaInfo(void){
	LPC_UART1->IER = IER_THRE | IER_RLS;
	UARTSend(1, (uint8_t *)"S" ,1 );
	UARTSend(1, (uint8_t *)FechaHora, strlen(FechaHora) );
	UARTSend(1, (uint8_t *)"W" ,1 );
	UART1Count = 0;
	LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;
}

void DesculaFH(void){
uint16_t m;
	m=0;
	while (estafeta[m] != '\0' && m<15){
	FH[m]=estafeta[m]-48;
	m++;
	}
	Dia=10*FH[1]+FH[2]; if(Dia>90) Dia -=90;
	Mes=10*FH[3]+FH[4]; if(Mes>90) Mes -=90;
	Year=10*FH[5]+FH[6]; Year +=2000;
	Hora=10*FH[7]+FH[8]; if(Hora>90) Hora -=90;
	Minutos=10*FH[9]+FH[10]; if(Minutos>90) Minutos -=90;
	Segundos=10*FH[11]+FH[12]; if(Segundos>90) Segundos -=90;
		  local_time.RTC_Sec = Segundos;
		  local_time.RTC_Min = Minutos;
		  local_time.RTC_Hour = Hora;
		  local_time.RTC_Yday = 8;
		  local_time.RTC_Wday = 3;
		  local_time.RTC_Mday = Dia;		// current date
		  local_time.RTC_Mon = Mes;
		  local_time.RTC_Year = Year;
		  RTCSetTime( local_time );		/* Set local time */

}

void RecibeFechaHora(){
	while(UART1Count<13){
	}
	strcpy(estafeta,(char *)UART1Buffer);
	q=0;
	DesculaFH();
	UART1Count = 0;
}


void ConstruyeFH(void){
	char mens3[20];
	strcpy(FechaHora, "");
	current_time = RTCGetTime();
	DI=current_time.RTC_Mday;
	ME=current_time.RTC_Mon;
	AN=current_time.RTC_Year;
	HO=current_time.RTC_Hour;
	MI=current_time.RTC_Min;
	SE=current_time.RTC_Sec;
	cadena[LongitudTotal+0]=DI;
	cadena[LongitudTotal+1]=ME;
	cadena[LongitudTotal+2]=AN-2000;
	cadena[LongitudTotal+3]=HO;
	cadena[LongitudTotal+4]=MI;
	cadena[LongitudTotal+5]=SE;
	for(k=0;k<6;k++){
		itoa(cadena[LongitudTotal+k],mens3);
		strcat(FechaHora,mens3);
	}
	k=strlen(FechaHora);
}


void Tiempito(int Bilardo){
	int m;
	int j=0;
	for(j=0;j<1000000;j++){
        for(m=0;m<Bilardo;m++){
        }
    }
}
void PoneFechaHora(void){
	  RTCInit();
	  NVIC_EnableIRQ(RTC_IRQn);
	  LPC_RTC->CIIR = IMMIN | IMYEAR;
	  RTCStart();
}


void Inicializar_pines(int selec){

	switch(selec){
		case 0:{
			LPC_PINCON->PINSEL4 &= (~(3 << 14));	// seteo el pin 2,7 como I/O
			LPC_GPIO2->FIODIR |= (1 << 7);
			LPC_GPIO2->FIOMASK = (~(1<<7));
			LPC_GPIO2->FIOCLR = (1 << 7); // apaga el led
			LPC_PINCON->PINSEL4 &= (~(3 << 26));	// seteo el pin 2,13 como I/O
			LPC_GPIO2->FIODIR |= (0<<13);	//pin 2,13 como entrada
			Tiempito(3);

		}
		break;
		case 1:{
			LPC_PINCON->PINSEL7 &= (~(3 << 18));	// pin 3,25
	        LPC_GPIO3->FIODIR |= (1 << 25);
		    LPC_PINCON->PINSEL1 &= (~(3 << 12));
		    LPC_PINCON->PINSEL1 &= (~(3 << 10));
		    LPC_GPIO0->FIODIR |= (1 << 22);
		    LPC_GPIO0->FIODIR |= (1 << 21);
		    LPC_GPIO2->FIODIR |= (1 << 7);
		    LPC_GPIO2->FIOPIN |= (1<<13);
		    LPC_GPIO2->FIOMASK = (~(1<<7));
		  	LPC_GPIO2->FIOSET = (1 << 7);
            LPC_GPIO0->FIOSET = (1 << 21); // Turn salida on +/- 6G
	 	    LPC_GPIO3->FIOSET = (1 << 25); // Turn salida on +/- 6G

		}
		break;


	}




}

void Apaga_Salida_Seisg(){
	LPC_GPIO3->FIOCLR = (1 << 25);

}
void Apaga_Salida_Unopcincog(){

	LPC_GPIO0->FIOCLR = (1 << 22);
}

void MiraUART1(uint8_t Sensor){
	if ( UART1Count != 0 )
	{
		switch(UART1Buffer[0]){
		case 'R':	// BORRA Y GRABA
			LPC_UART1->IER = IER_THRE | IER_RLS;
			BorraYGraba();
			UARTSend(1, (uint8_t *)"Fin de codigo escritura en flash", 34 );
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;
		break;
//		case 'S':
		case 'C':
			LPC_UART1->IER = IER_THRE | IER_RLS;
			MandarVector();
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;
	//	    LPC_GPIO0->FIOSET = (1 << 22); // Turn LED2 on

		break;
		case 'B':	//Borrar
			LPC_UART1->IER = IER_THRE | IER_RLS;
			UARTSend(1, (uint8_t *)UART1Buffer, UART1Count );
			BorraMemoria();
			UARTSend(1, (uint8_t *)stringMemory, strlen(stringMemory));
			UARTSend(1, (uint8_t *)"Fin de borrado en flash", 25 );
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;

		break;
		case 'S':	// LEE MEMORIA Y ENVIA A PC (TERMINA EN 'W')
			LPC_UART1->IER = IER_THRE | IER_RLS;
			LeeMemoria();
			MandarVector2(Sensor);
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;
//			LPC_GPIO0->FIOSET = (1 << 22); // Turn LED2 on
		break;
		case 'Y':
	//		strcpy(estafeta,"");
			RecibeFechaHora();
		break;
		case 'T':
			ConstruyeFH();
			EnviaInfo();
		break;
		case 'X':
			LPC_UART1->IER = IER_THRE | IER_RLS;
			BorraMemoria();
			BorraYGraba();
			CantMediciones=0;
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;
		break;
		default:
			{
/*
			for(c=0; c<4*LARGO; c++) stringMemory[c]=32;

			ConstruyeFH();
			//                strcat(cadena, FechaHora);
			LPC_UART1->IER = IER_THRE | IER_RLS;
			UARTSend(1, (uint8_t *)UART1Buffer, UART1Count );
			UARTSend(1, (uint8_t *)FechaHora, strlen(FechaHora));
			UART1Count = 0;
			LPC_UART1->IER = IER_THRE | IER_RLS | IER_RBR;	*/
		}
		break;
		}
	}
}



void Iniciar_sistema(){
		//Called by startup code
		Incializar_variables_locales();
		Inicializar_pines(0);
	    Tiempito(3);
	    PoneFechaHora();
		ADCInit(8000000);	// inicializa el ADC con velocidad de muestreo rápida
		IniciarVariables();
		GUI_init();
		Inicializar_pines(1);

}


void vApplicationMallocFailedHook ( void )
{
	for( ;; );
}

void vApplicationStackOverflowHook ( xTaskHandle *pxTask, signed char *pcTaskName )
{
	for( ;; );
}

void vApplicationIdleHook ( void )
{

}

void vApplicationTickHook ( void )
{

}
static void vTest_PerformFFT(void)
{
	#ifdef NPOINTS
	{
		#if (NPOINTS == NPOINTS_64)
		{
			vF_dspl_fftR4b16N64(psi_Output, psi_Input);
		}
		#elif (NPOINTS == NPOINTS_256)
		{
			vF_dspl_fftR4b16N256(psi_Output, psi_Input);
		}
		#elif (NPOINTS == NPOINTS_1024)
		{
			vF_dspl_fftR4b16N1024(psi_Output, psi_Input);
		}
		#elif (NPOINTS == NPOINTS_4096)
		{
			vF_dspl_fftR4b16N4096(psi_Output, psi_Input);
		}
		#else
		{
			#error "NPOINTS Not Valid!"
		}
		#endif
	}
	#else
	{
		#error "NPOINTS Not Defined!"
	}
	#endif
}


void wndExample_btnChange_OnClik (void* paramater)
{
	TText* pText;

	// Get the GUI's object
	pText = (TText*) GUI_Window_SearchObject ("txtLed");
	if ( strcmp (pText->text, " LED OFF ") == 0 )
	{
		pText->text = " LED ON ";
		LPC_GPIO0->FIODIR |= (1<<18);
		LPC_GPIO0->FIOSET = (1<<18);
	}
	else
	{
		pText->text = " LED OFF ";
		LPC_GPIO0->FIODIR |= (1<<18);
		LPC_GPIO0->FIOCLR = (1<<18);
	}
}
void EINT3_IRQHandler (void)
{
	portBASE_TYPE xHigherPriorityTaskWoken;

	NVIC_DisableIRQ(EINT3_IRQn); 			// Disable the interrupt

	LPC_SC->EXTINT = EINT3; 				// Clear the external interrupt flag
	LPC_GPIOINT->IO0IntClr = 0x01000000; 	// Clear the specific pin interrupt flag

	// Give semaphore
	xSemaphoreGiveFromISR (semaphore_TouchInterrupt, &xHigherPriorityTaskWoken);
}

void ConfigExternalInterrupt ( )
{
	// Configuration of the external interrupt
	LPC_GPIOINT->IO0IntEnF = 0x01000000; 	// Port0.24 (falling edge)
	LPC_SC->EXTMODE = EINT3_EDGE; 			// INT3 edge trigger
	LPC_SC->EXTPOLAR = 0;					// INT3 is falling edge

	// Enable the external interrupt
	NVIC_EnableIRQ(EINT3_IRQn);				// Enable the interrupt
	LPC_SC->EXTINT = EINT3; 				// Clear the external interrupt flag
	LPC_GPIOINT->IO0IntClr = 0x01000000; 	// Clear the specific pin interrupt flag
}


void wndDimmer_btnBack_OnClik ( void* parameter )
{
	GUI_Window_Draw ( "Menu" );
}



