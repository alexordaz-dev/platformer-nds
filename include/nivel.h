// Curso 2024-2025
/*---------------------------------------------------------------------------------
nivel.h
---------------------------------------------------------------------------------*/

//Estrictura que repesenta la posición de un bloque en el espacio y sus dimensiones.
typedef struct{
	int x, y;
	int anchura, altura;
}Bloques;

//Estructura para almacenar informacion sobre las colisiones de los niveles.
typedef struct {
	Bloques bloq[8]; //Array que guarda los bloques que hay en el nivel.
	int nbloq; //Cantidad de posiciones del array de Bloques que están ocupadas.
}Nivel; 

//Puntero que apunta al nivel en el que se está jugando.
extern Nivel* Ni;

//Para cargar los datos del nivel. Incluidos los fondos, y los sprites de bloques.
extern void cargarNivel(int id);

//Para mostrar los fondos en la transición al estado NIVELES
extern void mostrarNiveles(int n);

/***********************2024-2025*******************************/

