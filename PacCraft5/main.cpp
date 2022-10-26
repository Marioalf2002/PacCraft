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
#include <cstdlib>													// contiene la funcion system("pause")
#include <locale.h>													// Libreria que contiene la funcion setlocale
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
ALLEGRO_EVENT_QUEUE* event_queue;									//Variable para contener eventos
ALLEGRO_BITMAP* roca;												//Variable que contiene Textura Roca
ALLEGRO_BITMAP* comida;												//Variable que contiene Textura Comida
ALLEGRO_BITMAP* fondo;								

int dir = 0;														//Direccion del Personaje
int px = 30 * 14, py = 30 * 17;										//Posicion del Personaje
int jugar();														//Inicia Funcion Jugar

//MAPA DEL JUEGO
char mapa[MAXFIL][MAXCOL] = {
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "X  o |o o o XXXXXX o o o| o  X",
  "X XXX XX XX  o  o  XX XX XXX X",
  "XoXXX XX XX XXXXXX XX XX XXXoX",
  "X      o|o   o  o   o|o      X",
  "XoXXXoXX XXX XXXX XXX XXoXXXoX",
  "X    |XX    |XXXX|    XX     X",
  "XoXXXoXXXXXX XXXX XXXXXXoXXXoX",
  "X XXX|o  ooo|  | |ooo  o|XXX X",
  " |   |XX XXXX XX XXXX XX|   | ",
  "X XXXoXX XXXX XX XXXX XXoXXX X",
  "XoXXXo   ooo| |  |ooo   oXXXoX",
  "X XXXoXXXXXX XXXX XXXXXXoXXX X",
  "X    |XX    |XXXX|    XX|    X",
  "X XXXoXX XXXXXXXXXXXX XXoXXX X",
  "XoXXX| o| o o    o o |o |XXXoX",
  "X XXXoXXXX XXXXXXXXX XXX XXX X",
  "XoXXXoXXXX           XXX XXXoX",
  "X  o |o o  XXXXXXXXX o o| o  X",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};

/*
char mapa[MAXFIL][MAXCOL] = {
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
	"x           xxxxxx           x",
	"x xxx xxxxx   xx   xxxxx xxx x",
	"x xxx     xxxxxxxxxxx        x",
	"x     xx     xxxx     xx     x",
	"x xxx xx      xx      xx xxx x",
	"x     xx xxxx    xxxx xx     x",
	"x xxx xx xxxx    xxxx xx xxx x",
	"x xxx xx xxxx    xxxx xx xxx x",
	"      xx     xxxx     xx      ",
	"x xxx xx x xxxxxxxx x xx xxx x",
	"x xxx xx x xxxxxxxx x xx xxx x",
	"x xxx xx x xx    xx x xx xxx x",
	"x     xx      xx      xx     x",
	"x xxx xxxxxx xxxx xxxxxx xxx x",
	"x xxx xx     xxxx     xx xxx x",
	"x xxx xx xxxxxxxxxxxx xx xxx x",
	"x xxx                    xxx x",
	"x           xxxxxx           x",
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
};
*/

//PROGAMA INICIAL
int main()
{
	//IDIOMA QUE SE USARA
	setlocale(LC_ALL, "");											// Uso de la funcion setlocale detecta el idioma del sistema operativo del dispositivo donde se ejecuta.
	setlocale(LC_ALL, "spanish");									// Por defecto se usara el idioma establecido "spanish".

	//INICIALIZAMOS ALLEGRO
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 404", "No se pudo cargar correctamente la libreria Allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
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
	ventana = al_create_display(900, 600);
	menu_null = al_load_bitmap("menu/menu_null.png");
	menu_play = al_load_bitmap("menu/play.png");
	menu_salir = al_load_bitmap("menu/salir.png");
	roca = al_load_bitmap("img/roca.png");
	comida = al_load_bitmap("img/comida.png");
	fondo = al_load_bitmap("img/fondo.png");

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
	
	//VARIABLES QUE CONTENDRAN POSICION DE MOUSE Y CLICKS
	int x = -1, y = -1;
	int botones[] = { 0 };

	//CREAMOS VARIABLES DE SONIDO MENU
	ALLEGRO_SAMPLE* menu = al_load_sample("sound/musica.wav");
	al_reserve_samples(1);

	//ACTIVAMOS MUSICA DE MENU
	al_play_sample(menu, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL PROGRAMA ACTIVO
	while (!GetAsyncKeyState(VK_ESCAPE))		//Para cerrar el Programa se espera la señal de tecla "ESC"
	{

		ALLEGRO_EVENT Evento;										//Variable que llevara el Evento a registrar
		al_wait_for_event(event_queue, &Evento);

		al_clear_to_color(al_map_rgb(0, 0, 0));						//Limpiamos todo color que tengamos

		//VALIDAMOS CLICK PARA ACTIVAR MENU DEPENDIENDO UBICACION
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
					jugar();
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

//DIBUJADO DE MAPA
void mapeado() {
	int row, col;

	//CREAMOS VARIABLES DE SONIDO COMIDA
	ALLEGRO_SAMPLE* sonidocomida = al_load_sample("sound/comida.wav");
	al_reserve_samples(2);

	//FONDO DE JUEGO
	al_draw_bitmap(fondo, 0, 0, 0);

	//CICLO QUE PINTARA LAS ROCAS EN LA POSICION DE LAS "X" Y MANZANAS EN LA PISICION DE LAS "o"
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (mapa[row][col] == 'X')
			{
				//PINTAMOS MUROS
				al_draw_bitmap(roca, col * 30, row * 30, 0);
			}
			else if (mapa[row][col] == 'o')
			{
				//PINTAMOS COMIDA
				al_draw_bitmap(comida, col * 30, row * 30, 0);
				if ((py / 30 == row) && (px / 30 == col))
				{
					//ACTIVAMOS MUSICA DE MENU
					al_play_sample(sonidocomida, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

					//CAMBIAMOS LAS COMIDAS "o" POR " " PARA SIMULAR COMERLAS
					mapa[row][col] = ' ';

				}
			}
		}
	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(sonidocomida);
}

//FIN DE JUEGO

bool game_over()
{
	int row, col;
	for (row = 0; row < MAXFIL; row++)
	{
		for (col = 0; col < MAXCOL; col++)
		{
			if (mapa[row][col] == 'o') return true;
		}
	}

	return false;
}

//INICIO DE JUEGO
int jugar()
{
	//CREAMOS VARIABLES DE SONIDO AMBIENTE
	ALLEGRO_SAMPLE* ambiente = al_load_sample("sound/ambiente.wav");
	al_reserve_samples(1);
	
	//ACTIVAMOS MUSICA DE AMBIENTE
	al_play_sample(ambiente, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

	//CICLO QUE TENDRA EL JUEGO ACTIVO
	while ( (!GetAsyncKeyState(VK_ESCAPE)) && (game_over()) )					//Para cerrar el Programa se espera la señal de tecla "ESC" o que se termine de comer los alimentos
	{

		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queue, &Evento);

		/*if (dir == 0)
		{

		}
		if (dir == 1)
		{

		}
		if (dir == 2)
		{

		}
		if (dir == 3)
		{

		}

		if(Evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			 if(ALLEGRO_KEY_RIGHT) dir = 1;
			else if(ALLEGRO_KEY_LEFT) dir = 0;
			else if(ALLEGRO_KEY_UP) dir = 2;
			else if(ALLEGRO_KEY_DOWN) dir = 3;
		}

		if (px <= -30)px = 870;
		else if (px >= 870)px = -30;
		*/
		al_clear_to_color(al_map_rgb(0, 0, 0));
		mapeado();														//Activamos la funcion que dibuja el Mapa
		//dibujar_steve();

		al_flip_display();

	}

	//LIBERAMOS MEMORIA DE SONIDO
	al_destroy_sample(ambiente);
	return 1;
}