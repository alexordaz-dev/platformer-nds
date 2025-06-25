// Curso 2024-2025

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"

u16* gfxpepe;
u16* gfxtierra;
u16* gfxcorazon;


/* Reservar memoria para cada sprite que se quiera mostrar en pantalla */
void memoriaReserva()
{
	/* Por cada sprite que se quiera incluir en la pantalla principal hay que hacer algo equivalente a lo que sigue */
	gfxpepe= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    gfxtierra= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxcorazon= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un píxel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES */
void EstablecerPaletaPrincipal() {
	SPRITE_PALETTE[0] = RGB15(0, 0, 0);        
	SPRITE_PALETTE[1] = RGB15(31, 0, 0);       
	SPRITE_PALETTE[2] = RGB15(31, 31, 0);      
	SPRITE_PALETTE[3] = RGB15(31, 31, 31);     
	SPRITE_PALETTE[4] = RGB15(0, 31, 0);       
	SPRITE_PALETTE[5] = RGB15(0, 0, 31);       
	SPRITE_PALETTE[6] = RGB15(0, 0, 0);        
	SPRITE_PALETTE[7] = RGB15(0, 31, 31);      
	SPRITE_PALETTE[8] = RGB15(31, 0, 31);      
	SPRITE_PALETTE[9] = RGB15(16, 16, 16);     
	SPRITE_PALETTE[10] = RGB15(24, 24, 24);    
	SPRITE_PALETTE[11] = RGB15(8, 8, 8);       
	SPRITE_PALETTE[12] = RGB15(31, 16, 0);     
	SPRITE_PALETTE[13] = RGB15(16, 0, 0);      
	SPRITE_PALETTE[14] = RGB15(20, 10, 0);     
	SPRITE_PALETTE[15] = RGB15(16, 0, 31);     
	SPRITE_PALETTE[16] = RGB15(24, 16, 31);    
	SPRITE_PALETTE[17] = RGB15(31, 20, 28);    
	SPRITE_PALETTE[18] = RGB15(16, 24, 31);    
	SPRITE_PALETTE[19] = RGB15(0, 0, 16);      
	SPRITE_PALETTE[20] = RGB15(0, 31, 16);     
	SPRITE_PALETTE[21] = RGB15(0, 16, 0);      
	SPRITE_PALETTE[22] = RGB15(16, 20, 0);     
	SPRITE_PALETTE[23] = RGB15(24, 31, 16);    
	SPRITE_PALETTE[24] = RGB15(31, 31, 24);    
}

/* Definición de un sprite de 32x32 píxeles para dibujar a pepe */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 16x16 píxeles. Los primeros 256 (16x16) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 256 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho */

u8 pepe[256] = 
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	17	,	0	,	17	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	0	,	17	,	17	,	17	,	0	,	0	,	0	,	0	,	24	,	24	,	24	,	24	,	 //	0	0	0	0	0	17	0	17	0	0	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	24	,	24	,	24	,	0	,	14	,	0	,	0	,	0	,	24	,	24	,	24	,	24	,	 //	0	0	0	0	0	17	17	17	0	0	0	0	0	0	0	0
    0	,	0	,	0	,	15	,	15	,	15	,	15	,	0	,	0	,	0	,	0	,	15	,	15	,	15	,	15	,	15	,	 //	0	0	0	0	24	24	24	24	24	0	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	24	24	24	24	24	0	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	24	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	24	24	24	24	24	0	0	0	0	0	0	0
    24	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	24	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	15	15	15	15	15	15	15	0	0	0	0	0	0
    15	,	15	,	0	,	0	,	0	,	0	,	0	,	0	,	15	,	15	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	15	15	15	15	15	15	15	0	0	0	0	0	0
    0	,	0	,	0	,	24	,	24	,	15	,	15	,	15	,	0	,	0	,	0	,	24	,	24	,	15	,	15	,	15	,	 //	0	0	0	24	24	15	15	15	24	24	0	0	0	0	0	0
    0	,	0	,	0	,	24	,	24	,	19	,	19	,	19	,	0	,	0	,	0	,	0	,	0	,	19	,	19	,	19	,	 //	0	0	0	24	24	15	15	15	24	24	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	0	,	19	,	19	,	19	,	0	,	0	,	0	,	0	,	0	,	19	,	19	,	19	,	 //	0	0	0	24	24	19	19	19	24	24	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	6	,	6	,	0	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	19	19	19	0	0	0	0	0	0	0	0
    24	,	24	,	0	,	0	,	0	,	0	,	0	,	0	,	24	,	24	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	19	19	19	0	0	0	0	0	0	0	0
    24	,	24	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	19	19	19	0	0	0	0	0	0	0	0
    0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	6	6	0	6	6	0	0	0	0	0	0	0
    6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0

};

u8 tierra[256] =
{
	21	,	21	,	21	,	4	,	21	,	21	,	21	,	21	,	21	,	23	,	23	,	23	,	4	,	4	,	4	,	23	,	 //	21	21	21	4	21	21	21	21	21	21	21	4	21	21	21	21
    21	,	4	,	4	,	4	,	4	,	21	,	4	,	4	,	21	,	4	,	4	,	4	,	4	,	4	,	4	,	4	,	 //	21	23	23	23	4	4	4	23	4	4	4	4	4	4	23	21
    4	,	4	,	21	,	4	,	23	,	23	,	23	,	0	,	14	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	 //	21	4	4	4	4	21	4	4	4	23	23	23	4	4	4	4
    21	,	21	,	4	,	21	,	21	,	21	,	21	,	0	,	0	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	 //	21	4	4	4	4	4	4	4	4	4	4	4	21	23	23	21
    21	,	21	,	21	,	4	,	21	,	21	,	21	,	0	,	0	,	4	,	4	,	4	,	4	,	4	,	23	,	21	,	 //	4	4	21	4	23	23	23	4	4	21	4	4	4	4	4	21
    4	,	23	,	23	,	23	,	4	,	4	,	4	,	4	,	4	,	4	,	4	,	4	,	21	,	23	,	23	,	21	,	 //	21	21	21	21	21	21	21	21	21	21	21	21	21	21	21	21
    4	,	21	,	4	,	4	,	4	,	4	,	4	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	 //	21	21	4	21	21	21	21	4	21	21	21	21	4	21	21	21
    21	,	21	,	21	,	21	,	4	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	21	,	 //	21	21	21	21	21	21	21	21	21	21	21	21	21	21	21	21
    22	,	22	,	22	,	22	,	21	,	22	,	22	,	22	,	22	,	22	,	21	,	22	,	22	,	22	,	21	,	22	,	 //	22	22	22	22	21	22	22	22	22	21	22	22	22	22	21	22
    22	,	22	,	22	,	14	,	22	,	22	,	22	,	14	,	14	,	14	,	14	,	14	,	22	,	14	,	14	,	14	,	 //	22	22	21	22	22	22	21	22	22	22	22	21	22	22	21	22
    14	,	14	,	22	,	14	,	14	,	14	,	14	,	22	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	 //	22	22	22	14	22	22	22	14	22	22	22	14	22	22	22	14
    14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	 //	14	14	14	14	22	14	14	14	14	22	14	14	14	14	22	14
    22	,	21	,	22	,	22	,	22	,	22	,	21	,	22	,	22	,	22	,	22	,	21	,	22	,	22	,	21	,	22	,	 //	14	14	22	14	14	14	14	22	14	14	14	22	14	14	14	14
    22	,	22	,	22	,	14	,	22	,	22	,	22	,	14	,	14	,	22	,	14	,	14	,	14	,	14	,	22	,	14	,	 //	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14
    14	,	14	,	14	,	22	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	 //	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14
    14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	14	,	 //	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14	14
};

u8 corazon[256] =
{
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
	0	,	0	,	0	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	1	,	3	,	3	,	1	,	1	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
	0	,	1	,	1	,	3	,	1	,	1	,	1	,	0	,	14	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	 //	0	0	0	1	1	1	0	0	0	1	1	1	0	0	0	0
	0	,	1	,	1	,	3	,	1	,	1	,	1	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	1	,	 //	0	0	1	3	3	1	1	0	1	1	1	1	1	0	0	0
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	1	1	3	1	1	1	1	1	1	1	1	1	1	0	0
	0	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	0	,	 //	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0
	1	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	 //	0	1	1	3	1	1	1	1	1	1	1	1	1	1	0	0
	1	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	0	,	 //	0	0	1	1	1	1	1	1	1	1	1	1	1	0	0	0
	0	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	 //	0	0	0	1	1	1	1	1	1	1	1	1	0	0	0	0
	0	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	1	,	 //	0	0	0	0	1	1	1	1	1	1	1	0	0	0	0	0
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	1	1	1	1	1	0	0	0	0	0	0
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	1	1	1	0	0	0	0	0	0	0
	1	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	1	,	1	,	1	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	1	0	0	0	0	0	0	0	0
	1	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 //	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
	
};


/* Carga en memoria cada uno de los sprites que hemos dibujado */

void GuardarSpritesMemoria(){ 
	
int i;
	//sprite de 32*32
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxpepe[i] = pepe[i*2] | (pepe[(i*2)+1]<<8);
		gfxtierra[i] = tierra[i*2] | (tierra[(i*2)+1]<<8);
		gfxcorazon[i] = corazon[i*2] | (corazon[(i*2)+1]<<8);				
	}
	
}

/* Esta función dibuja un personaje en la posición x, y de pantalla. A cada rombo que se quiera mostrar en pantalla se le debe asignar un índice distinto, un valor entre 0 y 126 */

void MostrarPepe(int indice, int x, int y)
{ 
 
oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxpepe,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		false,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el personaje con el índice indicado */
void BorrarPepe(int indice, int x, int y)
{

oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxpepe,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		true,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
oamUpdate(&oamMain); 

}

void MostrarTierra(int indice, int x, int y)
{ 
 
oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxtierra,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		false,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el personaje con el índice indicado */
void BorrarTierra(int indice, int x, int y)
{

oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxtierra,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		true,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
oamUpdate(&oamMain); 

}

void MostrarCorazon(int indice, int x, int y)
{ 
 
oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcorazon,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		false,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el personaje con el índice indicado */
void BorrarCorazon(int indice, int x, int y)
{

oamSet(&oamMain, // main graphics engine context
		indice,           // oam index (0 to 127)  
		x, y,   // x and y pixel location of the sprite
		0,                    // priority, lower renders last (on top)
		0,					  // this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxcorazon,// +32*32/2,                  // pointer to the loaded graphics
		-1,                  // sprite rotation data  
		false,               // double the size when rotating?
		true,			// hide the sprite?
		false, false, // vflip, hflip
		false	// apply mosaic
		); 
oamUpdate(&oamMain); 

}
/***********************2024-2025*******************************/


