// Curso 2024-2025

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;
extern u16* gfxpepe;
extern u16* gfxtierra;
extern u16* gfxcorazon;

extern void memoriaReserva();

extern void EstablecerPaletaPrincipal();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */

// extern void EstablecerPaletaSecundaria();
/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */

extern void GuardarSpritesMemoria();
/* Carga en memoria los Sprites dibujados */

extern void MostrarPepe(int indice, int x, int y);
/* Esta función dibuja el personaje en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */

extern void BorrarPepe(int indice, int x, int y);
/* Esta función borra de la pantalla el personaje con el índice que se le indique como parámetro */

extern void MostrarTierra(int indice, int x, int y);
/* Esta función muestra el bloque de tierra*/

extern void BorrarTierra(int indice, int x, int y);
/* Esta función borra el bloque de tierra*/

extern void MostrarCorazon(int indice, int x, int y);
/* Esta función muestra el bloque de tierra*/

extern void BorrarCorazon(int indice, int x, int y);
/* Esta función borra el bloque de tierra*/

/***********************2024-2025*******************************/

