// Curso 2024-2025

/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo"
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/

#include <nds.h>	// Librería de la nds
#include <stdio.h>	// Librería de entrada/salida estándar de C
#include <stdlib.h> // Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h> // Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto

#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "personaje.h"
#include "nivel.h"
#include "sprites.h"

Personaje jugador; 
int delayCambioEstado = 0;
int UltimoNivel = 1;
int NivelActual = 1;

void juego()
{
	// Inicialización
	ESTADO = INICIO;
	visualizarMenu();

	// Configurar sprites
	memoriaReserva();
	EstablecerPaletaPrincipal();
	GuardarSpritesMemoria();

	//*************************** Interrupciones y TIMER ****************************//
	// Configurar el teclado Start y Select por interrupción.
	ConfigurarTeclado(0x400C);
	// Configurar el temporizador.
	ConfigurarTemporizador(0x3333, 0x00C1);
	// Establecer las rutinas de atención a interrupciones.
	EstablecerVectorInt();
	// Habilitar las interrupciones del teclado.
	HabilitarIntTeclado();
	// Habilitar las interrupciones del temporizador.
	HabilitarIntTempo();
	// Habilitar interrupciones.
	HabilitarInterrupciones();
	//******************************************************************************//

	// Bucle Principal
	while (1)
	{
		// Pantalla Tactil
		touchRead(&PANT_DAT);

		// Verificamos si hay toque (los valores rawx/rawy son > 0 cuando se toca)
		int tocando = (PANT_DAT.rawx > 0 || PANT_DAT.rawy > 0) ? 1 : 0;

		// Actualizar delay
		if (delayCambioEstado > 0)
		{
			delayCambioEstado--;
			tocando = 0; // Ignorar toques durante el delay
		}

		if (ESTADO == INICIO)
		{
			// Botones
			if (tocando && delayCambioEstado == 0)
			{
				if (PANT_DAT.px > 90 && PANT_DAT.px < 164)
				{
					if (PANT_DAT.py > 51 && PANT_DAT.py < 78)
					{
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						vidas = 5;
						Seg = 60;
						ESTADO = JUEGO;
						delayCambioEstado = DELAY_ESTADO;
					}
					else if (PANT_DAT.py > 89 && PANT_DAT.py < 114)
					{
						mostrarNiveles(UltimoNivel);
						ESTADO = NIVELES;
						delayCambioEstado = DELAY_ESTADO;
					}
					else if (PANT_DAT.py > 128 && PANT_DAT.py < 150)
					{
						visualizarCj();
						ESTADO = TUTORIAL;
						delayCambioEstado = DELAY_ESTADO;
					}
				}
			}
		}
		else if (ESTADO == JUEGO)
		{
			
			DibuajrVidas(vidas);

			if (TeclaDetectada()) //La función manejar entradas se encarga de saber que tecla esta siendo pulsada.
			{
				manejarEntradas(&jugador);
			}
			else
			{
				jugador.velX = 0; // Si no se ha pulsado ninguna tecla, es que el personaje no está moviendo
			}
			
			actualizarPersonaje(&jugador);

			// Lógica de nivel completado
			if (jugador.x >= 240)
			{
				if (NivelActual == UltimoNivel){
					UltimoNivel++;
				}

				NivelActual++;

				if (NivelActual > 3){
					BorrarPepe(0, jugador.x, jugador.y);
					BorrarVidas(vidas);
					cargarNivel(0);
					visualizarWin();
					ESTADO = FINAL;

				}else{
						Seg = 60;
						vidas = 5;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
				}

			}

			// Lógica de muerte
			if (jugador.y > 150)
			{
				BorrarVidas(vidas);
				vidas--;
				inicializarPersonaje(&jugador);
				if (vidas == 0)
				{
					BorrarPepe(0, jugador.x, jugador.y);
					BorrarVidas(vidas);
					cargarNivel(0);
					UltimoNivel = 1;
					NivelActual = 1;
					visualizarFinJuego();

					ESTADO = FINJUEGO;
				}
			}
		}
		else if (ESTADO == FINJUEGO)
		{
			

			// Botones
			if (tocando && delayCambioEstado == 0 &&
				PANT_DAT.px > 100 && PANT_DAT.px < 151 &&
				PANT_DAT.py > 135 && PANT_DAT.py < 151)
			{
				visualizarMenu();
				ESTADO = INICIO;
				delayCambioEstado = DELAY_ESTADO;
			}
		}
		else if (ESTADO == PAUSA)
		{
			//BorrarVidas(vidas); // Borrar los sprites de los corazones
			// int N;				// id del Nivel al que se estaba jugando antes de dar pausa
			
			if (tocando)
			{

				if (PANT_DAT.px > 48 && PANT_DAT.px < 123 && PANT_DAT.py < 138 && PANT_DAT.py > 117)
				{
					// Reanudar
					MostrarPepe(0, jugador.x, jugador.y);
					cargarNivel(NivelActual);

					ESTADO = JUEGO;
				}
				else if (PANT_DAT.px > 133 && PANT_DAT.px < 207 && PANT_DAT.py < 138 && PANT_DAT.py > 117)
				{
					// Menu
					visualizarMenu();
					ESTADO = INICIO;
					delayCambioEstado = DELAY_ESTADO;
				}
			}
		}
		else if (ESTADO == TUTORIAL)
		{
			if (tocando && delayCambioEstado == 0 &&
				PANT_DAT.px > 180 && PANT_DAT.px < 250 &&
				PANT_DAT.py > 160 && PANT_DAT.py < 183)
			{
				visualizarMenu();
				ESTADO = INICIO;
				delayCambioEstado = DELAY_ESTADO;
			}
		}
		else if (ESTADO == NIVELES)
		{
			//Botones para acceder a los niveles desbloqueados:
			switch (UltimoNivel)
			{
			case 1:
				if (tocando)
				{
					if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 37 && PANT_DAT.py < 58)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 1;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
				}
				break;

			case 2:
				if (tocando)
				{
					if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 37 && PANT_DAT.py < 58)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 1;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
					else if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 67 && PANT_DAT.py < 86)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 2;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
				}
				break;

			default:
				if (tocando)
				{
					if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 37 && PANT_DAT.py < 58)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 1;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
					else if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 67 && PANT_DAT.py < 86)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 2;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
					else if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 98 && PANT_DAT.py < 118)
					{
						Niv = 0;
						Seg = 60;
						vidas = 5;
						NivelActual = 3;
						inicializarPersonaje(&jugador);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
					}
				}
				break;
			}

			//Botón de volver
			if (tocando)
			{	
				if (PANT_DAT.px > 97 && PANT_DAT.px < 158 && PANT_DAT.py > 128 && PANT_DAT.py < 147)
				{
					if (Niv) //Si se ha accedido a NIVELES mediante JUEGO, reanuda el nivel
					{
						
						MostrarPepe(0, jugador.x, jugador.y);
						cargarNivel(NivelActual);
						ESTADO = JUEGO;
						Niv = 0;
					}
					else //Si no, carga el menú de inicio
					{
						visualizarMenu();
						ESTADO = INICIO;
						delayCambioEstado = DELAY_ESTADO;
					}
				}
			}
		}
		else if (ESTADO == FINAL)
		{
			
			if (tocando)
			{

				if (PANT_DAT.px > 20 && PANT_DAT.px < 80 && PANT_DAT.py > 150 && PANT_DAT.py < 170)
				{
					// Reiniciar
					UltimoNivel = 1;
					NivelActual = 1;
					visualizarMenu();
					ESTADO = INICIO;
					delayCambioEstado = DELAY_ESTADO;
				}
				else if (PANT_DAT.px > 180 && PANT_DAT.px < 260 && PANT_DAT.py > 150 && PANT_DAT.py < 170)
				{
					// Niveles
					mostrarNiveles(UltimoNivel);
					ESTADO = NIVELES;
					delayCambioEstado = DELAY_ESTADO;
				}
			}
		}

		// Esperar al refresco vertical para que el personaje se mueva de manera fluída
		swiWaitForVBlank();
	}
}

/***********************2024-2025*******************************/
