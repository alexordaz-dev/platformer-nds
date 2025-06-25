// Curso 2024-2025

/*---------------------------------------------------------------------------------
personaje.c
---------------------------------------------------------------------------------*/

#include "personaje.h" // en personaje.h está incluido niveles.h también
#include "perifericos.h"
#include "nivel.h"
#include "sprites.h"
#include <stdbool.h> //para usar booleanos

int vidas = 5; //Vidas con las que se comienza

// Inicializar personaje junto su sprite.
void inicializarPersonaje(Personaje *personaje)
{
    // Posición inicial: a la izquierda de la pantalla
    personaje->x = 10;
    personaje->y = 70;

    // Dimensiones
    personaje->altura = ALTO_PERSONAJE;
    personaje->anchura = ANCHO_PERSONAJE;

    // Velocidades
    personaje->velX = 0;
    personaje->velY = 0;

    // Estados
    personaje->enAire = false;

    // Mostrar sprite inicial
    MostrarPepe(0, personaje->x, personaje->y);
}

//Comprueba si personaje está colisionando con bloque, tanto horizontal como verticalmente.
bool hayColision(Personaje *personaje, Bloques *bloque)
{                                                             
    return ((personaje->x < bloque->x + bloque->anchura &&     // por la derecha
             personaje->x + personaje->anchura > bloque->x) && // por izquierda
            (personaje->y > bloque->y - bloque->altura &&      // por arriba
             personaje->y - personaje->altura < bloque->y));   // por abajo
}

//resuelve la colisión vertical que tenga jugador con bloque a lo largo del eje Y.
void resolverColisionVertical(Personaje *jugador, Bloques *bloque)
{
    if (jugador->velY > 0)
    {
        // Cayendo desde arriba
        jugador->y = bloque->y - bloque->altura;
        jugador->velY = 0;
        jugador->enAire = false;
    }
    else if (jugador->velY < 0)
    {
        // Subiendo desde abajo
        jugador->y = bloque->y + jugador->altura;
        jugador->velY = 0;
    }
}


//Resuelve la colisión que tenga jugador con bloque a lo largo del eje X.
void resolverColisionHorizontal(Personaje *jugador, Bloques *bloque)
{

    if (jugador->velX > 0)
    {
        // Moviéndose hacia la derecha
        jugador->x = bloque->x - jugador->anchura;
        jugador->velX = 0;
    }
    else if (jugador->velX < 0)
    {
        // Moviéndose hacia la izquierda
        jugador->x = bloque->x + bloque->anchura;
        jugador->velX = 0;
    }
}

//Aplica la gravedad al personaje si procede, es decir, si está en el aire.
void caer(Personaje *personaje)
{
    if (personaje->enAire)
    {
        personaje->velY += GRAVEDAD;
    }
}

//Actualiza la y del personaje en función de velY.
void actualizarY(Personaje *personaje)
{
    personaje->y += personaje->velY;

    // Detectar colisiones:
    bool collided = false;
    int i = 0;
    while (i < Ni->nbloq) //Se comprueba la colisión con cada bloque del nivel actual.
    {
        if (hayColision(personaje, &Ni->bloq[i]))
        {
            resolverColisionVertical(personaje, &Ni->bloq[i]);
            collided = true;
        }
        if (!collided)
        {
            //Si no está colisionando con ningún bloque a lo largo del eje Y, es porue no tiene ninguno bajo sus pies.
            personaje->enAire = true;
        }
        i++;
    }
}

//Actualiza la x del personaje en función de velX.
void actualizarX(Personaje *personaje)
{
    personaje->x += personaje->velX;

    int i = 0;

    //detectar colisiones:
    while (i < Ni->nbloq) //Se comprueba la colisión con cada bloque del nivel actual.
    {
        if (hayColision(personaje, &Ni->bloq[i]))
        {
            resolverColisionHorizontal(personaje, &Ni->bloq[i]);
        }
        i++;
    }
}

// Actualizar física y sprite del personaje
void actualizarPersonaje(Personaje *personaje)
{

    // Aplica la gravedad si está en el aire.
    caer(personaje);

    // Actualizar posición Y
    actualizarY(personaje);

    // Actualizar posición x
    actualizarX(personaje);

    // Limitar bordes de pantalla, para que no se salga en los bordes.
    if (personaje->x < 0)
        personaje->x = 0;
    if (personaje->x > SCREEN_WIDTH - personaje->anchura)
        personaje->x = SCREEN_WIDTH - personaje->anchura;

    // Actualizar sprite en nueva posición
    MostrarPepe(0, personaje->x, personaje->y);
}

// Manejar entrada del jugador. Precondición: se está pulsando una tecla.
void manejarEntradas(Personaje *personaje)
{

        int tecla = TeclaPulsada();

        if (tecla == IZQUIERDA)
        {
            personaje->velX = -VELOCIDAD_MOVIMIENTO;
        }
        else if (tecla == DERECHA)
        {
            personaje->velX = VELOCIDAD_MOVIMIENTO;
        }
        else if (tecla == B)
        {
            // Solo puede saltar si no está ya en el aire
            if (!personaje->enAire)
            {
                personaje->velY = VELOCIDAD_SALTO;
                personaje->enAire = true;
            }
        }
}

// Lógica de los Sprites de las vidas
void DibuajrVidas(int v){
            int i;
			for (i = 0; i < v; i++)
			{
				MostrarCorazon(i + 10, 154 + 20 * i, 35); //Empieza con el id 11 para que no inerfiera con los otros sprites.
            }

}

//Usada para elimianr los sprites de corazones.
void BorrarVidas(int v)
{
	int j;
	for (j = 0; j < v; j++)
	{
		BorrarCorazon(j + 10, 154 + 20 * j, 35);
	}
}