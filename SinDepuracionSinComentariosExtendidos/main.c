/**
*	\file       main.c
*	\brief      Proyecto: MDE1
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       19-11-2024 16:23:00
*/

/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/

#include "AP_MDE.h"
#include "AP_Inicializacion.h"

void main ( void )
{
    Inicializar( );

    while ( 1 )
    {
        MaquinaDeEstados();
    }
    return ;
}

