# include "iGraphics.h"



int gpositionx = 64, gpositiony = 64, spositionx=192, spositiony=192, epositionx=320, epositiony=320;
void iDraw()
{
	
	iClear();
	iShowBMP(gpositionx, gpositiony, "mmain.bmp");
	iShowBMP(epositionx, epositiony, "mpoint.bmp");
	

	iShowBMP(spositionx, spositiony, "mcrate.bmp");
	if (spositionx == epositionx && spositiony == epositiony)
	{
		iShowBMP(spositionx, epositiony, "mblue.bmp");
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
		if (gpositiony == spositiony+64  && gpositionx == spositionx)
		{
			spositiony -= 64;
		}
		gpositiony-=64;
		
	
	}
	if (key == GLUT_KEY_UP)
	{
		
		if (gpositiony == spositiony - 64  && gpositionx == spositionx)
		{
			spositiony += 64;
		}
		gpositiony+=64;
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (gpositionx == spositionx + 64  && gpositiony==spositiony)
		{
			spositionx -= 64;
		}
		gpositionx-=64;
		
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (gpositionx == spositionx - 64  && gpositiony == spositiony)
		{
			spositionx += 64;
		}
		gpositionx+=64;
		
	}

	
}

int main()
{
	
	iInitialize(576, 576, "demooo");
	return 0;
}