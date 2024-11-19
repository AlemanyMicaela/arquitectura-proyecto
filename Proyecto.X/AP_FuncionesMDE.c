/*
 * File:   AP_FuncionesMDE.c
 * Author: Feli
 *
 * Created on 14 de noviembre de 2024, 16:05
 */

#include "AP_FuncionesMDE.h"
#include "AP_Inicializacion.h"
#include <xc.h>
#define _XTAL_FREQ  8000000 // necesaria para la funci�n delay en C90

//rand()
#include <stdio.h> /* Declaración librerías*/
#include <stdlib.h>
#include <time.h>


/**
*	\file       AP_FuncionesMDE.c
*	\brief      Funciones de Eventos y Acciones asociadas a las Maquinas de estados
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/

/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/


/************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 ************************************************************************************************************/


/************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 ************************************************************************************************************/
int antiReboteCounter = 0;
int botonEstadoPrevio = 0;
static unsigned char led_position = 0b00000001;


unsigned long t_antirebote_ini; // valor inicial del cronometro para el parpadeo
/************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 ************************************************************************************************************/

/*-------------------------------------------- EVENTOS ----------------------------------------------------*/

/**
*	\fn      int s_llave_on ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  int : TRUE y FALSE
*/


int s_llave_on ( void )
{
    return (PORTCbits.RC0);
}

/**
*	\fn      int s_llave_off ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  int : TRUE y FALSE
*/


int s_llave_off ( void )
{
    return !(PORTCbits.RC0);
}

/**
*	\fn      int e_antirebote ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  int : TRUE y FALSE
*/






/*-------------------------------------------- ACCIONES ----------------------------------------------------*/

/**
*	\fn      void f_apagar ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/


void f_apagar ( void )
{
    LATDbits.LATD0 = 0;
    return ;
}

/**
*	\fn      void f_encender ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/


void f_encender ( void )
{
    LATDbits.LATD0 = 1;
    return ;
    
}

void f_position(void){
led_position = 0b00000001;
return;
}


/**
*	\fn      void f_intensidadlvl ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/




int e_antirebote ( void )
{
    int res = 0 ;

    if(cuenta_interrup-t_antirebote_ini >= 3.5) // 1 interrupcion = 100 mseg = 1 decima de segundo
		res=1; // dispara el evento

    return res ;
}

void t_antirebote( void )
{
    t_antirebote_ini = cuenta_interrup;
    //__delay_ms(100); bloqueante, esta funcion no existe  en C99
    return ;
}





void f_noSimula ( void )
{
    //LATDbits.LATD0 = 0;
    //return ; 

}


/*------------------------------------------TEMPORIZADORES -------------------------------------------------*/

/**
*	\fn      void t_antirebote ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\details Tiempo: 001
*	\details Base: SEGUNDOS
*	\author  yo
*	\date    14-11-2024 15:53:14

*   \param   void
*	\return  void
*/
void t_noSimular ( void )
{
    t_antirebote_ini = cuenta_interrup;

    return ;
}
void t_simular ( void )
{
    t_antirebote_ini = cuenta_interrup;

    return ;
}


int e_simular ( void )
{
    int res = 0 ;

    float var= rand() % 6 + 4; // esto es una simulacion y le voy  a colocar valores chicos.... 
    if(cuenta_interrup-t_antirebote_ini >= var) // 1 interrupcion = 100 mseg = 1 decima de segundo    
		res=1; // dispara el evento

    return res ;
}


/**
*	\fn      int s_intensidup ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  int : TRUE y FALSE
*/


int e_noSimular ( void )
{
    int res = 0 ;

    float var=rand() % 6 + 4; // esto es una simulacion y le voy  a colocar valores chicos.... 
    if(cuenta_interrup-t_antirebote_ini >= var) // 1 interrupcion = 100 mseg = 1 decima de segundo    
		res=1; // dispara el evento

    return res ;
}

