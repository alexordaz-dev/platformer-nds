//Curso 2024-2025

/*-------------------------------------
nivel.c
-------------------------------------*/

#include "nivel.h"
#include "fondos.h"
#include "definiciones.h"
#include "sprites.h"

// Niveles:
Nivel N0 = {0,{{0}}, 0}; // Nivel por defecto, Nivel vacío

// Convención: Los dos primeros Bloques de bloq[] representan el suelo de los extremos del nivel.
Nivel N1 = {{{0, 191, 30, 95}, {224, 191, 29, 95}, {60, 90, 14, 16}, {90, 120, 14, 16}, {120, 90, 14, 16}, {150, 120, 14, 16}, {180, 90, 14, 16}}, 7};

Nivel N2 = {{{0, 191, 30, 95}, {224, 191, 29, 95}, {65, 110, 14, 16}, {95, 95, 14, 16}, {140, 80, 14, 16}, {185, 104, 14, 16}}, 6};

Nivel N3 = {{{0, 191, 30, 95}, {224, 191, 29, 95}, {62, 88, 15, 16}, {110, 115, 15, 16}, {145, 90, 15, 16}, {170, 65, 15, 16}}, 6};

Nivel *Ni = &N0; // Para inicializar el puntero.


//Muestra los bloques que tenga el nivel al que apunta Ni. 
void mostrarBloques()
{

	int i;
	// Niv.bloq[] se recorre desde la posición 2, ya que los dos primeros están incluidos en el fondo.
	for (i = 2; i < Ni->nbloq; i++)
	{
		MostrarTierra(i - 1, Ni->bloq[i].x, Ni->bloq[i].y); // muestra todos los bloques que tiene el nivel
															// el id empieza en 1 porque el 0 es el jugador.
	}
}

//Elimina de pantalla los bloques del nivel al que paunta Ni.
void ocultarBloques() {
    // Verificar si hay bloques para ocultar
    if (Ni->nbloq <= 2) return;
    
    // Ocultar todos los bloques (empezando desde el índice 2)
	int i;
    for (i = 2; i < Ni->nbloq; i++) {
        BorrarTierra(i - 1, Ni->bloq[i].x, Ni->bloq[i].y);
    }
}

//Carga en pantalla la información del nivel que se indique en el parámetro id. Está información es su fondo y bloques.
//Si id == 0, entonces elimina de pantalla los bloques y hace que Ni apunte a N0.
extern void cargarNivel(int id) {
    // Primero ocultar bloques del nivel actual
    ocultarBloques();
    
    switch (id) {
        case 0: // Nivel vacío
            Ni = &N0;
            break;
            
        case 1: // Nivel 1
            visualizarN1();
            Ni = &N1;
            mostrarBloques();
            break;

        case 2: // Nivel 2
            visualizarN2();
            Ni = &N2;
            mostrarBloques();
            break;

        case 3: // Nivel 3
            visualizarN3();
            Ni = &N3;
            mostrarBloques();
            break;
            
        default:
            Ni = &N0; // Por defecto, nivel vacío
            break;
    }
}

//Muestra el fondo con la cantidad de niveles especificada en n
void mostrarNiveles(int n){
    switch (n)
			{                         //Nombres de los fondos:
			case 1:
				visualizarNiveles1(); //N1
				break;
			case 2:
				visualizarNiveles2(); //N2
				break;

			default:
				visualizarNiveles3(); //N3
				break;
			}
}
