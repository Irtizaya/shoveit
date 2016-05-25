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

int i, j, k, lvlsum, check=0;
int pressed=0,sel=0,ins=0,anim=0;
char crctr;
int wallptr, pointptr, crateptr,pix=64;
Level lvl[5] = { 1,2,3,4,5 }; //ADD LEVELS HERE
Wall W[5][81]; //ARRAY SIZES SHOULD BE SAME AS NUMBER OF LEVELS
Player Play[5];
Point P[5][81];
Crate C[5][81];

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
		for (i = 0; i < 81; i++) //CHECKING CRATES
		{
			if (C[currentlevel][i].crx == -99) break;
			else {
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

		for (i = 0; i < 81; i++){ //LEVELCHECKER
			if (C[currentlevel][i].crx == -99) break;
			else {
				lvlsum += C[currentlevel][i].crstat;
			}
		}

		if (lvlsum == 0){ //NEXT LEVEL
			
			currentlevel++;
			initialize();
		}

		for (i = 0; i < 576; i += 64) //BACKGROUND
		{
			for (j = 0; j < 576; j += 64)
			{
				iShowBMP(i, j, "mgrass.bmp");
			}
		}
		for (i = 0; i < 81; i++)//CHECKPOINTS
		{
			if (P[currentlevel][i].pox == -99) break;
			else { iShowBMP(pix*P[currentlevel][i].pox, pix*P[currentlevel][i].poy, "mpoint.bmp"); }
		}

		for (i = 0; i < 81; i++)//CRATES
		{
			if (C[currentlevel][i].crx == -99) break;

			else if (C[currentlevel][i].crstat == 0)
			{
				iShowBMP(pix*C[currentlevel][i].crx, pix*C[currentlevel][i].cry, "mblue.bmp");
			}
			else if (C[currentlevel][i].crstat == 1)
			{
				iShowBMP(pix*C[currentlevel][i].crx, pix*C[currentlevel][i].cry, "mcrate.bmp");
			}
		}
		
		for (i = 0; i < 81; i++)//WALLS
		{
			if (W[currentlevel][i].wallx == -99) break;
			else { iShowBMP(pix*W[currentlevel][i].wallx, pix*W[currentlevel][i].wally, "mwall.bmp"); }
		}

		iShowBMP(pix*Play[currentlevel].plx, pix*Play[currentlevel].ply, "mmain.bmp");//PLAYER
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

	if (key == 'r')
	{
		initialize();
	}

	if (key == 27)
	{
		if (ins == 1) ins = 0;
		initialize();
		check = 0;
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

			Play[currentlevel].move_down(currentlevel, W, C);
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
				else if (crctr == 'X') {
					P[currentlevel][pointptr].pox = j;
					P[currentlevel][pointptr].poy = 8 - i;
					pointptr++;
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