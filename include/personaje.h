// Curso 2024-2025

/*---------------------------------------------------------------------------------
personaje.h
---------------------------------------------------------------------------------*/

#include <nds.h>
//#include <stdbool.h>
#include "definiciones.h"

// Constantes del personaje
#define GRAVEDAD 1
#define VELOCIDAD_SALTO -9
#define VELOCIDAD_MOVIMIENTO 2
#define ANCHO_PERSONAJE 14
#define ALTO_PERSONAJE 16

//Estructura que representa al personaje jugable
typedef struct {
    int x, y; //Posición
    int altura, anchura; //Dimensiones
    int velX, velY; //Velocidad que tiene en dicho instante.
    bool enAire; 
} Personaje;

//Variables que se van a usar en juego.c y rutinasAtención.c
extern Personaje jugador;
extern int vidas;

//Métodos que se emplean en juego.c
extern void inicializarPersonaje(Personaje* personaje);
extern void actualizarPersonaje(Personaje* personaje);
extern void manejarEntradas(Personaje* personaje);

//Métodos para controlar la visualización de las vidas en pantalla.
extern void DibuajrVidas(int v);
extern void BorrarVidas(int v);