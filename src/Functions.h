﻿#pragma once

///////////////////////////////////////
/*
Functions
*/
///////////////////////////////////////

QS2D_INLINE void QS2D_Init(const char* name, const int width, const int height)
{
	srand(time(NULL));

	//States
	internal = (QS2D_Data*)calloc(1, sizeof(QS2D_Data));
	
	if (internal == NULL)
		exit(1);
	internal->background_color = QS2D_Color_New(0, 0, 0);
	internal->quit = 0;
	internal->autoRender = 1;
	internal->autoClear = 1;
	internal->w = width;
	internal->h = height;

	// SDL INIT
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	internal->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_RENDERER_PRESENTVSYNC);
	internal->render = SDL_CreateRenderer(internal->window, -1, SDL_RENDERER_ACCELERATED);
}

QS2D_INLINE void QS2D_Close()
{
	SDL_DestroyWindow(internal->window);
	SDL_DestroyRenderer(internal->render);
	free(internal);
	SDL_Quit();
}

QS2D_INLINE void QS2D_Screen_Render()
{
	SDL_RenderPresent(internal->render);
}

QS2D_INLINE int QS2D_Event()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			internal->quit = 1;
			break;
		case SDL_KEYDOWN:
			internal->input.key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			internal->input.key[event.key.keysym.scancode] = 0;
			break;
		default:
			break;
		}
	}

	if (internal->autoRender)
		QS2D_Screen_Render();
	if (internal->autoClear)
		QS2D_Screen_Clear();		

	return !internal->quit;
}

QS2D_INLINE bool QS2D_Key(const int button)
{
	if (button < 512)
	{
		return internal->input.key[button];
	}
	return 0;

}
QS2D_INLINE void QS2D_Quit()
{
	internal->quit = 1;
}

QS2D_INLINE QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b)
{
	const QS2D_Color color = { r, g, b};
	return color;
}

QS2D_INLINE void QS2D_Draw_ColorSet(const QS2D_Color c)
{
	SDL_SetRenderDrawColor(internal->render, c.r, c.g, c.b, 255);
}

QS2D_INLINE void QS2D_Screen_Clear()
{
	SDL_SetRenderDrawColor(internal->render, internal->background_color.r, internal->background_color.g, internal->background_color.b, 255);
	SDL_RenderClear(internal->render);
}

QS2D_INLINE void QS2D_Draw_Pixel(const float x, const float y)
{
	SDL_RenderDrawPointF(internal->render, x, y);
}

QS2D_INLINE void QS2D_Draw_Rect(const float x, const float y, const float w, const float h)
{
	SDL_FRect rect = { x,y,w,h };
	SDL_RenderDrawRectF(internal->render, &rect);
}

QS2D_INLINE QS2D_Color QS2D_Screen_GetPixel(const int x, const int y)
{
	//TODO 
	/*
	Uint32 pixel = 0;
	SDL_Rect rect = { x, y, 1, 1 };
	SDL_RenderReadPixels(internal->render, &rect, pixel, NULL, sizeof(Uint32)*internal->w);
	printf("<%8x> hexadecimal padded with blanks to width 8.\n", pixel);*/
	QS2D_Color c = { 0 };
	return c;
}

QS2D_INLINE void QS2D_Screen_SetBGColor(QS2D_Color c)
{
	internal->background_color = c;
}
QS2D_INLINE QS2D_Color QS2D_Screen_GetBGColor()
{
	return internal->background_color;
}

QS2D_INLINE void QS2D_Screen_Save(const char* path_name)
{
	SDL_Surface *s = SDL_CreateRGBSurface(0, internal->w, internal->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(internal->render, NULL, SDL_PIXELFORMAT_ARGB8888, s->pixels, s->pitch);
	SDL_SaveBMP(s, path_name);
	SDL_FreeSurface(s);
}

QS2D_INLINE void QS2D_Screen_AutoRender()
{
	internal->autoRender = 1;
}

QS2D_INLINE void QS2D_Screen_ManualRender()
{
	internal->autoRender = 0;
}
QS2D_INLINE void QS2D_Screen_AutoClear()
{
	internal->autoClear = 1;
}

QS2D_INLINE void QS2D_Screen_ManualClear()
{
	internal->autoClear = 0;
}

QS2D_INLINE void QS2D_Screen_Resize(const int w, const int h)
{
	SDL_SetWindowSize(internal->window, w, h);
	internal->w = w; internal->h = h;
}

QS2D_INLINE int QS2D_Screen_GetWidth()
{
	int w;
	SDL_GetWindowSize(internal->window, &w, NULL);
	return w;
}

QS2D_INLINE int QS2D_Screen_GetHeight()
{
	int h;
	SDL_GetWindowSize(internal->window, NULL, &h);
	return h;
}
