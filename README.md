Quick SDL2 Draw

A basic drawing C/C++ header only library but need SDL2

```c
#define QS2D_IMPLEMENTATION
#include "hdr/qs2d.h"

int main()
{
	QS2D_Init("Random Pixel and Color", 400, 400);
	while (!QS2D_Event())
	{
		QS2D_Color color = { rand() % 255, rand() % 255, rand() % 255, 255 };
		QS2D_SetColor(color);
		QS2D_Pixel(rand() % 400, rand() % 400);
	}
	QS2D_Close();
	return 0;
}
```

Draw random pixel on screen with random color