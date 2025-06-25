// Curso 2024-2025

/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/
        
#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "nivel.h"
#include "personaje.h"
        
int ESTADO; // Estado del juego
int Niv = 0;  //Sirve para controlar desde que estado se ha pasado a NIVEL
int Seg = 60; //Contador de segundos del nivel
Personaje jugador;

void RutAtencionTeclado()
{
    //Menú principal
    if (ESTADO == INICIO)
    {
        //Inicia el juego
        if (TeclaPulsada() == START)
        {
            inicializarPersonaje(&jugador);
			cargarNivel(NivelActual);
			vidas = 5;
			Seg = 60;
            ESTADO = JUEGO;
        }
    }
    //Durante el juego
    else if (ESTADO == JUEGO)
    {

        //Pausa el jeugo
        if (TeclaPulsada() == START)
        {
            ESTADO = PAUSA;
            visualizarPausa();
            BorrarPepe(0,0,0);
            BorrarVidas(vidas);
            cargarNivel(0);
            consoleClear();
        }
        //Muestra los niveles disponibles
        else if (TeclaPulsada() == SELECT)
        {
            Niv = 1; //Para saber que se ha accedido desde jeugo.
            ESTADO = NIVELES;
            cargarNivel(0);
            BorrarPepe(0,0,0);
            BorrarVidas(vidas);
            consoleClear();
            mostrarNiveles(UltimoNivel);
        }
    }
    //Desde la pantalla de Game Over cambia al menú principal.
    else if (ESTADO == FINJUEGO){
        if (TeclaPulsada()==START){
            visualizarMenu();
			ESTADO = INICIO;	
        }
    }
}

void RutAtencionTempo()
{
    static int tick = 0;

    if (ESTADO == JUEGO)
    {
        tick++;
        if (tick == 10)
        {
            Seg--;
            // Eliminar la línea previa para que no se vea la unidad decimal cuando pasamos a unidades 10->9
            consoleClear();
            iprintf("\x1b[13;5HTIEMPO=%d", Seg);
            tick = 0;
        }
       
        //Compueba si se ha acabado el tiempo.
        if (Seg == 0)
        {
            BorrarPepe(0, 0, 0);
			BorrarVidas(vidas);
			cargarNivel(0);
			UltimoNivel = 1;
			NivelActual = 1;
			visualizarFinJuego();
					
            ESTADO = FINJUEGO;
        }
    }
}

void EstablecerVectorInt()
{

    irqSet(IRQ_KEYS, RutAtencionTeclado);
    irqSet(IRQ_TIMER0, RutAtencionTempo);
}

/***********************2024-2025*******************************/
