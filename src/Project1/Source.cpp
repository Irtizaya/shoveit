#include "iGraphics.h"
#include "Wall.h"
#include "Point.h"
#include"Crate.h"
#include"Player.h"




Player Pl;
Wall W;
Point P;
Crate C;
//int gpositionx = 64 * 4, gpositiony = 64 * 4;
int i, j;
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
		iShowBMP(64 * C.posx[i], 64*C.posy[i], "mcrate.bmp");
	}

	iShowBMP(Pl.gpositionx, Pl.gpositiony, "mmain.bmp");
	
	for (j = 0; j < 4;j++)
	{
		for (i = 0; i < 4;i++)
		{ 
			if (C.posx[i] * 64 == P.cposx[j] * 64 && C.posy[i] * 64 == P.cposy[j] * 64)
			{
				iShowBMP(C.posx[i] * 64, C.posy[i] * 64, "mblue.bmp");
			}
		
		}
		
	}
	
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
		/*for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64*C.posy[i] + 64 && gpositionx == 64*C.posx[i])
			{
				C.posy[i] --;
				break;
			}
		}
		gpositiony -= 64;*/

		Pl.move_down(&C);
		
		
	
	}
	if (key == GLUT_KEY_UP)
	{
		
		/*for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * C.posy[i] - 64 && gpositionx == 64 * C.posx[i])
			{
				C.posy[i] ++;
				break;
			}
			
		}
		gpositiony+=64;*/

		Pl.move_up(&C);
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		
		/*for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * C.posy[i]  && gpositionx == 64 * C.posx[i] + 64)
			{
				C.posx[i] --;
				break;
			}
		}
		gpositionx-=64;*/
		Pl.move_left(&C);
		
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		
		/*for (i = 0; i < 4; i++)
		{
			if (gpositiony == 64 * C.posy[i] && gpositionx == 64 * C.posx[i]-64)
			{
				C.posx[i] ++;
				break;
			}
		}
		gpositionx+=64;*/

		Pl.move_right(&C);
		
	}

	
}

int main()
{
	
	iInitialize(576, 576, "demooo");
	return 0;
}