#include "iGraphics.h"
#include "Wall.h"
#include "Point.h"
#include"Crate.h"



int gpositionx = 64*4, gpositiony = 64*4, spositionx=192, spositiony=192, epositionx=320, epositiony=320;
int i,j;
Wall W;
Point P;
Crate C;
int Cposx[4] = { 3, 3, 4, 5 };
int Cposy[4] = { 4, 5, 3, 5 };
void iDraw()
{
	
	
	iClear();
	for (i = 0; i < 576; i += 64)
	{
		for (j = 0; j < 576; j += 64)
		{
			iShowBMP(i, j, "mgrass.bmp");
		}
	}
	
	
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (W.position[i][j]==1)
			{
				int posx = j*64, posy =64*( 8-i);
				iShowBMP(posx, posy, "mwall.bmp");
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		iShowBMP(64*P.cposx[i], 64*P.cposy[i], "mpoint.bmp");
	}
	for (i = 0; i < 4; i++)
	{
		iShowBMP(64 * Cposx[i], 64*Cposy[i], "mcrate.bmp");
	}

	//iShowBMP(64 * 4, 64 * 4, "mmain.bmp");


	iShowBMP(gpositionx, gpositiony, "mmain.bmp");
	//iShowBMP(epositionx, epositiony, "mpoint.bmp");
	

	//iShowBMP(spositionx, spositiony, "mcrate.bmp");
	
	for (j = 0; j < 4;j++)
	{
		for (i = 0; i < 4;i++)
		{ 
			if (Cposx[i] * 64 == P.cposx[j] * 64 && Cposy[i] * 64 == P.cposy[j] * 64)
			{
				iShowBMP(Cposx[i] * 64, Cposy[i] * 64, "mblue.bmp");
			}
		
		}
		
	}
	/*if (spositionx == epositionx && spositiony == epositiony)
	{
		iShowBMP(spositionx, epositiony, "mblue.bmp");
	}*/
	
}




void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	
}


void iKeyboard(unsigned char key)
{
	
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key==GLUT_KEY_DOWN)
	{
		for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64*Cposy[i] + 64 && gpositionx == 64*Cposx[i])
			{
				Cposy[i] --;
			}
		}
		gpositiony -= 64;
		
		/*/*if (gpositiony == spositiony+64  && gpositionx == spositionx)
		{
			spositiony -= 64;
		}
		gpositiony-=64;*/
		
	
	}
	if (key == GLUT_KEY_UP)
	{
		
		for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * Cposy[i] - 64 && gpositionx == 64 * Cposx[i])
			{
				Cposy[i] ++;
			}
		}
		/*if (gpositiony == spositiony - 64  && gpositionx == spositionx)
		{
			spositiony += 64;
		}*/
		gpositiony+=64;
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		
		for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * Cposy[i]  && gpositionx == 64 * Cposx[i] + 64)
			{
				Cposx[i] --;
			}
		}
		/*if (gpositionx == spositionx + 64  && gpositiony==spositiony)
		{
			spositionx -= 64;
		}*/
		gpositionx-=64;
		
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		
		for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * Cposy[i] && gpositionx == 64 * Cposx[i]-64)
			{
				Cposx[i] ++;
			}
		}
		/*if (gpositionx == spositionx - 64  && gpositiony == spositiony)
		{
			spositionx += 64;
		}*/
		gpositionx+=64;
		
	}

	
}

int main()
{
	
	iInitialize(576, 576, "demooo");
	return 0;
}