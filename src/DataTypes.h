#pragma once

//////////////////////////////////
/*
Typedef
*/
//////////////////////////////////

typedef struct QS2D_Color { Uint8 r, g, b, a; } QS2D_Color;
typedef struct QS2D_Input { bool key[512]; } QS2D_Input;
typedef struct QS2D_Data {
	SDL_Window *window;
	SDL_Renderer *render;
	QS2D_Input input;
	bool quit;
	bool renderOnEvent; int w, h;
} QS2D_Data;
typedef struct QS2D_Point { QS2D_Float x, y; } QS2D_Point;
