# QS2D : Quick Sdl2 Draw

A simple header-only library written in C to handle draw, input and window quick hover the SDL2.

## Dependency

    -SDL2 - Only the 2.0.10 because it use the new float drawing function

## Example :

Fill screen with randomly colored Pixel.

```c
#define QS2D_IMPLEMENTATION
#include <qs2d.h>

int main(int argc, char ** argv)
{
	const int width = 800, height = 480;
	QS2D_Init("Random pixel color", width, height);
	
	while (QS2D_Event())
		for(int i = 0; i < width; i++)
			for (int j = 0; j < height; j++)
			{
				QS2D_Draw_ColorSet(QS2D_Color_New(rand() % 255, rand() % 255, rand() % 255 ));
				QS2D_Draw_Pixel(i, j);
			}

	QS2D_Close();
	return 0;
}
```

