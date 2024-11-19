/*
 * File:   main.c
 * Author: Feli
 *
 * Created on 14 de noviembre de 2024, 15:57
 */

#include "AP_MDE.h"
#include "AP_Inicializacion.h"

#include <xc.h>

/**
*	\file       main.c
*	\brief      Proyecto: 2-blink+switch_antirebote
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/

/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/


void main ( void )
{
    Inicializar( );

    while ( 1 )
    {
        MaquinaDeEstados();
    }
    return ;
}


