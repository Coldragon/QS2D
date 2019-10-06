#pragma once

//////////////////////////////////
/*
Prototypes
*/
//////////////////////////////////

/* init */
QS2D_DEF void QS2D_Init(const char* name, const int width, const int height); // Init internals
QS2D_DEF void QS2D_Close(); // Release internals
QS2D_DEF void QS2D_Log(const char* format, ...); // Wrap printf

/* rendering */
QS2D_DEF void QS2D_Screen_Render(); // Render present, useful for ManualRender()
QS2D_DEF void QS2D_Screen_Clear(); // Clear back screen buffer, you need to Render() if ManualRender() is enabled
QS2D_DEF void QS2D_Screen_AutoRender(); // Auto render every Input_Handle()
QS2D_DEF void QS2D_Screen_ManualRender(); // Manually rendering, you'll need to use Render()
QS2D_DEF void QS2D_Screen_AutoClear(); // Auto Clear back buffer
QS2D_DEF void QS2D_Screen_ManualClear(); // Manually clear back buffer with _Clear()

/* event */
QS2D_DEF int QS2D_Input_Handle();
QS2D_DEF void QS2D_Quit(); // Stop the Input_Handle() and exit you're main loop
QS2D_DEF bool QS2D_Key_IsPressing(int button); // Return true while you press the key
QS2D_DEF bool QS2D_Key_OnPress(const int button); // Return true only one time when the key is down
QS2D_DEF bool QS2D_Key_OnRelease(const int button); // Return true only one time when the key is up

/* color */
QS2D_DEF QS2D_Color QS2D_Color_New(const Uint8 r, const Uint8 g, const Uint8 b);

/* drawing */
QS2D_DEF void QS2D_Draw_ColorSet(QS2D_Color c);
QS2D_DEF void QS2D_Draw_Pixel(const float x, const float y);
QS2D_DEF void QS2D_Draw_Rect(const float x, const float y, const float w, const float h);
QS2D_DEF void QS2D_Draw_FilledRect(const float x, const float y, const float w, const float h);
QS2D_DEF void QS2D_Draw_Line(const float x1, const float y1, const float x2, const float y2);

/* screen */
QS2D_DEF void QS2D_Screen_SetBGColor(QS2D_Color c);
QS2D_DEF QS2D_Color QS2D_Screen_GetBGColor();
QS2D_DEF void QS2D_Screen_Resize(int w, int h);
QS2D_DEF int QS2D_Screen_GetWidth();
QS2D_DEF int QS2D_Screen_GetHeight();
QS2D_DEF void QS2D_Screen_Save(const char* path_name);