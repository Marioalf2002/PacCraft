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
ALLEGRO_BITMAP* stevebmp;											//Imagen del personaje
ALLEGRO_BITMAP* muertesteve;										//Imagen muerte

int dir = 0;														//Direccion del Personaje
int px = 30 * 14, py = 30 * 17;										//Posicion del Personaje
int antpx, antpy;													//Posicion anteriro del Personaje

int jugarfacil();													//Inicio de Funcion de Juego Facil
int jugarmedio();													//Inicio de Funcion de Juego Medio
int jugardificil();													//Inicio de Funcion de Juego Dificil
int dificultad();													//Inicio de Funcion de Menu Dificultades

//MAPA DEL JUEGO
char facil[MAXFIL][MAXCOL] = {
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X    |     |XXXXXX|     |    X",
		"X XXX XXXXX|oooooo|XXXXX XXX X",
		"X|ooo|    X XXXXXX XX   |ooo|X",
		"X XXX XX     XXXX     XX XXX X",
		"X XXX XX      XX      XX XXX X",
		"X|ooo|XX XXXX oo XXXX XX|ooo|X",
		"X XXX XX XXXX oo XXXX XX XXX X",
		"X XXX XX XXXX oo XXXX XX XXX X",
		" |ooo|XX     XXXX     XX|ooo| ",
		"X XXX XX X XXXXXXXX X XX XXX X",
		"X XXX XX X XXXXXXXX X XX XXX X",
		"X XXX XX X XXooooXX X XX XXX X",
		"X|ooo|XX  | | XX | |  XX|ooo|X",
		"X XXX XXXXXX XXXX XXXXXX XXX X",
		"X XXX XX     XXXX     XX XXX X",
		"X XXX XX XXXXXXXXXXXX XX XXX X",
		"X XXX|  |            |  |XXX X",
		"X oooooooo  XXXXXX  oooooooo X",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

char medio[MAXFIL][MAXCOL] = {

		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"X  o |o o o XXXXXX o o o| o  X",
		"X XXX XX XX| oooo |XX XX XXX X",
		"XoXXX XX XX XXXXXX XX XX XXXoX",
		"X      o|o   o  o   o|o      X",
		"XoXXXoXX XXX XXXX XXX XXoXXXoX",
		"X    |XX    |XXXX|    XX     X",
		"XoXXXoXXXXXX XXXX XXXXXXoXXXoX",
		"X XXX|o  ooo|   ||ooo  o|XXX X",
		" |   |XX XXXX XX XXXX XX|   | ",
		"X XXXoXX XXXX XX XXXX XXoXXX X",
		"XoXXXo   ooo||   |ooo   oXXXoX",
		"X XXXoXXXXXX XXXX XXXXXXoXXX X",
		"X    |XX    |XXXX|    XX|    X",
		"X XXXoXX XXXXXXXXXXXX XXoXXX X",
		"XoXXX| o|  ooooooooo |o |XXXoX",
		"X XXXoXXXX XXXXXXXXX XXX XXX X",
		"XoXXXoXXXX           XXX XXXoX",
		"X  o |o o  XXXXXXXXX o o| o  X",
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
	stevebmp = al_load_bitmap("img/steve0.png");
	muertesteve = al_load_bitmap("img/muerte2.png");

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

	//REGISTRO DE EVENTOS
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());

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
					medio[row][col] = ' ';

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

//DIBUJADO PERSONAJE
void dibujar_steve()
{
	al_draw_bitmap(stevebmp, px, py, 0);
}

//ZOMBIE
class zombie
{
	ALLEGRO_BITMAP* zombiebmp;
	ALLEGRO_BITMAP* zombie1;
	int fdir= rand() % 4;
	int _x, _y;

public:
	zombie(int x, int y); //Constructor
	void dibujarzombie() const;
	void moverzombie();
	void choquezombie();
};

zombie::zombie(int x, int y)
{
	_x = x;
	_y = y;
	fdir = rand() % 4;

	zombie1 = al_create_bitmap(30, 30);
	zombiebmp = al_load_bitmap("img/zombie.png");
}

void zombie::dibujarzombie() const
{
	al_draw_bitmap(zombiebmp, _x, _y, 0);
}

void zombie::choquezombie()
{
	ALLEGRO_SAMPLE* muerte = al_load_sample("sound/muerte.wav");
	al_reserve_samples(3);

	if (((py == _y) && (px == _x)) || ((_y == antpy) && (_x == antpx)))
	{
		//ACTIVAMOS SONIDO DE MUERTE
		al_play_sample(muerte, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		for (int i = 0; i <= 1; i++)
		{
			mapa_facil();
			//mapa_medio();
			//mapa_dificil();
		}
		
		px = 30 * 14;
		py = 30 * 17;
		dir = 4;
	}
	al_destroy_sample(muerte);
	al_flip_display();
}

void zombie::moverzombie()
{
	dibujarzombie();
	choquezombie();

	fdir = rand() % 4;
	
	if (facil[_y / 30][_x / 30] == '|')
	{
		fdir = rand() % 4;
	}
	
	if (fdir == 0)
	{
		if (facil[_y / 30][(_x - 30) / 30] != 'X') _x -= 30;
		else fdir = rand() % 4;
	}
	else if (fdir == 1)
	{
		if (facil[_y / 30][(_x + 30) / 30] != 'X') _x += 30;
		else fdir = rand() % 4;
	}
	else if (fdir == 2)
	{
		if (facil[(_y - 30) / 30][_x / 30] != 'X') _y -= 30;
		else fdir = rand() % 4;
	}
	else if (fdir == 3)
	{
		if (facil[(_y + 30) / 30][_x / 30] != 'X') _y += 30;
		else fdir = rand() % 4;
	}
	
	/*
	switch (fdir)
	{
	case 0:
		if (mapa[_y / 30][(_x - 30) / 30] != 'X') _x -= 30;
		else fdir = rand() % 4;
		break;
	case 1:
		if (mapa[_y / 30][(_x + 30) / 30] != 'X') _x += 30;
		else fdir = rand() % 4;
		break;
	case 2:
		if (mapa[(_y - 30) / 30][_x / 30] != 'X') _y -= 30;
		else fdir = rand() % 4;
		break;
	case 3:
		if (mapa[(_y + 30) / 30][_x / 30] != 'X') _y += 30;
		else fdir = rand() % 4;
		break;
	}
	*/
	//Atajo
	if (_x <= -30)_x = 870;
	else if (_x >= 870)_x = -30;
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

	return false;
}

//INICIO DE JUEGO
int jugarfacil()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/ambiente.wav");
	al_reserve_samples(1);
	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* caminar = al_load_sample("sound/caminar.wav");
	al_reserve_samples(10);
	
	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ( (!GetAsyncKeyState(VK_ESCAPE)) && (game_over_facil()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{
		//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
		antpx = px;
		antpy = py;

		//ENEMIGOS
		//Zombie
		zombie A(30 * 1, 30 * 3);										//Creamos enemigo

		//SONIDO DE CAMINAR
		if (dir != 4)
		{
			//ACTIVAMOS SONIDO DE CAMINAR
			al_play_sample(caminar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}

		//TECLAS DE MOVIMIENTO
		if(events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
            switch(events.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				if (facil[(py + 30) / 30][px / 30] != 'X') py += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_UP:
				if (facil[(py - 30) / 30][px / 30] != 'X') py -= 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_RIGHT:
				if (facil[py / 30][(px + 30) / 30] != 'X') px += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_LEFT:
				if (facil[py / 30][(px - 30) / 30] != 'X') px -= 30;
				else dir = 4;
				break;
			}
		}

		//ATAJOS DEL MAPA
		if (px <= -30)px = 870;
		else if (px >= 870)px = -30;
		
		al_clear_to_color(al_map_rgb(0, 0, 0));

		mapa_facil();													//Activamos la funcion que dibuja el Mapa
		dibujar_steve();												//Activamos la funciones que dibuja al Personaje
		A.moverzombie();												//Activamos la creacion de un enemigo y movimiento del mismo
		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	al_destroy_sample(caminar);
	return 1;
}

int jugarmedio()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/ambiente.wav");
	al_reserve_samples(1);
	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* caminar = al_load_sample("sound/caminar.wav");
	al_reserve_samples(10);

	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ((!GetAsyncKeyState(VK_ESCAPE)) && (game_over_medio()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{
		//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
		antpx = px;
		antpy = py;

		//ENEMIGOS
		//Zombie
		zombie A(30 * 1, 30 * 3);										//Creamos enemigo

		//SONIDO DE CAMINAR
		if (dir != 4)
		{
			//ACTIVAMOS SONIDO DE CAMINAR
			al_play_sample(caminar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}

		//TECLAS DE MOVIMIENTO
		if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				if (medio[(py + 30) / 30][px / 30] != 'X') py += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_UP:
				if (medio[(py - 30) / 30][px / 30] != 'X') py -= 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_RIGHT:
				if (medio[py / 30][(px + 30) / 30] != 'X') px += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_LEFT:
				if (medio[py / 30][(px - 30) / 30] != 'X') px -= 30;
				else dir = 4;
				break;
			}
		}

		//ATAJOS DEL MAPA
		if (px <= -30)px = 870;
		else if (px >= 870)px = -30;

		al_clear_to_color(al_map_rgb(0, 0, 0));

		mapa_medio();													//Activamos la funcion que dibuja el Mapa
		dibujar_steve();												//Activamos la funciones que dibuja al Personaje
		A.moverzombie();												//Activamos la creacion de un enemigo y movimiento del mismo
		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	al_destroy_sample(caminar);
	return 1;
}

int jugardificil()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/ambiente.wav");
	al_reserve_samples(1);
	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* caminar = al_load_sample("sound/caminar.wav");
	al_reserve_samples(10);

	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ((!GetAsyncKeyState(VK_ESCAPE)) && (game_over_dificil()))		//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{
		//EVENTO QUE DETECTARA LA SEÑAL DE LAS TECLAS
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		//GUARDAMOS POSICION ANTERIOR DEL PERSONAJE
		antpx = px;
		antpy = py;

		//ENEMIGOS
		//Zombie
		zombie A(30 * 1, 30 * 3);										//Creamos enemigo

		//SONIDO DE CAMINAR
		if (dir != 4)
		{
			//ACTIVAMOS SONIDO DE CAMINAR
			al_play_sample(caminar, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		}

		//TECLAS DE MOVIMIENTO
		if (events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_DOWN:
				if (dificil[(py + 30) / 30][px / 30] != 'X') py += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_UP:
				if (dificil[(py - 30) / 30][px / 30] != 'X') py -= 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_RIGHT:
				if (dificil[py / 30][(px + 30) / 30] != 'X') px += 30;
				else dir = 4;
				break;
			case ALLEGRO_KEY_LEFT:
				if (dificil[py / 30][(px - 30) / 30] != 'X') px -= 30;
				else dir = 4;
				break;
			}
		}

		//ATAJOS DEL MAPA
		if (px <= -30)px = 870;
		else if (px >= 870)px = -30;

		al_clear_to_color(al_map_rgb(0, 0, 0));

		mapa_dificil();													//Activamos la funcion que dibuja el Mapa
		dibujar_steve();												//Activamos la funciones que dibuja al Personaje
		A.moverzombie();												//Activamos la creacion de un enemigo y movimiento del mismo
		al_flip_display();
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	al_destroy_sample(caminar);
	return 1;
}