#pragma once

//////////////////////////////////
/*
Prototypes
*/
//////////////////////////////////

/* init */

QS2D_DEF void QS2D_Init(char* name, const int width, const int height);
QS2D_DEF void QS2D_Close();

/* rendering */
QS2D_DEF void QS2D_Render();
QS2D_DEF void QS2D_Clear();
QS2D_DEF void QS2D_AutoRender();
QS2D_DEF void QS2D_ManualRender();

/* event */
QS2D_DEF int QS2D_Event();
QS2D_DEF void QS2D_Quit();
QS2D_DEF bool QS2D_Key(int button);

/* drawing */
QS2D_DEF QS2D_Color QS2D_NewColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
QS2D_DEF void QS2D_SetColor(QS2D_Color c);
QS2D_DEF void QS2D_Pixel(int x, int y);
QS2D_DEF void QS2D_ScreenShot(char* path_name);

/* window */
QS2D_DEF void QS2D_ResizeWin(int w, int h);
QS2D_DEF int QS2D_GetWinW();
QS2D_DEF int QS2D_GetWinH();

/* value */
QS2D_DEF QS2D_Color QS2D_GetPixel(int x, int y);

