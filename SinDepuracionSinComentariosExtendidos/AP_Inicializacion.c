/**
*	\file       AP_Inicializacion.c
*	\brief      Funciones de inicializacion de todo el proyecto
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       19-11-2024 16:23:00
*/

/************************************************************************************************************
 *** INCLUDES
 ************************************************************************************************************/
#include "AP_Inicializacion.h"
#include "AP_MDE.h"

/************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 ************************************************************************************************************/

/************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/
static void Inicializar_LED( void ) ;
static void Inicializar_SWITCH( void ) ;
static void Inicializar_MDE4( void ) ;

/************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 ************************************************************************************************************/

/**
*	\fn      void Inicializar_LED( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    19-11-2024 16:23:00
*   \param   void
*	\return  void
*/
static void Inicializar_LED( void )
{
    //!< Coloque aqui su codigo
	confirmado_on = 0 ;
	simulacion = 0 ;
	confirmado_off = 0 ;

    return ;
}

/**
*	\fn      void Inicializar_SWITCH( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    19-11-2024 16:23:00
*   \param   void
*	\return  void
*/
static void Inicializar_SWITCH( void )
{
    //!< Coloque aqui su codigo

    return ;
}

/**
*	\fn      void Inicializar_MDE4( void )
*	\brief   Inicializacion de las diferentes maquinas de estado
*	\details Amplie la descripcion
*	\author  yo
*	\date    19-11-2024 16:23:00
*   \param   void
*	\return  void
*/
static void Inicializar_MDE4( void )
{
    //!< Coloque aqui su codigo
	simulacion = 0 ;
	confirmado_on = 0 ;

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
*	\date    19-11-2024 16:23:00
*   \param   void
*	\return  void
*/
void Inicializar( void )
{
    //Coloque aqui su codigo


	Inicializar_LED( );

	Inicializar_SWITCH( );

	Inicializar_MDE4( );

	
    return ;
}

