#include "iGraphics.h"
#include "Wall.h"
#include "Point.h"
#include "Crate.h"
#include "Player.h"
#include "Level.h"

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int i, j, k, check=0;
int pressed=0,sel=0,ins=0,anim=0;
char crctr;
int wallptr, pointptr, crateptr;
Level lvl[1] = { 1 }; //ADD LEVELS HERE
Wall W[1][81]; //ARRAY SIZES SHOULD BE SAME AS NUMBER OF LEVELS
Player Play[1];
Point P[1][81];
Crate C[1][81];

int lvltotal = sizeof(lvl) / sizeof(lvl[0]);
int currentlevel = 0;

void initialize();

void iDraw()
{
	iClear();
	if (check == 0) //MENU
	{
		iShowBMP(0, 0, "TITLE.bmp");

		if (pressed && sel==2) iShowBMP(0, 0, "TITLEINS.bmp");
		else if (pressed && sel == 1) iShowBMP(0, 0, "TITLENG.bmp");
		if (ins == 1)
		{
			iShowBMP(0, 0, "instruction.bmp"); //ANIMATION
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
	
	if (check == 1) //GAME
	{
		for (i = 0; i < 576; i += 64) //BACKGROUND
		{
			for (j = 0; j < 576; j += 64)
			{
				iShowBMP(i, j, "mgrass.bmp");
			}
		}

		/*for (i = 0; i < 9; i++)
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
		}*/
	}
}

void iMouseMove(int mx, int my)
{
	//REQUIRED BLANK FUNCTION
}


void iMouse(int button, int state, int mx, int my)
{
	//REQUIRED BLANK FUNCTION
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


void iSpecialKeyboard(unsigned char key) //INPUTS
{
	if (key == GLUT_KEY_END) //QUIT
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

			//Play[currentlevel].move_down();
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
			//Play[currentlevel].move_up();
		}
	}

	if (key == GLUT_KEY_LEFT)
	{
		if (check == 1)
		{
			//Play[currentlevel].move_left();
		}
	}

	if (key == GLUT_KEY_RIGHT)
	{
		if (check == 1)
		{
			//Play[currentlevel].move_right();
		}
	}
}

int main()
{
	PlaySound("Goldenrod.wav", NULL, SND_LOOP | SND_ASYNC); //MUSIC
	initialize();
	iInitialize(576, 576, "SHOVE IT"); //DRAW SCREEN
	return 0;
}

void initialize(){
	for (k = 0; k < lvltotal; k++)
	{
		wallptr = 0;
		pointptr = 0;
		crateptr = 0;

		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				crctr = lvl[currentlevel].lvlar[i][j];
				if (crctr == 'W') {
					W[currentlevel][wallptr].wallx = j;
					W[currentlevel][wallptr].wally = 8 - i;
					wallptr++;
				}
				else if (crctr == 'P') {
					P[currentlevel][pointptr].pox = j;
					P[currentlevel][pointptr].poy = 8 - i;
					pointptr++;
				}
				else if (crctr == 'C') {
					C[currentlevel][crateptr].crx = j;
					C[currentlevel][crateptr].cry = 8 - i;
					crateptr++;
				}
				else if (crctr == '*') {
					Play[currentlevel].plx = j;
					Play[currentlevel].ply = 8 - i;
				}

			}
		}

	}
}