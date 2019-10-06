#pragma once
#include <stdio.h>

#ifdef QS2D_INCLUDE_STBIMAGE
#define STB_IMAGE_IMPLEMENTATION
#include QS2D_INCLUDE_STBIMAGE
#endif

#include <string.h>
#include <ctype.h>

///////////////////////////////////////
/*
Functions
*/
///////////////////////////////////////

/* init */
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
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
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
QS2D_INLINE void QS2D_Log(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

/* rendering */
QS2D_INLINE void QS2D_Screen_Render()
{
	SDL_RenderPresent(internal->render);
}
QS2D_INLINE void QS2D_Screen_Clear()
{
	SDL_SetRenderDrawColor(internal->render, internal->background_color.r, internal->background_color.g, internal->background_color.b, 255);
	SDL_RenderClear(internal->render);
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

/* event */
QS2D_INLINE int QS2D_Input_Handle()
{
	static SDL_Event event;

	for (int i = 0; i < 512; i++)
	{
		internal->input.on_press[i] = 0;
		internal->input.on_release[i] = 0;
	}
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			internal->quit = 1;
			break;
		case SDL_KEYDOWN:
			//internal->input.is_pressing[event.key.keysym.scancode] = 1;
			if (internal->input.is_pressing[event.key.keysym.scancode] == 0)
			{
				internal->input.is_pressing[event.key.keysym.scancode] = 1;
				internal->input.on_press[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
			//internal->input.is_pressing[event.key.keysym.scancode] = 0;
			if (internal->input.is_pressing[event.key.keysym.scancode] == 1)
			{
				internal->input.is_pressing[event.key.keysym.scancode] = 0;
				internal->input.on_release[event.key.keysym.scancode] = 1;
			}
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
QS2D_INLINE void QS2D_Quit()
{
	internal->quit = 1;
}
QS2D_INLINE bool QS2D_Key_IsPressing(const int button)
{
	if (button < 512)
	{
		return internal->input.is_pressing[button];
	}
	return 0;
}
QS2D_INLINE bool QS2D_Key_OnRelease(const int button)
{
	if (button < 512)
	{
		return internal->input.on_release[button];
	}
	return 0;
}
QS2D_INLINE bool QS2D_Key_OnPress(const int button)
{
	if (button < 512)
	{
		return internal->input.on_press[button];
	}
	return 0;
}

/* color */
QS2D_INLINE QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b)
{
	const QS2D_Color color = { r, g, b};
	return color;
}

/* drawing */
QS2D_INLINE void QS2D_Draw_ColorSet(const QS2D_Color c)
{
	SDL_SetRenderDrawColor(internal->render, c.r, c.g, c.b, 255);
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
QS2D_INLINE void QS2D_Draw_FilledRect(const float x, const float y, const float w, const float h)
{
	SDL_FRect rect = { x,y,w,h };
	SDL_RenderFillRectF(internal->render, &rect);
}
QS2D_INLINE void QS2D_Draw_Line(const float x1, const float y1, const float x2, const float y2)
{
	SDL_RenderDrawLineF(internal->render, x1, y1, x2, y2);
}
QS2D_INLINE void QS2D_Draw_Image(QS2D_Image * image, const float x, const float y, const float scale_w, const float scale_h, const float degree_rotation)
{
	SDL_FRect my_rect = { x, y, image->w * scale_w == 0 ? 1 : scale_w, image->h * scale_h == 0 ? 1 : scale_h };
	SDL_RenderCopyExF(internal->render, image->handle, NULL, &my_rect, degree_rotation, NULL, SDL_FLIP_NONE);
}

/* screen */
QS2D_INLINE void QS2D_Screen_SetBGColor(QS2D_Color c)
{
	internal->background_color = c;
}
QS2D_INLINE QS2D_Color QS2D_Screen_GetBGColor()
{
	return internal->background_color;
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
QS2D_INLINE void QS2D_Screen_Save(const char* path_name)
{
	SDL_Surface* s = SDL_CreateRGBSurface(0, internal->w, internal->h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_RenderReadPixels(internal->render, NULL, SDL_PIXELFORMAT_ARGB8888, s->pixels, s->pitch);
	SDL_SaveBMP(s, path_name);
	SDL_FreeSurface(s);
}

/* image */
QS2D_INLINE const char* GetExtension(const char* string_)
{
	char const* ex = strrchr(string_, '.');
	if (!ex || ex == string_)
	{
		return "";
	}
	return ex + 1;
}
#ifdef _WIN32 || _WIN64
#define QS2D_CROSSPLATFORM_STRCICMP(A, B) _stricmp(A, B)
#else
#include <strings.h>
#define QS2D_CROSSPLATFORM_STRCICMP(A, B) strcasecmp(A, B);
#endif

QS2D_INLINE QS2D_Image QS2D_Image_Load(const char* path)
{
	const char* extension = GetExtension(path);
	QS2D_Image image = { 0 };
	if (!QS2D_CROSSPLATFORM_STRCICMP(extension, "BMP"))
	{
		SDL_Surface* surf = SDL_LoadBMP(path);
		if (surf)
		{
			image.handle = SDL_CreateTextureFromSurface(internal->render, surf);
			SDL_QueryTexture(image.handle, NULL, NULL, &image.w, &image.h);
			SDL_FreeSurface(surf);
			QS2D_Log("Succes Loading BMP Image %s with size %d, %d", path, image.w, image.h);
			return image;
		}
		QS2D_Log("Error Loading BMP Image %s", path);
	}
	if (!QS2D_CROSSPLATFORM_STRCICMP(extension, "PNG") || !QS2D_CROSSPLATFORM_STRCICMP(extension, "JPG") || !QS2D_CROSSPLATFORM_STRCICMP(extension, "JPEG") || !QS2D_CROSSPLATFORM_STRCICMP(extension, "TGA") || !QS2D_CROSSPLATFORM_STRCICMP(extension, "GIF"))
#ifdef QS2D_INCLUDE_STBIMAGE
	{
		int req_format = STBI_rgb_alpha;
		int width, height, orig_format;
		unsigned char* data = stbi_load(path, &width, &height, &orig_format, req_format);
		if (data == NULL) {
			SDL_Log("Loading image failed: %s", stbi_failure_reason());
			exit(1);
		}
		int depth, pitch;
		Uint32 pixel_format;
		if (req_format == STBI_rgb) {
			depth = 24;
			pitch = 3 * width;
			pixel_format = SDL_PIXELFORMAT_RGB24;
		}
		else {
			depth = 32;
			pitch = 4 * width;
			pixel_format = SDL_PIXELFORMAT_RGBA32;
		}
		SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, width, height,
			depth, pitch, pixel_format);
		if (surf)
		{
			image.handle = SDL_CreateTextureFromSurface(internal->render, surf);
			if (image.handle)
			{
				image.w = width; image.h = height;
				SDL_FreeSurface(surf);
				stbi_image_free(data);
				return image;
			}
		}
		stbi_image_free(data);
	}
#else
	{
		QS2D_Log("You need to define QS2D_INCLUDE_STBIMAGE to use this file format\n");
	}
#endif
	Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	rmask = 0xff000000;
	gmask = 0x00ff0000;
	bmask = 0x0000ff00;
	amask = 0x000000ff;
#else
	rmask = 0x000000ff;
	gmask = 0x0000ff00;
	bmask = 0x00ff0000;
	amask = 0xff000000;
#endif
	static bool error_image = false;
	static SDL_Texture* error_texture_cache = NULL;
	image.w = 128; image.h = 128;
	if (error_image == false)
	{
		error_texture_cache = SDL_CreateTexture(internal->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 128, 128);
		if (error_texture_cache != NULL)
		{
			SDL_SetRenderTarget(internal->render, error_texture_cache);
			SDL_RenderClear(internal->render);
			SDL_SetRenderDrawColor(internal->render, 255, 0, 255, 255);
			SDL_Rect my_rect = { 0,0,128,128 };
			SDL_RenderDrawRect(internal->render, &my_rect);
			SDL_RenderDrawLine(internal->render, 0, 0, 128, 128);
			SDL_RenderDrawLine(internal->render, 128, 0, 0, 128);
			SDL_SetRenderTarget(internal->render, NULL);
			QS2D_Log("A dummy image has been created\n");
			image.handle = error_texture_cache;
			error_image = true;
			return image;
		}
		QS2D_Log("Error Dummy error image is not created !\n");
	}
	image.handle = error_texture_cache;
	return image;
}
#endif