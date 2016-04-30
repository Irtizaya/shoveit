# include "iGraphics.h"



int gpositionx = 70, gpositiony = 70, spositionx=210, spositiony=210;
void iDraw()
{
	
	iClear();
	iShowBMP(gpositionx, gpositiony, "main2.bmp");
	

	iShowBMP(spositionx, spositiony, "crate.bmp");
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
		if (gpositiony == spositiony+70  && gpositionx == spositionx)
		{
			spositiony -= 70;
		}
		gpositiony-=70;
	}
	if (key == GLUT_KEY_UP)
	{
		
		if (gpositiony == spositiony - 70  && gpositionx == spositionx)
		{
			spositiony += 70;
		}
		gpositiony+=70;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (gpositionx == spositionx + 70  && gpositiony==spositiony)
		{
			spositionx -= 70;
		}
		gpositionx-=70;
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (gpositionx == spositionx - 70  && gpositiony == spositiony)
		{
			spositionx += 70;
		}
		gpositionx+=70;
	}

	
}

int main()
{
	
	iInitialize(630, 630, "demooo");
	return 0;
}