// Curso 2024-2025

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "Puerta.h"
#include "PuertaAbierta.h"
#include "Fondo.h"
#include "Menu.h"
#include "FinJuego.h"
#include "Pausa.h"
#include "Cj.h"
#include "Niveles1.h"
#include "Niveles2.h"
#include "Niveles3.h"
#include "N1.h"
#include "N2.h"
#include "N3.h"
#include "Win.h"

/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

// void visualizarPuerta() {
// 	dmaCopyHalfWords(DMA_CHANNEL,
//         PuertaBitmap, // Variable que se genera automáticamente 
//         (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
//         PuertaBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
// }

// void visualizarPuertaAbierta() {
		
//     dmaCopyHalfWords(DMA_CHANNEL,
//         PuertaAbiertaBitmap, // Variable que se genera automáticamente 
//         (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
//         PuertaAbiertaBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
// }

void visualizarFondo() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        FondoBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        FondoBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarMenu() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        MenuBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        MenuBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarFinJuego() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        FinJuegoBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        FinJuegoBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarPausa() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        PausaBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        PausaBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarCj() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        CjBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        CjBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarNiveles1() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        Niveles1Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        Niveles1BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarNiveles2() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        Niveles2Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        Niveles2BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}
void visualizarNiveles3() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        Niveles3Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        Niveles3BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarN1() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        N1Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        N1BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarN2() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        N2Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        N2BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarN3() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        N3Bitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        N3BitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarWin() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
        WinBitmap, // Variable que se genera automáticamente 
        (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
        WinBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

/***********************2024-2025*******************************/

