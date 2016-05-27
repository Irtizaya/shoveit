#include "iGraphics.h"
#include "Wall.h"
#include "Point.h"
#include "Crate.h"
#include "Player.h"
#include "Level.h"

#include <iostream>
#include <cstdio>
#include <string>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace std;

int i, j, k, lvlsum, check = 0, sound = 0, lvlsel = 0, inlvl = 0, ptrx = 180, ptry = 576 - 173;
int pressed = 0, sel = 0, ins = 0, anim = 0, acount = 6, back = 0;
char crctr;
int wallptr, pointptr, crateptr, pix = 64;
Level lvl[10] = { 1, 2, 3, 4, 5,6,7,8,9,10 }; //ADD LEVELS HERE
Wall W[10][81]; //ARRAY SIZES SHOULD BE SAME AS NUMBER OF LEVELS
Player Play[10];
Point P[10][81];
Crate C[10][81];

int lvltotal = sizeof(lvl) / sizeof(lvl[0]);
int currentlevel = 0;

void initialize();

void iDraw()
{
	iClear();

	glutReshapeWindow(576, 576);
	
	if (check == 0) //MENU
	{

		iShowBMP(0, 0, "images/TITLES.bmp");

		if (pressed && sel == 2) iShowBMP(0, 0, "images/TITLEINS1.bmp");
		else if (pressed && sel == 1) iShowBMP(0, 0, "images/TITLENG1.bmp");
		else if (pressed && sel == 3) iShowBMP(0, 0, "images/TITLES2.bmp");
		if (ins == 1)
		{
			iShowBMP(0, 0, "images/instruct.bmp"); //ANIMATION
			if (anim == 0)
			{
				iShowBMP(64 * 2.5, 64 * 1, "images/mmain.bmp");
				iShowBMP(64 * 3.5, 64 * 1, "images/mcrate.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "images/mpoint.bmp");
				anim = 1;
				Sleep(500); //iDelay(1)
			}

			else if (anim == 1)
			{
				iShowBMP(64 * 3.5, 64 * 1, "images/mmain.bmp");
				iShowBMP(64 * 4.5, 64 * 1, "images/mcrate.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "images/mpoint.bmp");
				anim = 2;
				Sleep(500);
			}

			else if (anim == 2)
			{
				iShowBMP(64 * 4.5, 64 * 1, "images/mmain.bmp");
				iShowBMP(64 * 5.5, 64 * 1, "images/mblue.bmp");
				anim = 0;
				Sleep(500);
			}
		}
		else if (inlvl == 1)
		{
			iShowBMP(0, 0, "images/lvls.bmp");
			iShowBMP(ptrx, ptry, "images/arrow1.bmp");
		}
	}

	else if (check == 1) //GAME
	{
		for (i = 0; i < 81; i++) //CHECKING CRATES
		{
			if (C[currentlevel][i].crx == -99) break;
			else
			{
				for (j = 0; j < 81; j++)//CHECKPOINTS
				{
					if (P[currentlevel][j].pox == -99) break;
					else if (P[currentlevel][j].pox == C[currentlevel][i].crx && P[currentlevel][j].poy == C[currentlevel][i].cry)
					{
						C[currentlevel][i].crstat = 0;
						break;
					}
					else C[currentlevel][i].crstat = 1;
				}
			}
		}

		lvlsum = 0;

		for (i = 0; i < 81; i++)  //LEVELCHECKER
		{
			if (C[currentlevel][i].crx == -99) break;
			else
			{
				lvlsum += C[currentlevel][i].crstat;
			}
		}

		for (i = 0; i < 576; i += 64) //BACKGROUND
		{
			for (j = 0; j < 576; j += 64)
			{
				iShowBMP(i, j, "images/mgrass.bmp");
			}
		}
		for (i = 0; i < 81; i++)//CHECKPOINTS
		{
			if (P[currentlevel][i].pox == -99) break;
			else
			{
				iShowBMP(pix*P[currentlevel][i].pox, pix*P[currentlevel][i].poy, "images/mpoint.bmp");
			}
		}

		for (i = 0; i < 81; i++)//CRATES
		{
			if (C[currentlevel][i].crx == -99) break;

			else if (C[currentlevel][i].crstat == 0)
			{
				iShowBMP(pix*C[currentlevel][i].crx, pix*C[currentlevel][i].cry, "images/mblue.bmp");
			}
			else if (C[currentlevel][i].crstat == 1)
			{
				iShowBMP(pix*C[currentlevel][i].crx, pix*C[currentlevel][i].cry, "images/mcrate.bmp");
			}
		}

		for (i = 0; i < 81; i++)//WALLS
		{
			if (W[currentlevel][i].wallx == -99) break;
			else
			{
				iShowBMP(pix*W[currentlevel][i].wallx, pix*W[currentlevel][i].wally, "images/mwall.bmp");
			}
		}

		iShowBMP(pix*Play[currentlevel].plx, pix*Play[currentlevel].ply, "images/mmain.bmp");//PLAYER

		if (lvlsum == 0)  //NEXT LEVEL
		{

			if (currentlevel == lvltotal - 1)
			{
				iShowBMP(0, 0, "images/GAME.bmp");
			}
			else if (acount == 6)
			{
				acount--;
			}

			else if (acount == 5)
			{
				Sleep(500);
				iShowBMP(0, 0, "images/NEW1.bmp");
				acount--;
			}
			else if (acount == 4)
			{
				Sleep(500);
				iShowBMP(0, 0, "images/NEW2.bmp");

				acount--;
			}
			else if (acount == 3)
			{
				Sleep(500);
				iShowBMP(0, 0, "images/NEW3.bmp");

				acount--;
			}
			else if (acount == 2)
			{
				Sleep(500);
				iShowBMP(0, 0, "images/NEW4.bmp");

				acount--;
			}
			else if (acount == 1)
			{
				Sleep(500);
				iShowBMP(0, 0, "images/NEW5.bmp");

				acount--;
			}
			else if (acount == 0)
			{
				Sleep(500);
				currentlevel++;
				initialize();
			}
		}
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
		if (check == 0)
		{
			if (ins == 1)
			{
				/*ins = 0;
				check = 0;
				sel = 2;*/
			}
			else if (inlvl == 1)
			{
				inlvl = 0;
				currentlevel = lvlsel;
				initialize();
				check = 1;

			}
			else if (sel == 1)
			{
				inlvl = 1;
				//check = 1;
			}
			else if (sel == 2)
			{
				ins = 1;
			}
			else if (sel == 3 && sound == 0)
			{
				PlaySound(0, 0, 0);
				sound = 1;
			}
			else if (sel == 3 && sound == 1)
			{
				PlaySound("Goldenrod.wav", NULL, SND_LOOP | SND_ASYNC);
				sound = 0;
			}
		}
		else if (check == 1)
		{
			if (acount < 6)
			{
				currentlevel++;
				initialize();
			}
		}

	}

	if (key == 27)
	{
		currentlevel = 0;
		if (ins == 1)ins = 0;
		sel = 1;
		inlvl = 0;
		lvlsel = 0;
		initialize();
		ptrx = 180;
		ptry = 576 - 173;
		check = 0;
	}

	if (key == 'r' || key == 'R')
	{
		initialize();
	}
}


void iSpecialKeyboard(unsigned char key) //INPUTS
{
	if (key == GLUT_KEY_END) //QUIT
	{
		exit(0);
	}

	if (key == GLUT_KEY_DOWN)
	{
		if (check == 0)
		{
			pressed++;
			sel++;
			if (sel > 3) sel = 1;
			if (inlvl == 1)
			{
				ptry -= 40; lvlsel++;
				if (ptry < 43)
				{
					ptry = 403;
					lvlsel = 1;
				}
			}


		}
		if (check == 1)
		{

			Play[currentlevel].move_down(currentlevel, W, C);
		}
	}

	if (key == GLUT_KEY_UP)
	{
		if (check == 0)
		{
			pressed++;
			sel--;
			if (sel < 1) sel = 3;
			if (inlvl == 1)
			{
				ptry += 40; lvlsel--;
				if (ptry > 403)
				{
					ptry = 43;
					lvlsel = 9;
				}
			}
		}
		if (check == 1)
		{
			Play[currentlevel].move_up(currentlevel, W, C);
		}
	}

	if (key == GLUT_KEY_LEFT)
	{
		if (check == 1)
		{
			Play[currentlevel].move_left(currentlevel, W, C);
		}
	}

	if (key == GLUT_KEY_RIGHT)
	{
		if (check == 1)
		{
			Play[currentlevel].move_right(currentlevel, W, C);
		}
	}
}

int main()
{
	PlaySound("Goldenrod.wav", NULL, SND_LOOP | SND_ASYNC); //MUSIC

	initialize();
	iInitialize(576, 576, "Shove It!"); //DRAW SCREEN
	return 0;
}

void initialize()
{
	acount = 6;
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
				if (crctr == 'W')
				{
					W[currentlevel][wallptr].wallx = j;
					W[currentlevel][wallptr].wally = 8 - i;
					wallptr++;
				}
				else if (crctr == 'P')
				{
					P[currentlevel][pointptr].pox = j;
					P[currentlevel][pointptr].poy = 8 - i;
					pointptr++;
				}
				else if (crctr == 'C')
				{
					C[currentlevel][crateptr].crx = j;
					C[currentlevel][crateptr].cry = 8 - i;
					crateptr++;
				}
				else if (crctr == 'X')
				{
					P[currentlevel][pointptr].pox = j;
					P[currentlevel][pointptr].poy = 8 - i;
					pointptr++;
					C[currentlevel][crateptr].crx = j;
					C[currentlevel][crateptr].cry = 8 - i;
					crateptr++;
				}
				else if (crctr == '*')
				{
					Play[currentlevel].plx = j;
					Play[currentlevel].ply = 8 - i;
				}
			}
		}
	}
}