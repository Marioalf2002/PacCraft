//**************************************************************************************//
// 					Plantilla Proyecto Vacio C++ v2.0 26/10/2022					    //
//**************************************************************************************//
//																						//
//	General		>	Dir Salida			> $(SolutionDir)\Bin							//
//				>	Dir Intermedio		> $(SolutionDir)\Tmp							//
//				>	Nomb Destino		> $(ProjectName)			(Release / 64)		//
//				>	Nomb Destino		> $(ProjectName)_d			(Debug / 64)		//
//				>	Nomb Destino		> $(ProjectName)_32			(Release / 32)		//
//				>	Nomb Destino		> $(ProjectName)_32d		(Debug / 32)		//
//																						//
//	Avanzado	>	Juego de Caract		> Multibyte										//
//	C/C++		>	General				> Comp Multiproc		> Si					//
//				>	Optimizacion		> Tamaño o velocidad	> Codigo Rapido			//
//				>	Gen de Codigo		> Bit en tiempo de ej.	> MT (Release)			//
//				>						> Bit en tiempo de ej.	> MTd (Debug)			//
//				>						> Modelo de punt fl		> Rapido				//
//				>	Idioma				> Estandar del Leng.	> Ultimo Borrador		//
//																						//
//	Allegro		>	Add-Ons				> Image Addon			> Si					//
//				>						> Truetype Font Addon	> Si					//
//				>						> Primitives Addon		> Si					//
//				>						> Audio Addon			> Si					//
//				>						> Audio Codec Addon		> Si					//
//				>						> Dialog Addon			> Si					//
//				>						> Font Addon			> Si					//
//				>						> Color Addon			> Si					//
//																						//
//**************************************************************************************//

#include <iostream>
#include <cstdlib>													//Libreria que habilita mas funciones especiales
#include <locale.h>													//Libreria que contiene la funcion setlocale
#include <Windows.h>												//Libreria para medidas de pantalla

#include <allegro5/allegro.h>										//Libreria base de Allegro
#include <allegro5/allegro_image.h>									//Libreria para implementar Imagenes
#include <allegro5/allegro_primitives.h>							//Libreria para primitivas
#include <allegro5/allegro_color.h>									//Libreria para implementar Colores
#include <allegro5/allegro_audio.h>									//Libreria para sonido
#include <allegro5/allegro_acodec.h>								//Libreria extra para sonido 
#include <allegro5/allegro_font.h>									//Libreria para Fuentes de Texto
#include <allegro5/allegro_ttf.h>									//Libreria para tipo archivo de Fonts
#include <allegro5/allegro_native_dialog.h>							//Libreria para mensajes nativos

#define MAXFIL 21													//EJE Y DEL MAPA
#define MAXCOL 31													//EJE X DEL MAPA

using namespace std;												//Evitamos escribir std al utilizar la biblioteca/Libreria standard

ALLEGRO_DISPLAY* ventana;											//Variable que contiene al Ventana
ALLEGRO_BITMAP* menu_null;											//Variable que contiene imagen Menu Inicial
ALLEGRO_BITMAP* menu_play;											//Variable que contiene imagen Menu Play
ALLEGRO_BITMAP* menu_salir;											//Variable que contiene imagen Menu Salir

ALLEGRO_BITMAP* modos;												//Variable que contiene imagen Menu Dificultades
ALLEGRO_BITMAP* modo_facil;											//Variable que contiene imagen Menu Dificultades Facil
ALLEGRO_BITMAP* modo_medio;											//Variable que contiene imagen Menu Dificultades Medio
ALLEGRO_BITMAP* modo_dificil;										//Variable que contiene imagen Menu Dificultades Dificil
ALLEGRO_EVENT_QUEUE* event_queue;									//Variable para contener eventos
ALLEGRO_EVENT_QUEUE* event_queue_teclado;							//Variable para contener eventos

ALLEGRO_BITMAP* roca;												//Variable que contiene Textura Roca
ALLEGRO_BITMAP* netherrack;											//Variable que contiene Textura Netherrack
ALLEGRO_BITMAP* endstone;											//Variable que contiene Textura End Stone

ALLEGRO_BITMAP* diamante;											//Variable que contiene Textura Diamante
ALLEGRO_BITMAP* netherite;											//Variable que contiene Textura Netherite
ALLEGRO_BITMAP* enderperl;											//Variable que contiene Textura Enderperl

ALLEGRO_BITMAP* cueva;												//Fondo del Cueva
ALLEGRO_BITMAP* nether;												//Fondo del Nether
ALLEGRO_BITMAP* endcity;											//Fondo del End City

ALLEGRO_BITMAP* steve;												//Personaje
ALLEGRO_BITMAP* stevebmp;											//Imagen del personaje Derecha
ALLEGRO_BITMAP* muertesteve;										//Imagen muerte

ALLEGRO_BITMAP* zombie;												//Imagen del Zombie
ALLEGRO_BITMAP* esqueleto;											//Imagen del Esqueleto
ALLEGRO_BITMAP* creeper;											//Imagen del Creeper
ALLEGRO_BITMAP* arana;												//Imagen del Araña

ALLEGRO_BITMAP* whither;											//Imagen del Whiter
ALLEGRO_BITMAP* piglin;												//Imagen del Piglin
ALLEGRO_BITMAP* zombipiglin;										//Imagen del ZombiPiglin
ALLEGRO_BITMAP* blaze;												//Imagen del Blaze

ALLEGRO_BITMAP* enderman;											//Imagen del Enderman
ALLEGRO_BITMAP* dragon;												//Imagen del Dragon


int px = 30 * 14, py = 30 * 17;										//Posicion del Personaje
int antpx, antpy;													//Posicion anterior del Personaje

int zy = 30 * 1, zx = 30 * 1;										//Posicion del Zombie
int ey = 30 * 10, ex = 30 * 5;										//Posicion del Esqueleto
int cy = 30 * 1, cx = 30 * 25;										//Posicion del Creeper
int ary = 30 * 9, arx = 30 * 25;									//Posicion del Araña
int wy = 30 * 1, wx = 30 * 1;										//Posicion del Whither
int zpy = 30 * 10, zpx = 30 * 5;									//Posicion del Zombie Piglin
int piy = 30 * 1, pix = 30 * 25;									//Posicion del Piglin
int by = 30 * 9, bx = 30 * 25;										//Posicion del Blaze
int eny = 30 * 1, enx = 30 * 1;										//Posicion del Enderman
int eny2 = 30 * 10, enx2 = 30 * 5;									//Posicion del Enderman 2
int eny3 = 30 * 1, enx3 = 30 * 25;									//Posicion del Enderman 3
int eny4 = 30 * 9, enx4 = 30 * 25;									//Posicion del Enderman 4
int dy = 30 * 9, dx = 30 * 14;										//Posicion del Dragon

int jugarfacil();													//Inicio de Funcion de Juego Facil
int jugarmedio();													//Inicio de Funcion de Juego Medio
int jugardificil();													//Inicio de Funcion de Juego Dificil
int dificultad();													//Inicio de Funcion de Menu Dificultades

//MAPA DEL JUEGO
char facil[MAXFIL][MAXCOL] = {
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X           XXXXXX           X",
		"X XXX XXXXX oooooo XXXXX XXX X",
		"X ooo     X XXXXXX XX    ooo X",
		"X XXX XX     XXXX     XX XXX X",
		"X XXX XX      XX      XX XXX X",
		"X ooo XX XXXX oo XXXX XX ooo X",
		"X XXX XX XXXX oo XXXX XX XXX X",
		"X XXX XX XXXX oo XXXX XX XXX X",
		" |ooo XX     XXXX     XX ooo| ",
		"X XXX XX X XXXXXXXX X XX XXX X",
		"X XXX XX X XXXXXXXX X XX XXX X",
		"X XXX XX X XXooooXX X XX XXX X",
		"X ooo XX      XX      XX ooo X",
		"X XXX XXXXXX XXXX XXXXXX XXX X",
		"X XXX XX     XXXX     XX XXX X",
		"X XXX XX XXXXXXXXXXXX XX XXX X",
		"X XXX                    XXX X",
		"X oooooooo  XXXXXX  oooooooo X",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

char medio[MAXFIL][MAXCOL] = {

		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X  o    o   XXXXXX   o    o  X",
		"X XXX XX XX        XX XX XXX X",
		"X XXX XX XX XXXXXX XX XX XXX X",
		"X      o o   o  o   o o      X",
		"XoXXXoXX XXX XXXX XXX XXoXXXoX",
		"X     XX     XXXX     XX     X",
		"XoXXXoXXXXXX XXXX XXXXXXoXXXoX",
		"X XXX o  ooo      ooo  o XXX X",
		" |    XX XXXX XX XXXX XX    | ",
		"X XXXoXX XXXX XX XXXX XXoXXX X",
		"XoXXXo   ooo      ooo   oXXXoX",
		"X XXXoXXXXXX XXXX XXXXXXoXXX X",
		"X     XX     XXXX     XX     X",
		"X XXXoXX XXXXXXXXXXXX XXoXXX X",
		"XoXXX  o   o o o o o  o  XXXoX",
		"X XXXoXXXX XXXXXXXXX XXX XXX X",
		"XoXXXoXXXX           XXX XXXoX",
		"X  o  o o  XXXXXXXXX o o  o  X",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

char dificil[MAXFIL][MAXCOL] = {
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X oooooooooooooooooooooooooo X",
		"X X   X X X X XX X X X X   X X",
		"X             oo             X",
		"X X   X X X X XX X X X X   X X",
		"X     oooooooooooooooooo     X",
		"X X   X X X X XX X X X X   X X",
		"X       X   X oo X   X       X",
		"X X   X X X X XX X X X X   X X",
		" |oooooooooooooooooooooooooo| ",
		"X X   X X X X XX X X X X   X X",
		"X       X   X oo X   X       X",
		"X       X   X oo X   X       X",
		"X X   X X X X XX X X X X   X X",
		"X     oooooooooooooooooo     X",
		"X X   X X X X XX X X X X   X X",
		"X             XX             X",
		"X X   X X X X    X X X X   X X",
		"X oooooooooooooooooooooooooo X",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

//PROGAMA INICIAL
int main()
{
	//IDIOMA QUE SE USARA
	setlocale(LC_ALL, "");											// Uso de la funcion setlocale detecta el idioma del sistema operativo del dispositivo donde se ejecuta.
	setlocale(LC_ALL, "spanish");									// Por defecto se usara el idioma establecido "spanish".

	//INICIALIZAMOS ALLEGRO
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 404", "No se pudo cargar correctamente la libreria Allegro 5", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}

	//INICIALIZAMOS LIBRERIAS
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_mouse();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();

	//DAMOS VALORES A LAS VARIABLES CREADAS AL INCIO
	//VENTANA
	ventana = al_create_display(900, 600);

	//TEXTURA MUROS
	roca = al_load_bitmap("img/roca.png");
	netherrack = al_load_bitmap("img/netherrack.png");
	endstone = al_load_bitmap("img/endstone.png");
	
	//TEXTURA ITEMS
	diamante = al_load_bitmap("img/diamante.png");
	netherite = al_load_bitmap("img/netherite.png");
	enderperl = al_load_bitmap("img/enderperl.png");
	
	//TEXTURA FONDO
	cueva = al_load_bitmap("img/cueva.png");
	nether = al_load_bitmap("img/nether.png");
	endcity = al_load_bitmap("img/endcity.png");
	
	//TEXTURA PERSONAJE
	steve = al_create_bitmap(33, 33);
	stevebmp = al_load_bitmap("img/steve1.png");
	muertesteve = al_load_bitmap("img/muerte2.png");

	//TEXRURA ENEMIGOS
	zombie = al_load_bitmap("img/zombie.png");
	esqueleto = al_load_bitmap("img/esqueleto.png");
	creeper = al_load_bitmap("img/creeper.png");
	arana = al_load_bitmap("img/arana.png");
	whither = al_load_bitmap("img/wither.png");
	piglin = al_load_bitmap("img/piglin.png");
	zombipiglin = al_load_bitmap("img/zombiepiglin.png");
	blaze = al_load_bitmap("img/blaze.png");
	enderman = al_load_bitmap("img/enderman.png");
	dragon = al_load_bitmap("img/dragon.png");

	//CREAMOS EL TIPO DE LETRA CON TAMAÑO
	ALLEGRO_FONT* font = al_load_font("fonts/Minecraft.ttf", 70, 0);

	//SOLICITAMOS MEDIDAS DE LA PANTALLA
	int ANCHO = GetSystemMetrics(SM_CXSCREEN);
	int ALTO = GetSystemMetrics(SM_CYSCREEN);

	//DAMOS NOMBRE A LA VENTANA Y POSICION
	al_set_window_title(ventana, "PacCraft");
	al_set_window_position(ventana, ((ANCHO / 2) - (800 / 2)), ((ALTO / 2) - (600 / 2)));

	//CREAMOS DECTOR DE EVENTOS
	event_queue = al_create_event_queue();
	event_queue_teclado = al_create_event_queue();

	//REGISTRO DE EVENTOS
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue_teclado, al_get_keyboard_event_source());

	//MENUS INICIAL
	menu_null = al_load_bitmap("menu/menu.png");
	menu_play = al_load_bitmap("menu/play.png");
	menu_salir = al_load_bitmap("menu/salir.png");

	//VARIABLES QUE CONTENDRAN POSICION DE MOUSE Y CLICKS
	int x = -1, y = -1;
	int botones[] = { 0 };

	//CREAMOS VARIABLES DE SONIDO MENU
	ALLEGRO_SAMPLE* menu = al_load_sample("sound/musica.wav");
	al_reserve_samples(1);

	//ACTIVAMOS MUSICA DE MENU
	al_play_sample(menu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL PROGRAMA ACTIVO "MENU"
	while (!GetAsyncKeyState(VK_ESCAPE))							//Para cerrar el Programa se espera la señal de tecla "ESC"
	{
		ALLEGRO_EVENT Evento;										//Variable que llevara el Evento a registrar
		al_wait_for_event(event_queue, &Evento);

		al_clear_to_color(al_map_rgb(0, 0, 0));						//Limpiamos todo color que tengamos para liberar memoria

		//VALIDAMOS CLICK PARA ACTIVAR MENU DEPENDIENDO UBICACION DEL PUNTERO
		if (botones[0] == 0) {
			al_draw_bitmap(menu_null, 0, 0, 0);						//Pintamos lo que contenga la variable "menu_null"

		}
		else if (botones[0] == 1)
		{
			al_draw_bitmap(menu_play, 0, 0, 0);						//Pintamos lo que contenga la variable "menu_play"
		}
		else
		{
			al_draw_bitmap(menu_salir, 0, 0, 0);					//Pintamos lo que contenga la variable "menu_salir"
		}

		//CONDICIONES PARA CONTROLAR LA UBICACION DEL MOUSE
		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			x = Evento.mouse.x;
			y = Evento.mouse.y;

			//POSICION CUANDO EL PUNTERO ESTE DENTRO DEL RECUADRO DE "INICIAR"
			if (x >= 586 && x <= 824 && y >= 262 && y <= 325)
			{
				botones[0] = 1;
				if (Evento.mouse.button & 1)
				{
					//LIBERAMOS MEMORIA DE SONIDO
					al_destroy_sample(menu);

					//EJECUTAMOS FUNCION QUE CONTIENE EL JUEGO
					dificultad();
				}
			}
			//POSICION CUANDO EL PUNTERO ESTE DENTRO DEL RECUADRO DE "SALIR"
			else if (x >= 585 && x <= 818 && y >= 354 && y <= 416)
			{
				botones[0] = 2;
				if (Evento.mouse.button & 1)
				{
					return 1;
				}
			}
			//POSICION CUANDO EL PUNTERO ESTE FUERA DE "INICIAR" Y "SALIR"
			else
			{
				botones[0] = 0;
			}
		}

		//SIEMPRE COLOCAR PARA QUE SE PUEDA PINTAR TODO LO QUE SOLICITEMOS
		al_flip_display();
	}
	return 0;
}

//MENU DE DIFICULTADES
int dificultad()
{
	//MENUS DIFICULTADES
	modos = al_load_bitmap("menu/modo.png");
	modo_facil = al_load_bitmap("menu/facil.png");
	modo_medio = al_load_bitmap("menu/medio.png");
	modo_dificil = al_load_bitmap("menu/dificil.png");

	//VARIABLES QUE CONTENDRAN POSICION DE MOUSE Y CLICKS
	int x = -1, y = -1;
	int botones[] = { 0 };

	//CREAMOS VARIABLES DE SONIDO MENU
	ALLEGRO_SAMPLE* menu = al_load_sample("sound/musicad.wav");
	al_reserve_samples(1);

	//ACTIVAMOS MUSICA DE MENU
	al_play_sample(menu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL PROGRAMA ACTIVO "MENU"
	while (!GetAsyncKeyState(VK_ESCAPE))							//Para cerrar el Programa se espera la señal de tecla "ESC"
	{
		ALLEGRO_EVENT Evento;										//Variable que llevara el Evento a registrar
		al_wait_for_event(event_queue, &Evento);

		al_clear_to_color(al_map_rgb(0, 0, 0));						//Limpiamos todo color que tengamos para liberar memoria

		//VALIDAMOS CLICK PARA ACTIVAR MENU DEPENDIENDO UBICACION DEL PUNTERO
		if (botones[0] == 0) {
			al_draw_bitmap(modos, 0, 0, 0);							//Pintamos lo que contenga la variable "modos"
		}
		else if (botones[0] == 1)
		{
			al_draw_bitmap(modo_facil, 0, 0, 0);					//Pintamos lo que contenga la variable "modo_facil"
		}
		else if (botones[0] == 2)
		{
			al_draw_bitmap(modo_medio, 0, 0, 0);					//Pintamos lo que contenga la variable "modo_medio"
		}
		else if (botones[0] == 3)
		{
			al_draw_bitmap(modo_dificil, 0, 0, 0);					//Pintamos lo que contenga la variable "modo_dificil"
		}

		//CONDICIONES PARA CONTROLAR LA UBICACION DEL MOUSE
		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			x = Evento.mouse.x;
			y = Evento.mouse.y;

			//POSICION CUANDO EL PUNTERO ESTE DENTRO DEL RECUADRO DE FACIL
			if (x >= 610 && x <= 785 && y >= 253 && y <= 309)
			{
				botones[0] = 1;
				if (Evento.mouse.button & 1)
				{
					//LIBERAMOS MEMORIA DE SONIDO
					al_destroy_sample(menu);

					//EJECUTAMOS FUNCION QUE CONTIENE EL JUEGO
					jugarfacil();
					
				}
			}

			//POSICION CUANDO EL PUNTERO ESTE DENTRO DEL RECUADRO DE MEDIO
			else if (x >= 569 && x <= 829 && y >= 330 && y <= 390)
			{
				botones[0] = 2;
				if (Evento.mouse.button & 1)
				{
					//LIBERAMOS MEMORIA DE SONIDO
					al_destroy_sample(menu);

					//EJECUTAMOS FUNCION QUE CONTIENE EL JUEGO
					jugarmedio();
				}
			}

			//POSICION CUANDO EL PUNTERO ESTE DENTRO DEL RECUADRO DE DIFICIL
			else if (x >= 511 && x <= 878 && y >= 406 && y <= 466)
			{
				botones[0] = 3;
				if (Evento.mouse.button & 1)
				{
					//LIBERAMOS MEMORIA DE SONIDO
					al_destroy_sample(menu);

					//EJECUTAMOS FUNCION QUE CONTIENE EL JUEGO
					jugardificil();
				}
			}

			//POSICION CUANDO EL PUNTERO ESTE FUERA DEL LAS OPCIONES
			else
			{
				botones[0] = 0;
			}
		}

		//SIEMPRE COLOCAR PARA QUE SE PUEDA PINTAR TODO LO QUE SOLICITEMOS
		al_flip_display();

	}

	return 1;
}

//DIBUJADO DE MAPA FACIL
void mapa_facil() {
	int row, col;

	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* comida = al_load_sample("sound/coin.wav");
	al_reserve_samples(20);

	//FONDO DE JUEGO
	al_draw_bitmap(cueva, 0, 0, 0);

	//CICLO QUE PINTARA LAS ROCAS EN LA POSICION DE LAS "X" Y MANZANAS EN LA POSICION DE LAS "o"
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (facil[row][col] == 'X')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(roca, col * 30, row * 30, 0);
			}
			else if (facil[row][col] == 'o')
			{
				//PINTAMOS COMIDA
				al_draw_bitmap(diamante, col * 30, row * 30, 0);
				if ((py / 30 == row) && (px / 30 == col))
				{
					//ACTIVAMOS MUSICA DE COMIDA
					al_play_sample(comida, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

					//CAMBIAMOS LAS COMIDAS "o" POR " " PARA SIMULAR COMERLAS
					facil[row][col] = ' ';

				}
			}
		}
	}
}

//DIBUJO DE MAPA MEDIO
void mapa_medio() {
	int row, col;

	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* comida = al_load_sample("sound/coin.wav");
	al_reserve_samples(20);

	//FONDO DE JUEGO
	al_draw_bitmap(nether, 0, 0, 0);

	//CICLO QUE PINTARA LAS ROCAS EN LA POSICION DE LAS "X" Y MANZANAS EN LA POSICION DE LAS "o"
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (medio[row][col] == 'X')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(netherrack, col * 30, row * 30, 0);
			}
			else if (medio[row][col] == 'o')
			{
				//PINTAMOS COMIDA
				al_draw_bitmap(netherite, col * 30, row * 30, 0);
				if ((py / 30 == row) && (px / 30 == col))
				{
					//ACTIVAMOS MUSICA DE COMIDA
					al_play_sample(comida, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

					//CAMBIAMOS LAS COMIDAS "o" POR " " PARA SIMULAR COMERLAS
					medio[row][col] = 'N';

				}
			}
		}
	}
}

//DIBUJO DE MAPA DIFICIL
void mapa_dificil() {
	int row, col;

	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* comida = al_load_sample("sound/coin.wav");
	al_reserve_samples(20);

	//FONDO DE JUEGO
	al_draw_bitmap(endcity, 0, 0, 0);

	//CICLO QUE PINTARA LAS ROCAS EN LA POSICION DE LAS "X" Y MANZANAS EN LA POSICION DE LAS "o"
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (dificil[row][col] == 'X')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(endstone, col * 30, row * 30, 0);
			}
			else if (dificil[row][col] == 'o')
			{
				//PINTAMOS COMIDA
				al_draw_bitmap(enderperl, col * 30, row * 30, 0);
				if ((py / 30 == row) && (px / 30 == col))
				{
					//ACTIVAMOS MUSICA DE COMIDA
					al_play_sample(comida, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

					//CAMBIAMOS LAS COMIDAS "o" POR " " PARA SIMULAR COMERLAS
					dificil[row][col] = ' ';

				}
			}
		}
	}
}

//DIBUJO ENEMIGOS
//FACIL
void dibujar_zombie()
{
	al_draw_bitmap(zombie, zx, zy, 0);
}

void dibujar_esqueleto()
{
	al_draw_bitmap(esqueleto, ex, ey, 0);
}

void dibujar_creeper()
{
	al_draw_bitmap(creeper, cx, cy, 0);
}

void dibujar_arana()
{
	al_draw_bitmap(arana, arx, ary, 0);
}

//MEDIO
void dibujar_whither()
{
	al_draw_bitmap(whither, wx, wy, 0);
}

void dibujar_piglin()
{
	al_draw_bitmap(piglin, pix, piy, 0);
}

void dibujar_zombiepiglin()
{
	al_draw_bitmap(zombipiglin, zpx, zpy, 0);
}

void dibujar_blaze()
{
	al_draw_bitmap(blaze, bx, by, 0);
}

//DIFICIL
void dibujar_enderman()
{
	al_draw_bitmap(enderman, enx, eny, 0);
	al_draw_bitmap(enderman, enx2, eny2, 0);
	al_draw_bitmap(enderman, enx3, eny3, 0);
	al_draw_bitmap(enderman, enx4, eny4, 0);
}

void dibujar_dragon()
{
	al_draw_bitmap(dragon, dx, dy, 0);
}

//ENEMIGOS
//FACIL
void movimiento_zombie_facil()
{
	int wdir = rand() % 4;

	if (facil[zy / 30][zx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (facil[zy / 30][(zx - 30) / 30] != 'X') zx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (facil[zy / 30][(zx + 30) / 30] != 'X') zx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (facil[(zy - 30) / 30][zx / 30] != 'X') zy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (facil[(zy + 30) / 30][zx / 30] != 'X') zy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (zx <= -30)zx = 870;
	else if (zx >= 870)zx = -30;
}

void movimiento_esqueleto_facil()
{
	int wdir = rand() % 4;

	if (facil[ey / 30][ex / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (facil[ey / 30][(ex - 30) / 30] != 'X') ex -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (facil[ey / 30][(ex + 30) / 30] != 'X') ex += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (facil[(ey - 30) / 30][ex / 30] != 'X') ey -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (facil[(ey + 30) / 30][ex / 30] != 'X') ey += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (ex <= -30)ex = 870;
	else if (ex >= 870)ex = -30;
}

void movimiento_creeper_facil()
{
	int wdir = rand() % 4;

	if (facil[cy / 30][cx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (facil[cy / 30][(cx - 30) / 30] != 'X') cx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (facil[cy / 30][(cx + 30) / 30] != 'X') cx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (facil[(cy - 30) / 30][cx / 30] != 'X') cy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (facil[(cy + 30) / 30][cx / 30] != 'X') cy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (cx <= -30)cx = 870;
	else if (cx >= 870)cx = -30;
}

void movimiento_araña_facil()
{
	int wdir = rand() % 4;

	if (facil[ary / 30][arx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (facil[ary / 30][(arx - 30) / 30] != 'X') arx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (facil[ary / 30][(arx + 30) / 30] != 'X') arx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (facil[(ary - 30) / 30][arx / 30] != 'X') ary -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (facil[(ary + 30) / 30][arx / 30] != 'X') ary += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (arx <= -30)arx = 870;
	else if (arx >= 870)arx = -30;
}

//MEDIO
void movimiento_whither_medio()
{
	int wdir = rand() % 4;

	if (facil[wy / 30][wx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (medio[wy / 30][(wx - 30) / 30] != 'X') wx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (medio[wy / 30][(wx + 30) / 30] != 'X') wx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (medio[(wy - 30) / 30][wx / 30] != 'X') wy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (medio[(wy + 30) / 30][wx / 30] != 'X') wy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (wx <= -30)wx = 870;
	else if (wx >= 870)wx = -30;
}

void movimiento_piglin_medio()
{
	int wdir = rand() % 4;

	if (facil[piy / 30][pix / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (medio[piy / 30][(pix - 30) / 30] != 'X') pix -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (medio[piy / 30][(pix + 30) / 30] != 'X') pix += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (medio[(piy - 30) / 30][pix / 30] != 'X') piy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (medio[(piy + 30) / 30][pix / 30] != 'X') piy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (pix <= -30)pix = 870;
	else if (pix >= 870)pix = -30;
}

void movimiento_zombiepiglin_medio()
{
	int wdir = rand() % 4;

	if (facil[zpy / 30][zpx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (medio[zpy / 30][(zpx - 30) / 30] != 'X') zpx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (medio[zpy / 30][(zpx + 30) / 30] != 'X') zpx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (medio[(zpy - 30) / 30][zpx / 30] != 'X') zpy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (medio[(zpy + 30) / 30][zpx / 30] != 'X') zpy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (zpx <= -30)zpx = 870;
	else if (zpx >= 870)zpx = -30;
}

void movimiento_blaze_medio()
{
	int wdir = rand() % 4;

	if (facil[by / 30][bx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (medio[by / 30][(bx - 30) / 30] != 'X') bx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (medio[by / 30][(bx + 30) / 30] != 'X') bx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (medio[(by - 30) / 30][bx / 30] != 'X') by -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (medio[(by + 30) / 30][bx / 30] != 'X') by += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (bx <= -30)bx = 870;
	else if (bx >= 870)bx = -30;
}

//DIFICIL
void movimiento_enderman_dificil()
{
	int wdir = rand() % 4;

	if (facil[eny / 30][enx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (dificil[eny / 30][(enx - 30) / 30] != 'X') enx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (dificil[eny / 30][(enx + 30) / 30] != 'X') enx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (dificil[(eny - 30) / 30][enx / 30] != 'X') eny -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (dificil[(eny + 30) / 30][enx / 30] != 'X') eny += 30;
		else wdir = rand() % 4;
		break;
	}

	wdir = rand() % 4;

	switch (wdir)
	{
	case 0:
		if (dificil[eny2 / 30][(enx2 - 30) / 30] != 'X') enx2 -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (dificil[eny2 / 30][(enx2 + 30) / 30] != 'X') enx2 += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (dificil[(eny2 - 30) / 30][enx2 / 30] != 'X') eny2 -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (dificil[(eny2 + 30) / 30][enx2 / 30] != 'X') eny2 += 30;
		else wdir = rand() % 4;
		break;
	}

	wdir = rand() % 4;

	switch (wdir)
	{
	case 0:
		if (dificil[eny3 / 30][(enx3 - 30) / 30] != 'X') enx3 -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (dificil[eny3 / 30][(enx3 + 30) / 30] != 'X') enx3 += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (dificil[(eny3 - 30) / 30][enx3 / 30] != 'X') eny3 -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (dificil[(eny3 + 30) / 30][enx3 / 30] != 'X') eny3 += 30;
		else wdir = rand() % 4;
		break;
	}

	wdir = rand() % 4;

	switch (wdir)
	{
	case 0:
		if (dificil[eny4 / 30][(enx4 - 30) / 30] != 'X') enx4 -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (dificil[eny4 / 30][(enx4 + 30) / 30] != 'X') enx4 += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (dificil[(eny4 - 30) / 30][enx4 / 30] != 'X') eny4 -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (dificil[(eny4 + 30) / 30][enx4 / 30] != 'X') eny4 += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (enx <= -30)enx = 870;
	else if (enx >= 870)enx = -30;
	if (enx2 <= -30)enx2 = 870;
	else if (enx2 >= 870)enx2 = -30;
	if (enx3 <= -30)enx3 = 870;
	else if (enx3 >= 870)enx3 = -30;
	if (enx4 <= -30)enx4 = 870;
	else if (enx4 >= 870)enx4 = -30;
}

void movimiento_dragon_dificil()
{
	int wdir = rand() % 4;

	if (facil[dy / 30][dx / 30] == '|')
	{
		wdir = rand() % 4;
	}

	switch (wdir)
	{
	case 0:
		if (dificil[dy / 30][(dx - 30) / 30] != 'X') dx -= 30;
		else wdir = rand() % 4;
		break;
	case 1:
		if (dificil[dy / 30][(dx + 30) / 30] != 'X') dx += 30;
		else wdir = rand() % 4;
		break;
	case 2:
		if (dificil[(dy - 30) / 30][dx / 30] != 'X') dy -= 30;
		else wdir = rand() % 4;
		break;
	case 3:
		if (dificil[(dy + 30) / 30][dx / 30] != 'X') dy += 30;
		else wdir = rand() % 4;
		break;
	}

	//cout << wdir << endl;

	//Atajo
	if (dx <= -30)dx = 870;
	else if (dx >= 870)dx = -30;
}

//DIBUJADO PERSONAJE DERECHA
void dibujar_steve()
{
	al_draw_bitmap(stevebmp, px, py, 0);
}

//MOVIMIENTO PERSONAJE
void mover_personaje_facil()
{
	//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue_teclado, &events);

	//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
	antpx = px;
	antpy = py;

	//TECLAS DE MOVIMIENTO

	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (events.keyboard.keycode == ALLEGRO_KEY_A || events.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			if (facil[py / 30][(px - 30) / 30] != 'X') px -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_W || events.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			if (facil[(py - 30) / 30][px / 30] != 'X') py -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_D || events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			if (facil[py / 30][(px + 30) / 30] != 'X') px += 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_S || events.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			if (facil[(py + 30) / 30][px / 30] != 'X') py += 30;
		}
	}

	//ATAJOS DEL MAPA
	if (px <= -30)px = 870;
	else if (px >= 870)px = -30;
}

void mover_personaje_medio()
{
	//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue_teclado, &events);

	//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
	antpx = px;
	antpy = py;

	//TECLAS DE MOVIMIENTO
	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (events.keyboard.keycode == ALLEGRO_KEY_A || events.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			if (medio[py / 30][(px - 30) / 30] != 'X') px -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_W || events.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			if (medio[(py - 30) / 30][px / 30] != 'X') py -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_D || events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			if (medio[py / 30][(px + 30) / 30] != 'X') px += 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_S || events.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			if (medio[(py + 30) / 30][px / 30] != 'X') py += 30;
		}
	}

	//ATAJOS DEL MAPA
	if (px <= -30)px = 870;
	else if (px >= 870)px = -30;
}

void mover_personaje_dificil()
{
	//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
	ALLEGRO_EVENT events;
	al_wait_for_event(event_queue_teclado, &events);

	//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
	antpx = px;
	antpy = py;

	//TECLAS DE MOVIMIENTO
	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (events.keyboard.keycode == ALLEGRO_KEY_A || events.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			if (dificil[py / 30][(px - 30) / 30] != 'X') px -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_W || events.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			if (dificil[(py - 30) / 30][px / 30] != 'X') py -= 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_D || events.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			if (dificil[py / 30][(px + 30) / 30] != 'X') px += 30;
		}
		else if (events.keyboard.keycode == ALLEGRO_KEY_S || events.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			if (dificil[(py + 30) / 30][px / 30] != 'X') py += 30;
		}
	}

	//ATAJOS DEL MAPA
	if (px <= -30)px = 870;
	else if (px >= 870)px = -30;
}

//MUERTE
void choque_facil()
{
	if 
		(
		((py == zy) && (px == zx)) || ((zy == antpy) && (zx == antpx))
		|| ((py == ey) && (px == ex)) || ((ey == antpy) && (ex == antpx))
		|| ((py == cy) && (px == cx)) || ((cy == antpy) && (cx == antpx))
		|| ((py == ary) && (px == arx)) || ((ary == antpy) && (arx == antpx))
		)
	{
		mapa_facil();
		dibujar_steve();
		
		px = 30 * 14;
		py = 30 * 17;
		cout << "MORISTE, FACIL!\n";
	}
}

void choque_medio()
{
	if 
		(
		((py == wy) && (px == wx)) || ((wy == antpy) && (wx == antpx))
		|| ((py == piy) && (px == pix)) || ((piy == antpy) && (pix == antpx))
		|| ((py == zpy) && (px == zpx)) || ((zpy == antpy) && (zpx == antpx))
		|| ((by == wy) && (bx == wx)) || ((by == antpy) && (bx == antpx))
		)
	{
		mapa_medio();
		dibujar_steve();
		px = 30 * 14;
		py = 30 * 17;
		cout << "MORISTE, MEDIO!\n";
	}
}

void choque_dificil()
{
	if 
		(
		((py == eny) && (px == enx)) || ((eny == antpy) && (enx == antpx))
		|| ((py == dy) && (px == dx)) || ((dy == antpy) && (dx == antpx))
		|| ((py == eny2) && (px == enx2)) || ((eny2 == antpy) && (enx2 == antpx))
		|| ((py == eny3) && (px == enx3)) || ((eny3 == antpy) && (enx3 == antpx))
		|| ((py == eny4) && (px == enx4)) || ((eny4 == antpy) && (enx4 == antpx))
		)
	{
		mapa_dificil();
		dibujar_steve();
		px = 30 * 14;
		py = 30 * 17;
		cout << "MORISTE, DIFICIL!\n";
	}
}

//FIN DE JUEGO
bool game_over_facil()
{
	int row, col;
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (facil[row][col] == 'o') return true;
		}
	}

	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (facil[row][col] == 'N')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(diamante, col * 30, row * 30, 0);
			}
		}
	}

	mapa_facil();
	dibujar_steve();
	px = 30 * 14;
	py = 30 * 17;

	return false;
}

bool game_over_medio()
{
	int row, col;
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (medio[row][col] == 'o') return true;
		}
	}

	mapa_medio();
	dibujar_steve();
	px = 30 * 14;
	py = 30 * 17;

	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (medio[row][col] == 'N')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(netherite, col * 30, row * 30, 0);
			}
		}
	}

	return false;
}

bool game_over_dificil()
{
	int row, col;
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (dificil[row][col] == 'o') return true;
		}
	}

	mapa_dificil();
	dibujar_steve();
	px = 30 * 14;
	py = 30 * 17;
	
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (dificil[row][col] == 'N')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(enderperl, col * 30, row * 30, 0);
			}
		}
	}

	return false;
}

//INICIO DE JUEGO
int jugarfacil()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/ambiente.wav");
	al_reserve_samples(1);
	
	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	
	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ( (!GetAsyncKeyState(VK_ESCAPE)) && (game_over_facil()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{		
		al_clear_to_color(al_map_rgb(0, 0, 0));		
		
		mapa_facil();													//Activamos la funcion que dibuja el Mapa

		dibujar_steve();												//Activamos la funcion que dibuja al Personaje
		mover_personaje_facil();										//Activamos movimiento Personaje

		dibujar_zombie();												//Activamos la funcion que dibuja al Zombie
		dibujar_esqueleto();											//Activamos la funcion que dibuja al Esqueleto
		dibujar_creeper();												//Activamos la funcion que dibuja al Creeper
		dibujar_arana();												//Activamos la funcion que dibuja al Araña
		movimiento_zombie_facil();										//Activamos movimiento enemigo
		movimiento_esqueleto_facil();									//Activamos movimiento enemigo
		movimiento_creeper_facil();										//Activamos movimiento enemigo
		movimiento_araña_facil();										//Activamos movimiento enemigo
		
		choque_facil();													//Activamos funcion para coque entre enemigo y personaje

		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	return 1;
}

int jugarmedio()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/nether.wav");
	al_reserve_samples(1);

	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ((!GetAsyncKeyState(VK_ESCAPE)) && (game_over_medio()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		mapa_medio();													//Activamos la funcion que dibuja el Mapa
		
		dibujar_steve();												//Activamos la funcion que dibuja al Personaje
		mover_personaje_medio();										//Activamos la funcion del movimiento del Personaje
		
		dibujar_whither();												//Activamos la funcion que dibuja al Whither
		dibujar_piglin();												//Activamos la funcion que dibuja al Piglin
		dibujar_zombiepiglin();											//Activamos la funcion que dibuja al Zombie Piglin
		dibujar_blaze();												//Activamos la funcion que dibuja al Blaze
		movimiento_whither_medio();										//Activamos movimiento enemigo
		movimiento_piglin_medio();										//Activamos movimiento enemigo
		movimiento_zombiepiglin_medio();								//Activamos movimiento enemigo
		movimiento_blaze_medio();										//Activamos movimiento enemigo

		choque_medio();													//Activamos funcion para coque entre enemigo y personaje

		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	return 1;
}

int jugardificil()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/end.wav");
	al_reserve_samples(1);

	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ((!GetAsyncKeyState(VK_ESCAPE)) && (game_over_dificil()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));

		mapa_dificil();													//Activamos la funcion que dibuja el Mapa
		
		dibujar_steve();												//Activamos la funciones que dibuja al Personaje
		mover_personaje_dificil();										//Activamos la funcion del movimiento del Personaje
		
		dibujar_enderman();												//Activamos la funcion que dibuja al Zombie Piglin
		dibujar_dragon();												//Activamos la funcion que dibuja al Blaze
		movimiento_enderman_dificil();									//Activamos movimiento enemigo
		movimiento_dragon_dificil();									//Activamos movimiento enemigo
		
		choque_dificil();												//Activamos funcion para coque entre enemigo y personaje

		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	return 1;
}