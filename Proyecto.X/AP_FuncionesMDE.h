/**
*	\file       AP_FuncionesMDE.h
*	\brief      Prototipos, defines, etc. de los Eventos y Acciones asociadas a la M de E
*	\details    Descripcion detallada del archivo
*	\author     yo
*	\date       14-11-2024 15:53:14
*/

#ifndef INC_AP_FUNCIONESMDEE_H_
#define INC_AP_FUNCIONESMDEE_H_

/************************************************************************************************************
 *** INCLUDES GLOBALES
 ************************************************************************************************************/

/************************************************************************************************************
 *** DEFINES GLOBALES
 ************************************************************************************************************/
#define		TRUE		1
#define		FALSE		0
#define		ON		1
#define		OFF		0

/************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 ************************************************************************************************************/

/************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES GLOBALES
 ************************************************************************************************************/

/*-------------------------------------------- EVENTOS ----------------------------------------------------*/

int s_llave_on ( void );
int s_llave_off ( void );
int e_antirebote ( void );

int e_simular ( void );
int e_noSimular ( void );

/*-------------------------------------------- ACCIONES ----------------------------------------------------*/

void f_apagar ( void );
void f_encender ( void );

//void f_apagarint(void);

void f_inton(void);
void f_intoff ( void );

void f_noSimula ( void );


/*------------------------------------------TEMPORIZADORES -------------------------------------------------*/

void t_antirebote ( void );
void t_noSimular ( void );

void t_simular ( void );

#endif /* INC_AP_FUNCIONESMDEE_H_ */
