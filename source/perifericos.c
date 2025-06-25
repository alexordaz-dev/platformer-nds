// Curso 2024-2025

/*-------------------------------------
perifericos.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"

int tecla; // Variable para guardar la tecla pulsada; valorar si es necesaria

int TeclaDetectada()
{
	// Devuelve TRUE si detecta que se ha pulsado alguna tecla.
	if ((~TECLAS_DAT & 0x03ff) != 0)
		return 1;
	else
		return 0;
}

int TeclaPulsada()
{

	// Devuelve el código de la tecla pulsada utilizando para ello las constantes definidas en
	// definiciones.h:  A=0;B=1;SELECT=2;START=3;DERECHA=4;IZQUIERDA=5;
	// ARRIBA=6;ABAJO=7;R=8;L=9;

	if (!(TECLAS_DAT & 1 << A))
		return A;
	else if (!(TECLAS_DAT & 1 << B))
		return B;
	else if (!(TECLAS_DAT & 1 << SELECT))
		return SELECT;
	else if (!(TECLAS_DAT & 1 << START))
		return START;
	else if (!(TECLAS_DAT & 1 << DERECHA))
		return DERECHA;
	else if (!(TECLAS_DAT & 1 << IZQUIERDA))
		return IZQUIERDA;
	else if (!(TECLAS_DAT & 1 << ARRIBA))
		return ARRIBA;
	else if (!(TECLAS_DAT & 1 << ABAJO))
		return ABAJO;
	else if (!(TECLAS_DAT & 1 << R))
		return R;
	else if (!(TECLAS_DAT & 1 << L))
		return L;

	// Si no se ha pulsado ninguna tecla, devolver -1
	else
		return -1;
}

void ConfigurarTeclado(int Conf_Tec)
{
	// Configuración del teclado. Modificar su registro de control en base a los bits
	// activados en el parametro Conf_Tec
	TECLAS_CNT |= Conf_Tec;
}

void ConfigurarTemporizador(int Latch, int Conf_Tempo)
{
	// Configuración del temporizador. El latch es el valor del registro de datos del temporizador
	// Activar los bits del registro de control necesarios en base a los bits activados en el parámetro Conf_Tempo
	TIMER0_DAT = Latch;
	TIMER0_CNT = Conf_Tempo;
}

void HabilitarIntTeclado()
{
	// Habilitar las interrupciones del teclado
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE |= (1 << 12);
	IME = 1;
}

void InhibirIntTeclado()
{

	// Deshabilitar las interrupciones del teclado
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general

	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE &= ~(1 << 12);
	IME = 1;
}

void HabilitarIntTempo()
{

	// Habilitar las interrupciones del temporizador (timer0)
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE |= (1 << 3);
	IME = 1;
}

void InhibirIntTempo()
{

	// Deshabilitar las interrupciones del temporizador (timer0)
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE &= ~(1 << 3);
	IME = 1;
}

void PonerEnMarchaTempo()
{
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	TIMER0_CNT |= (1 << 7);
}

void PararTempo()
{
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	TIMER0_CNT &= ~(1 << 7);
}

/***********************2024-2025*******************************/
