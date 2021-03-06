﻿#pragma once

//////////////////////////////////
/*
Typedef
*/
//////////////////////////////////

typedef struct QS2D_Color { Uint8 r, g, b; } QS2D_Color;
typedef struct QS2D_Input { bool is_pressing[512]; bool on_release[512]; bool on_press[512]; } QS2D_Input;
typedef struct QS2D_Data {
	SDL_Window *window;
	SDL_Renderer *render;
	QS2D_Color background_color;
	QS2D_Input input;
	bool quit;
	bool autoRender; 
	bool autoClear;
	int w, h;
} QS2D_Data;
typedef struct QS2D_Point { QS2D_Float x, y; } QS2D_Point;
typedef struct QS2D_Rect { QS2D_Float x, y, w, h; } QS2D_Rect;
typedef struct QS2D_Image { int w, h; SDL_Texture* handle; } QS2D_Image;