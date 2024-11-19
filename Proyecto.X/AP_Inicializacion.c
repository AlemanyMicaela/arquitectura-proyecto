/*
 * File:   AP_Inicializacion.c
 * Author: Feli
 *
 * Created on 14 de noviembre de 2024, 16:03
 */


#include <xc.h>

/**
*	\file       AP_Inicializacion.c
*	\brief      Funciones de inicializacion de todo el proyecto
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/

/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/
#include "AP_Inicializacion.h"
#include "AP_MDE.h"

/************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 ************************************************************************************************************/
// agregar prototipos
void timer0_config(void);
void iniciar_timer0(void);
void recargar_timer(void);
/************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/
static void Inicializar_LED( void ) ;
static void Inicializar_SWITCH( void ) ;
//static void Inicializar_INTENSIDAd( void ) ;
static void Inicializar_MDE4( void ) ;


/************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/
void timer0_config(void)
	{
    // configuracion del timer 0
    OSCCON = 0b01101100;	// Configuracion del oscilador 8 MHz
	//T0CONbits.TMR0ON = 1;	// timer0 encendido
    T0CONbits.T08BIT = 0;	// cuenta pulsos hasta desbordar TMR0 con 65536 porque tiene 16 bits
    T0CONbits.T0CS   = 0;	// fuente de reloj interno, trabajara como temporizador
    T0CONbits.PSA    = 0;	// habilita el prescaler
    T0CONbits.T0PS = 1;		// Factor de division 4 
    // configuracion de interrupciones
    INTCON = 0;       		// Deshabilita todas las interrupciones
    INTCONbits.TMR0IE = 1;  // habilitar las interrupciones del timer 0     
    INTCONbits.TMR0IF = 0;  // pone la bandera de interrupcion del timer 0 en 0 
    INTCONbits.GIE = 1;		// Habilita la mascara global de interrupciones
	}

void recargar_timer(void)
    {
    TMR0H = 0x3C; 		    // setea el timer 0 en 0x3CB0 = 15536 como valor inicial
    TMR0L = 0xB0;			// de modo que va a contar hasta 50000 hasta desbordar
    }

void iniciar_timer0()
{/*
	-frecuencia del osciulador se configura en --> 8 MHz ==>
    ciclo de reloj --> 1/8.000.000 seg
	-un ciclo de instruccion requiere 4 cilcos de reloj ==>
    tiempo de instruccion --> 1/8.000.000*4 = 1/2.000.000 seg 
	-el prescaler se configura para que multiplique el perìodo de reloj por 4 ==>
    salida del prescaler --> 1/2.000.000 * 4 = 1/500.000 seg cada click del timer0
	-queremos tener una base de tiempo de 100 mseg = 0,1 seg
	generamos interrupciones cada --> 0,1 / (1 / 500.000) = 50.000 click
    el timer0 debe contar desde 15.565 a 65.565 = 50.000 click 
     */
	// setea el inicio del timer0 15536 = 0x3CB0 (hexadecimal)
   TMR0H = 0x3C;
   TMR0L = 0xB0;	    
   T0CONbits.TMR0ON = 1;	// timer0 ENCENDIDO
   
   return ;
}

void __interrupt(high_priority) High_Priority_Interrupt(void)
//void high_priority interrupt High_Priority_Interrupt(void)	//File-->Project Properties-->XC8 Global Options --> C Standard --> C 90
    { 
        cuenta_interrup++; // variable global que cuenta la cantidad de interrupciones
        recargar_timer();
        INTCONbits.TMR0IF=0; // limpiar bandera de interrupcion
		//iniciar_timer0();
		return;
    }
/**
*	\fn      void Inicializar_BLINK( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/
static void Inicializar_LED( void )
{
    //!< Coloque aqui su codigo
	confirmado_on = 0 ;
    simulacion = 0 ;
	confirmado_off = 0 ;
	
	
    ANSEL=0;				// Deshabilitacion de canales analogicos
	ANSELH=0;				// Deshabilitacion de canales analogicos
	TRISDbits.TRISD0=0;		// PIN 0 DEL PUESTO D ES SALIDA
    LATDbits.LATD0 = 0;
    TRISCbits.TRISC0=1;		// PIN 0 DEL PUESTO C ES ENTRADA
    TRISCbits.TRISC1=1;     //PIN 1 DEL PUERTO C ES ENTRADA 
    TRISCbits.TRISC2=1;     //PIN 2 DEL PUERTO C ES ENTRADA
    TRISB=0;
    LATB=0;

    return ;
}

/**
*	\fn      void Inicializar_SWITCH( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/
static void Inicializar_SWITCH( void )
{
    //!< Coloque aqui su codigo
    
	confirmado_on = 0 ;
    confirmado_off=1;

    return ;
}

/*static void Inicializar_INTENSIDAd( void )
{
    //!< Coloque aqui su codigo
	intensidadlvl=0;
    return ;
}*/

static void Inicializar_MDE4( void )
{
    //!< Coloque aqui su codigo
	simulacion = 0 ;
	confirmado_off = 0 ;

    return ;
}
/************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 ************************************************************************************************************/

/**
*	\fn      void Inicializar( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/
void Inicializar( void )
{
    //Coloque aqui su codigo

    timer0_config();
	iniciar_timer0();
	Inicializar_LED( );
    Inicializar_SWITCH( );

	Inicializar_MDE4( );

	
    return ;
}

