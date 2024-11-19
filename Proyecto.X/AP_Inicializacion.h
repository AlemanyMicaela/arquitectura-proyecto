/**
*	\file       AP_Inicializacion.h
*	\brief      prototipo de la Funcion general de inicializaciones
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/

#ifndef INC_AP_INICIALIZACION_H_
#define INC_AP_INICIALIZACION_H_

//agregar configuración includes
#include <stdio.h>
// configuracion del lenguaje XC8 y del PIC
#include <xc.h>
#include <pic18f46k20.h>

/************************************************************************************************************
 *** DEFINES GLOBALES
 ************************************************************************************************************/
//agregar configuracion de fuses
// configuracion de fuses del PIC
#pragma config CONFIG1H = 0x08
#pragma config CONFIG2L	= 0x19
#pragma config CONFIG2H = 0x1E
#pragma config CONFIG3H = 0x01
#pragma config CONFIG4L = 0x80
#pragma config CONFIG5L	= 0x0F
#pragma config CONFIG5H	= 0xC0
#pragma config CONFIG6L	= 0x0F
#pragma config CONFIG6H	= 0xE0
#pragma config CONFIG7L	= 0x0F
#pragma config CONFIG7H	= 0x40

// base de tiempo utilizada también en AP_FuncionesMDE.c como externa
unsigned long cuenta_interrup = 0;
void recargar_timer(void);
void timer0_config(void);
void Inicializar( void ) ;

#endif /* INC_AP_INICIALIZACION_H_ */
