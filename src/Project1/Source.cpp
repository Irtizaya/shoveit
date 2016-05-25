#include "iGraphics.h"
#include "Wall.h"
#include "Point.h"
#include "Crate.h"
#include "Player.h"

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

Player Pl;
Wall W;
Point P;
Crate C;
int i, j, check=0, NGx=2,NGy=4;
int pressed=0,sel=0,ins=0,pera,anim=0;

int Cposx[4] = { 3, 3, 4, 5 };
int Cposy[4] = { 4, 5, 3, 5 };
void iDraw()
{
	iClear();
	if (check == 0)
	{
		iShowBMP(0, 0, "TITLE.bmp");

		if (pressed && sel==2) iShowBMP(0, 0, "TITLEINS.bmp");
		else if (pressed && sel == 1) iShowBMP(0, 0, "TITLENG.bmp");
		if (ins == 1)
		{
			iShowBMP(0, 0, "instruction.bmp");
			if (anim == 0)
			{
				iShowBMP(64 * 2.5, 64 * 1, "mmain.bmp");
				iShowBMP(64 * 3.5, 64 * 1, "mcrate.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "mpoint.bmp");
				anim = 1;
				iDelay(1);
			}
			
			else if (anim == 1)
			{
				iShowBMP(64 * 3.5, 64 * 1, "mmain.bmp");
				iShowBMP(64 * 4.5, 64 * 1, "mcrate.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "mpoint.bmp");
				anim = 2;
				iDelay(1);
			}

			else if (anim==2)
			{
				iShowBMP(64 * 4.5, 64 * 1, "mmain.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "mblue.bmp");
				anim = 0;
				iDelay(1);
			}
		}
	}
	
	if (check == 1)
	{
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
				if (W.position[i][j] == 1)
				{
					int posx = j * 64, posy = 64 * (8 - i);
					iShowBMP(posx, posy, "mwall.bmp");
				}
			}
		}

		for (i = 0; i < 4; i++)
		{
			iShowBMP(64 * P.cposx[i], 64 * P.cposy[i], "mpoint.bmp");
		}
		for (i = 0; i < 4; i++)
		{
			iShowBMP(64 * C.posx[i], 64 * C.posy[i], "mcrate.bmp");
		}

		iShowBMP(Pl.gpositionx, Pl.gpositiony, "mmain.bmp");

		for (j = 0; j < 4; j++)
		{
			for (i = 0; i < 4; i++)
			{
				if (C.posx[i] * 64 == P.cposx[j] * 64 && C.posy[i] * 64 == P.cposy[j] * 64)
				{
					iShowBMP(C.posx[i] * 64, C.posy[i] * 64, "mblue.bmp");
				}
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
	if (key == '\r')
	{
		if (sel == 1)
		{
			check = 1;
		}
		else if (sel == 2)
		{
			ins = 1;
		}
	}

	if (key == 27)
	{
		if (ins == 1) ins = 0;
	}
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key==GLUT_KEY_DOWN)
	{
		if (check == 0)
		{
			pressed++;
			sel++;
			if (sel > 2) sel = 1;
			
		}
		if (check == 1)
		{

			Pl.move_down(&C);
		}
	}

	if (key == GLUT_KEY_UP)
	{
		
		if (check == 0)
		{ 
			pressed++;
			sel++;
			if (sel > 2) sel = 1;
		}
		if (check == 1)
		{
			Pl.move_up(&C);
		}
	}

	if (key == GLUT_KEY_LEFT)
	{
		
		if (check == 1)
		{
			Pl.move_left(&C);
		}
	}

	if (key == GLUT_KEY_RIGHT)
	{
		
		
		if (check == 1)
		{
			Pl.move_right(&C);

		}
	}
}

int main()
{
	PlaySound("Goldenrod.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(576, 576, "SHOVE IT");
	return 0;
}