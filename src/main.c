/*
 * Example main
 *
 * Choose one with the preprocessor
 */

#define MAIN_EX 3

/*
 * 1 - Random pixel on screen with random color
 * 2 - Perlin Noise
 * 3 - Perlin Noise2
 * 4 - Test
 */


#define QS2D_IMPLEMENTATION
#include "hdr/qs2d.h"


#if MAIN_EX == 1

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

#endif

#if MAIN_EX == 2

// https://openclassrooms.com/courses/bruit-de-perlin
// Added a random hash

float PerlinPinPin(float x, float y, float res){
	float tempX, tempY;
	int x0, y0, ii, jj, gi0, gi1, gi2, gi3;
	float unit = 1.0f / sqrt(2);
	float tmp, s, t, u, v, Cx, Cy, Li1, Li2;
	float gradient2[][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},{1,0},{-1,0},{0,1},{0,-1}};
	static unsigned int perm[256];
	static unsigned int assigned[256];
	static bool trigger = true;
	if (trigger){
		for (int i = 0; i < 256; i++)
			assigned[i] = -1;

		for (int i = 0; i < 256; i++){
			int nb;
			do{
				nb = rand() % 256;
			}
			while (assigned[nb] != -1);
			assigned[nb] = 1;
			perm[i] = nb;
		}
		trigger = false;
	}
	x /= res;
	y /= res;
	x0 = (int)(x);
	y0 = (int)(y);
	ii = x0 & 255;
	jj = y0 & 255;
	gi0 = perm[ii + perm[jj]] % 8;
	gi1 = perm[ii + 1 + perm[jj]] % 8;
	gi2 = perm[ii + perm[jj + 1]] % 8;
	gi3 = perm[ii + 1 + perm[jj + 1]] % 8;
	tempX = x - x0;
	tempY = y - y0;
	s = gradient2[gi0][0] * tempX + gradient2[gi0][1] * tempY;
	tempX = x - (x0 + 1);
	tempY = y - y0;
	t = gradient2[gi1][0] * tempX + gradient2[gi1][1] * tempY;
	tempX = x - x0;
	tempY = y - (y0 + 1);
	u = gradient2[gi2][0] * tempX + gradient2[gi2][1] * tempY;
	tempX = x - (x0 + 1);
	tempY = y - (y0 + 1);
	v = gradient2[gi3][0] * tempX + gradient2[gi3][1] * tempY;
	tmp = x - x0;
	Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
	Li1 = s + Cx * (t - s);
	Li2 = u + Cx * (v - u);
	tmp = y - y0;
	Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;
	return Li1 + Cy * (Li2 - Li1);
}


int main(){
	int w = 1400, h = 800;
	QS2D_Init("Perlin Noise Boy !", w, h);

	for (int x = 0; x < w; x++)
		for (int y = 0; y < h; y++)
		{
			float value = (PerlinPinPin(x, y, 20) + 1) * 0.5f * 255;
			QS2D_Color c = {value, value, value, 255};
			QS2D_SetColor(c);
			QS2D_Pixel(x, y);
		}

	while (!QS2D_Event()){}

	QS2D_Close();
	return 0;
}

#endif

#if MAIN_EX == 3

// https://gist.github.com/nowl/828013

static int SEED;

static int hash[] = { 208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
185,248,251,245,28,124,204,204,76,36,1,107,28,234,163,202,224,245,128,167,204,
9,92,217,54,239,174,173,102,193,189,190,121,100,108,167,44,43,77,180,204,8,81,
70,223,11,38,24,254,210,210,177,32,81,195,243,125,8,169,112,32,97,53,195,13,
203,9,47,104,125,117,114,124,165,203,181,235,193,206,70,180,174,0,167,181,41,
164,30,116,127,198,245,146,87,224,149,206,57,4,192,210,65,210,129,240,178,105,
228,108,245,148,140,40,35,195,38,58,65,207,215,253,65,85,208,76,62,3,237,55,89,
232,50,217,64,244,157,199,121,252,90,17,212,203,149,152,140,187,234,177,73,174,
193,100,192,143,97,53,145,135,19,103,13,90,135,151,199,91,239,247,33,39,145,
101,120,99,3,186,86,99,41,237,203,111,79,220,135,158,42,30,154,120,67,87,167,
135,176,183,191,253,115,184,21,233,58,129,233,142,39,128,211,118,137,139,255,
114,20,218,113,154,27,127,246,250,1,8,198,250,209,92,222,173,21,88,102,219 };

int noise2(int x, int y){
	int tmp = hash[(y + SEED) % 256];
	return hash[(tmp + x) % 256];
}

float lin_inter(float x, float y, float s){
	return x + s * (y - x);
}

float smooth_inter(float x, float y, float s){
	return lin_inter(x, y, s * s * (3 - 2 * s));
}

float noise2d(float x, float y){
	int x_int = x;
	int y_int = y;
	float x_frac = x - x_int;
	float y_frac = y - y_int;
	int s = noise2(x_int, y_int);
	int t = noise2(x_int + 1, y_int);
	int u = noise2(x_int, y_int + 1);
	int v = noise2(x_int + 1, y_int + 1);
	float low = smooth_inter(s, t, x_frac);
	float high = smooth_inter(u, v, x_frac);
	return smooth_inter(low, high, y_frac);}

float perlin2d(float x, float y, float freq, int depth){
	float xa = x * freq;
	float ya = y * freq;
	float amp = 1.0;
	float fin = 0;
	float div = 0.0;

	int i;
	for (i = 0; i<depth; i++){
		div += 256 * amp;
		fin += noise2d(xa, ya) * amp;
		amp /= 2;
		xa *= 2;
		ya *= 2;
	}

	return fin / div;
}

int main(int argc, char *argv[]){
	SEED = time(NULL);
	int w = 1280, h = 720;
	QS2D_Init("Perlin Noise2 Boy !", w, h);

	for (int x = 0; x < w; x++){
		for (int y = 0; y < h; y++){
			float value = (perlin2d(x, y, 0.02f, 5) + 1) * 0.5f * 255;
			QS2D_Color c = { value, value, value, 255 };
			QS2D_SetColor(c);
			QS2D_Pixel(x, y);
		}
		QS2D_Render();
	}
		

	while (!QS2D_Event()){
		if(QS2D_Key(QS2D_KEY_RETURN)){
			QS2D_ScreenShot("screen.bmp");
		}
		if(QS2D_Key(QS2D_KEY_SPACE)){
			SEED = rand()%(rand()%200)*rand();
			for (int x = 0; x < w; x++){
				for (int y = 0; y < h; y++){
					float value = (perlin2d(x, y, 0.02f, 5) + 1) * 0.5f * 255;
					QS2D_Color c = { value, value, value, 255 };
					QS2D_SetColor(c);
					QS2D_Pixel(x, y);
				}
				QS2D_Render();
			}
		}
	}

	QS2D_Close();

	return 0;
}

#endif

#if MAIN_EX == 4

int main(int argc, char *argv[]){
	int w = 800, h = 480;
	QS2D_Init("Test", w, h);

	while (!QS2D_Event()){
		
	}

	QS2D_Close();
	return 0;
}

#endif