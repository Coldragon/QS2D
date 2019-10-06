///////////////////////////////////////////////////////////////////////
///////////            QS2D : Quick SDL2 Drawer           /////////////
///////////////////////////////////////////////////////////////////////
/* 
MIT License
Copyright(c) 2019 WARLUS Dylan
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef QS2D_INCLUDE_QS2D_H
#define QS2D_INCLUDE_QS2D_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#define QS2D_VERSION "012"
#ifdef QS2D_USE_STATIC
#define QS2D_DEF static
#else
#define QS2D_DEF extern
#endif
#ifdef QS2D_USE_DOUBLE
#define QS2D_Float double
#else
#define QS2D_Float float
#endif
#ifdef QS2D_INCLUDE_STBIMAGE
#include QS2D_INCLUDE_STBIMAGE
#endif
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
QS2D_DEF void QS2D_Init(const char* name, const int width, const int height);
QS2D_DEF void QS2D_Close();
QS2D_DEF void QS2D_Log(const char* format, ...);
QS2D_DEF void QS2D_Screen_Render();
QS2D_DEF void QS2D_Screen_Clear();
QS2D_DEF void QS2D_Screen_AutoRender();
QS2D_DEF void QS2D_Screen_ManualRender();
QS2D_DEF void QS2D_Screen_AutoClear();
QS2D_DEF void QS2D_Screen_ManualClear();
QS2D_DEF int QS2D_Input_Handle();
QS2D_DEF void QS2D_Quit();
QS2D_DEF bool QS2D_Key_IsPressing(int button);
QS2D_DEF bool QS2D_Key_OnPress(const int button);
QS2D_DEF bool QS2D_Key_OnRelease(const int button);
QS2D_DEF QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b);
QS2D_DEF void QS2D_Draw_ColorSet(QS2D_Color c);
QS2D_DEF void QS2D_Draw_Pixel(const float x, const float y);
QS2D_DEF void QS2D_Draw_Rect(const float x, const float y, const float w, const float h);
QS2D_DEF void QS2D_Draw_FilledRect(const float x, const float y, const float w, const float h);
QS2D_DEF void QS2D_Draw_Line(const float x1, const float y1, const float x2, const float y2);
QS2D_DEF void QS2D_Draw_Image(QS2D_Image* image, const float x, const float y, const float scale_w, const float scale_h, const float degree_rotation);
QS2D_DEF void QS2D_Screen_SetBGColor(QS2D_Color c);
QS2D_DEF QS2D_Color QS2D_Screen_GetBGColor();
QS2D_DEF void QS2D_Screen_Resize(int w, int h);
QS2D_DEF int QS2D_Screen_GetWidth();
QS2D_DEF int QS2D_Screen_GetHeight();
QS2D_DEF void QS2D_Screen_Save(const char* path_name);
QS2D_DEF QS2D_Image QS2D_Image_Load(const char* path);
enum
{
	QS2D_KEY_UNKNOWN = 0,QS2D_KEY_A = 4,QS2D_KEY_B = 5, QS2D_KEY_C = 6,
	QS2D_KEY_D = 7,	QS2D_KEY_E = 8,QS2D_KEY_F = 9,	QS2D_KEY_G = 10,
	QS2D_KEY_H = 11, QS2D_KEY_I = 12,QS2D_KEY_J = 13, QS2D_KEY_K = 14,
	QS2D_KEY_L = 15, QS2D_KEY_M = 16,QS2D_KEY_N = 17, QS2D_KEY_O = 18,
	QS2D_KEY_P = 19, QS2D_KEY_Q = 20,QS2D_KEY_R = 21, QS2D_KEY_S = 22,
	QS2D_KEY_T = 23, QS2D_KEY_U = 24,QS2D_KEY_V = 25, QS2D_KEY_W = 26,
	QS2D_KEY_X = 27, QS2D_KEY_Y = 28,QS2D_KEY_Z = 29, QS2D_KEY_1 = 30,
	QS2D_KEY_2 = 31, QS2D_KEY_3 = 32,QS2D_KEY_4 = 33, QS2D_KEY_5 = 34,
	QS2D_KEY_6 = 35, QS2D_KEY_7 = 36,QS2D_KEY_8 = 37, QS2D_KEY_9 = 38,
	QS2D_KEY_0 = 39, QS2D_KEY_RETURN = 40,QS2D_KEY_ESCAPE = 41, QS2D_KEY_BACKSPACE = 42,
	QS2D_KEY_TAB = 43, QS2D_KEY_SPACE = 44,QS2D_KEY_MINUS = 45, QS2D_KEY_EQUALS = 46,
	QS2D_KEY_LEFTBRACKET = 47, QS2D_KEY_RIGHTBRACKET = 48,QS2D_KEY_BACKSLASH = 49, QS2D_KEY_NONUSHASH = 50,
	QS2D_KEY_SEMICOLON = 51, QS2D_KEY_APOSTROPHE = 52,QS2D_KEY_GRAVE = 53, QS2D_KEY_COMMA = 54,
	QS2D_KEY_PERIOD = 55, QS2D_KEY_SLASH = 56,QS2D_KEY_CAPSLOCK = 57, QS2D_KEY_F1 = 58,
	QS2D_KEY_F2 = 59, QS2D_KEY_F3 = 60,QS2D_KEY_F4 = 61, QS2D_KEY_F5 = 62,
	QS2D_KEY_F6 = 63, QS2D_KEY_F7 = 64,QS2D_KEY_F8 = 65, QS2D_KEY_F9 = 66,
	QS2D_KEY_F10 = 67, QS2D_KEY_F11 = 68,QS2D_KEY_F12 = 69, QS2D_KEY_PRINTSCREEN = 70,
	QS2D_KEY_SCROLLLOCK = 71, QS2D_KEY_PAUSE = 72,QS2D_KEY_INSERT = 73, QS2D_KEY_HOME = 74,
	QS2D_KEY_PAGEUP = 75, QS2D_KEY_DELETE = 76,QS2D_KEY_END = 77, QS2D_KEY_PAGEDOWN = 78,
	QS2D_KEY_RIGHT = 79, QS2D_KEY_LEFT = 80,QS2D_KEY_DOWN = 81, QS2D_KEY_UP = 82,
	QS2D_KEY_NUMLOCKCLEAR = 83, QS2D_KEY_KP_DIVIDE = 84,QS2D_KEY_KP_MULTIPLY = 85, QS2D_KEY_KP_MINUS = 86,
	QS2D_KEY_KP_PLUS = 87, QS2D_KEY_KP_ENTER = 88,QS2D_KEY_KP_1 = 89, QS2D_KEY_KP_2 = 90,
	QS2D_KEY_KP_3 = 91, QS2D_KEY_KP_4 = 92,QS2D_KEY_KP_5 = 93, QS2D_KEY_KP_6 = 94,
	QS2D_KEY_KP_7 = 95, QS2D_KEY_KP_8 = 96,QS2D_KEY_KP_9 = 97, QS2D_KEY_KP_0 = 98,
	QS2D_KEY_KP_PERIOD = 99, QS2D_KEY_NONUSBACKSLASH = 100,QS2D_KEY_APPLICATION = 101, QS2D_KEY_POWER = 102,
	QS2D_KEY_KP_EQUALS = 103, QS2D_KEY_F13 = 104,QS2D_KEY_F14 = 105, QS2D_KEY_F15 = 106,
	QS2D_KEY_F16 = 107, QS2D_KEY_F17 = 108,QS2D_KEY_F18 = 109, QS2D_KEY_F19 = 110,
	QS2D_KEY_F20 = 111, QS2D_KEY_F21 = 112,QS2D_KEY_F22 = 113, QS2D_KEY_F23 = 114,
	QS2D_KEY_F24 = 115, QS2D_KEY_EXECUTE = 116,QS2D_KEY_HELP = 117, QS2D_KEY_MENU = 118,
	QS2D_KEY_SELECT = 119, QS2D_KEY_STOP = 120,QS2D_KEY_AGAIN = 121, QS2D_KEY_UNDO = 122,
	QS2D_KEY_CUT = 123, QS2D_KEY_COPY = 124,QS2D_KEY_PASTE = 125, QS2D_KEY_FIND = 126,
	QS2D_KEY_MUTE = 127, QS2D_KEY_VOLUMEUP = 128,QS2D_KEY_VOLUMEDOWN = 129, QS2D_KEY_KP_COMMA = 133,
	QS2D_KEY_KP_EQUALSAS400 = 134, QS2D_KEY_INTERNATIONAL1 = 135,QS2D_KEY_INTERNATIONAL2 = 136, QS2D_KEY_INTERNATIONAL3 = 137,
	QS2D_KEY_INTERNATIONAL4 = 138, QS2D_KEY_INTERNATIONAL5 = 139,QS2D_KEY_INTERNATIONAL6 = 140, QS2D_KEY_INTERNATIONAL7 = 141,
	QS2D_KEY_INTERNATIONAL8 = 142, QS2D_KEY_INTERNATIONAL9 = 143,QS2D_KEY_LANG1 = 144, QS2D_KEY_LANG2 = 145,
	QS2D_KEY_LANG3 = 146, QS2D_KEY_LANG4 = 147,QS2D_KEY_LANG5 = 148, QS2D_KEY_LANG6 = 149,
	QS2D_KEY_LANG7 = 150, QS2D_KEY_LANG8 = 151,QS2D_KEY_LANG9 = 152, QS2D_KEY_ALTERASE = 153,
	QS2D_KEY_SYSREQ = 154, QS2D_KEY_CANCEL = 155,QS2D_KEY_CLEAR = 156, QS2D_KEY_PRIOR = 157,
	QS2D_KEY_RETURN2 = 158, QS2D_KEY_SEPARATOR = 159,QS2D_KEY_OUT = 160, QS2D_KEY_OPER = 161,
	QS2D_KEY_CLEARAGAIN = 162, QS2D_KEY_CRSEL = 163,QS2D_KEY_EXSEL = 164, QS2D_KEY_KP_00 = 176,
	QS2D_KEY_KP_000 = 177, QS2D_KEY_THOUSANDSSEPARATOR = 178,QS2D_KEY_DECIMALSEPARATOR = 179, QS2D_KEY_CURRENCYUNIT = 180,
	QS2D_KEY_CURRENCYSUBUNIT = 181, QS2D_KEY_KP_LEFTPAREN = 182,QS2D_KEY_KP_RIGHTPAREN = 183, QS2D_KEY_KP_LEFTBRACE = 184,
	QS2D_KEY_KP_RIGHTBRACE = 185, QS2D_KEY_KP_TAB = 186,QS2D_KEY_KP_BACKSPACE = 187, QS2D_KEY_KP_A = 188,
	QS2D_KEY_KP_B = 189, QS2D_KEY_KP_C = 190,QS2D_KEY_KP_D = 191, QS2D_KEY_KP_E = 192,
	QS2D_KEY_KP_F = 193, QS2D_KEY_KP_XOR = 194,QS2D_KEY_KP_POWER = 195, QS2D_KEY_KP_PERCENT = 196,
	QS2D_KEY_KP_LESS = 197, QS2D_KEY_KP_GREATER = 198,QS2D_KEY_KP_AMPERSAND = 199, QS2D_KEY_KP_DBLAMPERSAND = 200,
	QS2D_KEY_KP_VERTICALBAR = 201, QS2D_KEY_KP_DBLVERTICALBAR = 202,QS2D_KEY_KP_COLON = 203, QS2D_KEY_KP_HASH = 204,
	QS2D_KEY_KP_SPACE = 205, QS2D_KEY_KP_AT = 206,QS2D_KEY_KP_EXCLAM = 207, QS2D_KEY_KP_MEMSTORE = 208,
	QS2D_KEY_KP_MEMRECALL = 209, QS2D_KEY_KP_MEMCLEAR = 210,QS2D_KEY_KP_MEMADD = 211, QS2D_KEY_KP_MEMSUBTRACT = 212,
	QS2D_KEY_KP_MEMMULTIPLY = 213, QS2D_KEY_KP_MEMDIVIDE = 214,QS2D_KEY_KP_PLUSMINUS = 215, QS2D_KEY_KP_CLEAR = 216,
	QS2D_KEY_KP_CLEARENTRY = 217, QS2D_KEY_KP_BINARY = 218,QS2D_KEY_KP_OCTAL = 219, QS2D_KEY_KP_DECIMAL = 220,
	QS2D_KEY_KP_HEXADECIMAL = 221, QS2D_KEY_LCTRL = 224,QS2D_KEY_LSHIFT = 225, QS2D_KEY_LALT = 226,
	QS2D_KEY_LGUI = 227, QS2D_KEY_RCTRL = 228,QS2D_KEY_RSHIFT = 229, QS2D_KEY_RALT = 230,
	QS2D_KEY_RGUI = 231, QS2D_KEY_MODE = 257,QS2D_KEY_AUDIONEXT = 258, QS2D_KEY_AUDIOPREV = 259,
	QS2D_KEY_AUDIOSTOP = 260, QS2D_KEY_AUDIOPLAY = 261,QS2D_KEY_AUDIOMUTE = 262, QS2D_KEY_MEDIASELECT = 263,
	QS2D_KEY_WWW = 264, QS2D_KEY_MAIL = 265,QS2D_KEY_CALCULATOR = 266, QS2D_KEY_COMPUTER = 267,
	QS2D_KEY_AC_SEARCH = 268, QS2D_KEY_AC_HOME = 269,QS2D_KEY_AC_BACK = 270, QS2D_KEY_AC_FORWARD = 271,
	QS2D_KEY_AC_STOP = 272, QS2D_KEY_AC_REFRESH = 273,QS2D_KEY_AC_BOOKMARKS = 274, QS2D_KEY_BRIGHTNESSDOWN = 275,
	QS2D_KEY_BRIGHTNESSUP = 276, QS2D_KEY_DISPLAYSWITCH = 277,QS2D_KEY_KBDILLUMTOGGLE = 278, QS2D_KEY_KBDILLUMDOWN = 279,
	QS2D_KEY_KBDILLUMUP = 280, QS2D_KEY_EJECT = 281,QS2D_KEY_SLEEP = 282, QS2D_KEY_APP1 = 283,
	QS2D_KEY_APP2 = 284, QS2D_KEY_AUDIOREWIND = 285,QS2D_KEY_AUDIOFASTFORWARD = 286, QS2D_KEY_SCANCODES = 512,
};
#endif
#ifdef QS2D_IMPLEMENTATION
#include <time.h>
#include <stdlib.h>
#ifndef _MSC_VER
#ifdef __cplusplus
#define QS2D_INLINE inline
#else
#define QS2D_INLINE
#endif
#else
#define QS2D_INLINE __forceinline
#endif
static QS2D_Data *internal;
#include <stdio.h>
#ifdef QS2D_INCLUDE_STBIMAGE
#define STB_IMAGE_IMPLEMENTATION
#include QS2D_INCLUDE_STBIMAGE
#endif
#include <string.h>
#include <ctype.h>
QS2D_INLINE void QS2D_Init(const char* name, const int width, const int height)
{
	srand(time(NULL));
	internal = (QS2D_Data*)calloc(1, sizeof(QS2D_Data));
	if (internal == NULL)
		exit(1);
	internal->background_color = QS2D_Color_New(0, 0, 0);
	internal->quit = 0;
	internal->autoRender = 1;
	internal->autoClear = 1;
	internal->w = width;
	internal->h = height;
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
			if (internal->input.is_pressing[event.key.keysym.scancode] == 0)
			{
				internal->input.is_pressing[event.key.keysym.scancode] = 1;
				internal->input.on_press[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
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
QS2D_INLINE QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b)
{
	const QS2D_Color color = { r, g, b};
	return color;
}
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
	SDL_FRect my_rect = { x, y, image->w * (scale_w == 0 ? 1 : scale_w), image->h * (scale_h == 0 ? 1 : scale_h) };
	SDL_RenderCopyExF(internal->render, image->handle, NULL, &my_rect, degree_rotation, NULL, SDL_FLIP_NONE);
}
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
