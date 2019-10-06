#pragma once

//////////////////////////////////
/*
Prototypes
*/
//////////////////////////////////

/* init */
QS2D_DEF void QS2D_Init(const char* name, const int width, const int height);
QS2D_DEF void QS2D_Close();
QS2D_DEF void QS2D_Log(const char* format, ...);

/* rendering */
QS2D_DEF void QS2D_Screen_Render();
QS2D_DEF void QS2D_Screen_Clear();
QS2D_DEF void QS2D_Screen_AutoRender();
QS2D_DEF void QS2D_Screen_ManualRender();

/* event */
QS2D_DEF int QS2D_Input_Handle();
QS2D_DEF void QS2D_Quit();
QS2D_DEF bool QS2D_Key_IsPressing(int button);

/* drawing */
QS2D_DEF QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b);
QS2D_DEF void QS2D_Draw_ColorSet(QS2D_Color c);
QS2D_DEF void QS2D_Draw_Pixel(const float x, const float y);
QS2D_DEF void QS2D_Draw_Rect(const float x, const float y, const float w, const float h);


/* Screen */
QS2D_DEF void QS2D_Screen_SetBGColor(QS2D_Color c);
QS2D_DEF QS2D_Color QS2D_Screen_GetBGColor();
QS2D_DEF void QS2D_Screen_Resize(int w, int h);
QS2D_DEF int QS2D_Screen_GetWidth();
QS2D_DEF int QS2D_Screen_GetHeight();
QS2D_DEF void QS2D_Screen_Save(const char* path_name);

/* value */
QS2D_DEF QS2D_Color QS2D_Screen_GetPixel(int x, int y);