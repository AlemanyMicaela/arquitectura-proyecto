/*
 * File:   AP_MDE.c
 * Author: Feli
 *
 * Created on 14 de noviembre de 2024, 16:09
 */




/**
*	\file       AP_MDE.c
*	\brief      Maquina/s de Estado
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/
/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/
#include "AP_MDE.h"
#include "AP_FuncionesMDE.h"
#include <xc.h>
/************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 ************************************************************************************************************/
#define		RESET		0	
//Maquina: BLINK
#define		APAGADO		1	// < Maquina: BLINK >
#define		ENCENDIDO		2	// < Maquina: BLINK >
#define		DESTELLANDO		3	// < Maquina: BLINK >

//Maquina: SWITCH
#define		SWITCH_OFF		1	// < Maquina: SWITCH >
#define		SWITCH_ON		2	// < Maquina: SWITCH >
#define		CONFIRMANDO_ON		3	// < Maquina: SWITCH >
#define		CONFIRMANDO_OFF		4	// < Maquina: SWITCH >

//Maquina: INTENSIDAD
//#define		INTENSIDAD		1	// < Maquina: INTENSIDAD >
//#define		INT		2	// < Maquina: INTENSIDAD >
//#define		OFF		3	// < Maquina: INTENSIDAD >

//Maquina: MDE4
#define		no_simula		1	// < Maquina: MDE4 >
#define		Simula_ausencia		2	// < Maquina: MDE4 >
#define		Simula_presencia		3	// < Maquina: MDE4 >

/************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 ************************************************************************************************************/

/************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/
static int LED ( int );
static int SWITCH ( int );
//static int INTENSIDAd ( int );
static int MDE4 ( int );


/************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 ************************************************************************************************************/
int confirmado_on;		//
int confirmado_off;		//
//int intensidadlvl;		//
int simulacion;		//


/************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/

/**
*	\fn      static int BLINK ( int Estado )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   [in] Estado: caso dentro de la maquina (estado actual)
*	\return  int : estado siguiente
*/
static int SWITCH ( int  Estado )
{
    switch ( Estado )
    {

        case RESET :
            confirmado_off = 1;
            confirmado_on = 0;
            

            Estado = SWITCH_OFF;

            break;

        case SWITCH_OFF :
            if ( s_llave_on() )
            {
                t_antirebote();

                Estado = CONFIRMANDO_ON;
            }

            break;

        case SWITCH_ON :
            if ( s_llave_off() )
            {
                t_antirebote();
                Estado = CONFIRMANDO_OFF;
            }

            break;

        case CONFIRMANDO_ON :
            if ( e_antirebote() && s_llave_off() )
            {
               
                Estado = SWITCH_OFF;
            }

            if ( e_antirebote() && s_llave_on() )
            {
                confirmado_on = 1;
                confirmado_off = 0;
                f_intoff();
                f_inton();

                Estado = SWITCH_ON;
            }

            break;

        case CONFIRMANDO_OFF :
            if ( e_antirebote() && s_llave_on() )
            {

                Estado = SWITCH_ON;
            }

            if ( e_antirebote() && s_llave_off() )
            {
                confirmado_off = 1;
                confirmado_on = 0;
                f_intoff();
                f_position();

                Estado = SWITCH_OFF;
            }

            break;


        default:
            Estado = RESET ;
            break;

    }
    return Estado ;
}

static int LED ( int  Estado ){
    switch ( Estado )
    {

        case RESET :
            f_apagar();

            Estado = APAGADO;

            break;

        case APAGADO :
            if ( confirmado_on == 1 )
            {
                f_encender();
                Estado = ENCENDIDO;
            }

            break;

        case ENCENDIDO :
            if ( confirmado_off == 1 )
            {
                f_apagar();
                

                Estado = APAGADO;
            }

            break;

        
        default:
            Estado = RESET ;
            break;

    }
    return Estado ;
}
/*
static int INTENSIDAd ( int  Estado )
{
    switch ( Estado )
    {

        case RESET :
            intensidadlvl = 1;
            Estado = INTENSIDAD;

            break;

        case INTENSIDAD :
            if ( confirmado_on == 1 && s_llave_up())
            {
                f_intup();
                Estado = INT;
            }
            if(confirmado_on==1 && s_llave_down()){
            
                f_intdown();
                Estado= INT;
            }

            break;

        case INT :
            if ( confirmado_off == 1 )
            {
                Estado = OFF;
            }
            if(confirmado_on==1){
            
                Estado=INTENSIDAD;
            }

            break;

        case OFF :
            if ( confirmado_off == 1 )
            {
            }
           
            if(confirmado_on==1){
                    Estado = INTENSIDAD;
            }
            

            break;

        default:
            Estado = RESET ;
            break;

    }
    return Estado ;
}
*/

static int MDE4 ( int  Estado )
{

    switch ( Estado )
    {

        case RESET :
            simulacion = 0;

            Estado = no_simula;

            break;

        case no_simula :
            if ( simulacion == 0 && confirmado_on == 1 )
            {

                Estado = no_simula;
            }

            if ( confirmado_off == 1 )
            {
                f_encender();
                t_simular();
                simulacion = 1;

                Estado = Simula_presencia;
            }

            break;

        case Simula_ausencia :
            if ( e_noSimular() )
            {
               
               
                f_noSimula();
                simulacion = 0;

                Estado = no_simula;
            }

            break;

        case Simula_presencia :
            if ( e_simular() )
            {
                f_apagar();
                t_noSimular();

                Estado = Simula_ausencia;
            }

            break;

        default:
            Estado = RESET ;
            break;

    }
    return Estado ;
}



/************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 ************************************************************************************************************/

/**
*	\fn      void MaquinaDeEstados ( void )
*	\brief   Coloque aqui su descripcion
*	\details Amplie la descripcion
*	\author  yo
*	\date    14-11-2024 15:53:14
*   \param   void
*	\return  void
*/
void MaquinaDeEstados ( void )
{
    static int estados_LED = RESET;
    static int estados_SWITCH = RESET;
    //static int estados_INTENSIDAd = RESET;
    static int estados_MDE4 = RESET;

    // Coloque su codigo aqui
    estados_INTENSIDAd = INTENSIDAd(estados_INTENSIDAd);
    estados_LED = LED( estados_LED );
    estados_SWITCH = SWITCH( estados_SWITCH );
    estados_MDE4 = MDE4( estados_MDE4 );


    return ;
}

