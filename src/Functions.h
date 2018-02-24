#pragma once

///////////////////////////////////////
/*
Functions
*/
///////////////////////////////////////

QS2D_INLINE void QS2D_Init(char* name, const int width, const int height)
{
	srand(time(NULL));

	//States
	internal = (QS2D_Data*)malloc(sizeof(QS2D_Data));
	internal->quit = 0;
	internal->renderOnEvent = 1;
	internal->w = width;
	internal->h = height;

	//Sdl
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

QS2D_INLINE void QS2D_Render()
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
	if (internal->renderOnEvent)
		QS2D_Render();
	return internal->quit;
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

QS2D_INLINE QS2D_Color QS2D_NewColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	QS2D_Color color = { r, g, b, a };
	return color;
}

QS2D_INLINE void QS2D_SetColor(const QS2D_Color c)
{
	SDL_SetRenderDrawColor(internal->render, c.r, c.g, c.b, c.a);
}

QS2D_INLINE void QS2D_Clear()
{
	SDL_RenderClear(internal->render);
}

QS2D_INLINE void QS2D_Pixel(const int x, const int y)
{
	SDL_RenderDrawPoint(internal->render, x, y);
}

QS2D_INLINE QS2D_Color QS2D_GetPixel(const int x, const int y)
{
	/*
	Uint32 pixel = 0;
	SDL_Rect rect = { x, y, 1, 1 };
	SDL_RenderReadPixels(internal->render, &rect, pixel, NULL, sizeof(Uint32)*internal->w);
	printf("<%8x> hexadecimal padded with blanks to width 8.\n", pixel);*/
	QS2D_Color c = { 0 };
	return c;
}

QS2D_INLINE void QS2D_ScreenShot(char* path_name)
{
	SDL_Surface *s = SDL_CreateRGBSurface(0, internal->w, internal->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(internal->render, NULL, SDL_PIXELFORMAT_ARGB8888, s->pixels, s->pitch);
	SDL_SaveBMP(s, path_name);
	SDL_FreeSurface(s);
}

QS2D_INLINE void QS2D_AutoRender()
{
	internal->renderOnEvent = 1;
}

QS2D_INLINE void QS2D_ManualRender()
{
	internal->renderOnEvent = 0;
}


QS2D_INLINE void QS2D_ResizeWin(const int w, const int h)
{
	SDL_SetWindowSize(internal->window, w, h);
	internal->w = w; internal->h = h;
}

QS2D_INLINE int QS2D_GetWinW()
{
	int w;
	SDL_GetWindowSize(internal->window, &w, NULL);
	return w;
}

QS2D_INLINE int QS2D_GetWinH()
{
	int h;
	SDL_GetWindowSize(internal->window, NULL, &h);
	return h;
}
