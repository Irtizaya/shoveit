#include "Level.h"
#include <string>

using namespace std;

Level::Level()
{
}

Level::Level(int id)
{
    int i, j;
    string str[9];
    if (id == 1)
    {
        str[0] = "OOWWWOOOO";
        str[1] = "OOWPWOOOO";
        str[2] = "OOWOWWWWO";
        str[3] = "WWWCOCPWO";
        str[4] = "WPOC*WWWO";
        str[5] = "WWWWCWOOO";
        str[6] = "OOOWPWOOO";
        str[7] = "OOOWWWOOO";
        str[8] = "OOOOOOOOO";
    }

    else if (id == 2)
    {
        str[0] = "WWWWWOOOO";
        str[1] = "WOO*WOOOO";
        str[2] = "WOCCWOWWW";
        str[3] = "WOCOWOWPW";
        str[4] = "WWWOWWWPW";
        str[5] = "OWWOOOOPW";
        str[6] = "OWOOOWOOW";
        str[7] = "OWOOOWWWW";
        str[8] = "OWWWWWOOO";
    }

    else if (id == 3)
    {
        str[0] = "OWWWWOOOO";
        str[1] = "WWOOWOOOO";
        str[2] = "WO*CWOOOO";
        str[3] = "WWCOWWOOO";
        str[4] = "WWOCOWOOO";
        str[5] = "WPCOOWOOO";
        str[6] = "WPPXPWOOO";
        str[7] = "WWWWWWOOO";
        str[8] = "OOOOOOOOO";
    }

    else if (id == 4)
    {
        str[0] = "OWWWWOOOO";
        str[1] = "OW*OWWWOO";
        str[2] = "OWOCOOWOO";
        str[3] = "WWWOWOWWO";
        str[4] = "WPWOWOOWO";
        str[5] = "WPCOOWOWO";
        str[6] = "WPOOOCOWO";
        str[7] = "WWWWWWWWO";
        str[8] = "OOOOOOOOO";
    }

    else if (id == 5)
    {
        str[0] = "OOWWWWWWO";
        str[1] = "OOWOOOOWO";
        str[2] = "WWWCCCOWO";
        str[3] = "W*OCPPOWO";
        str[4] = "WOCPPPWWO";
        str[5] = "WWWWOOWOO";
        str[6] = "OOOWWWWOO";
        str[7] = "OOOOOOOOO";
        str[8] = "OOOOOOOOO";
    }

	else if (id == 6)
	{
		str[0] = "OOWWWWWOO";
		str[1] = "WWWOO*WOO";
		str[2] = "WOOCPOWWO";
		str[3] = "WOOPCPOWO";
		str[4] = "WWWOXCOWO";
		str[5] = "OOWOOOWWO";
		str[6] = "OOWWWWWOO";
		str[7] = "OOOOOOOOO";
		str[8] = "OOOOOOOOO";
	}
	
	else if (id == 7)
	{
		str[0] = "OOWWWWOOO";
		str[1] = "OOWPPWOOO";
		str[2] = "OWWOPWWOO";
		str[3] = "OWOOCPWOO";
		str[4] = "WWOCOOWWO";
		str[5] = "WOOWCCOWO";
		str[6] = "WOO*OOOWO";
		str[7] = "WWWWWWWWO";
		str[8] = "OOOOOOOOO";
	}

	else if (id == 8)
	{
		str[0] = "WWWWWWWWO";
		str[1] = "WOOWOOOWO";
		str[2] = "WOCPPCOWO";
		str[3] = "W*CPXOWWO";
		str[4] = "WOCPPCOWO";
		str[5] = "WOOWOOOWO";
		str[6] = "WWWWWWWWO";
		str[7] = "OOOOOOOOO";
		str[8] = "OOOOOOOOO";
	}

	else if (id == 9)
	{
		str[0] = "WWWWWWOOO";
		str[1] = "WOOOOWOOO";
		str[2] = "WOCCCWWOO";
		str[3] = "WOOWPPWWW";
		str[4] = "WWOOPPCOW";
		str[5] = "OWO*OOOOW";
		str[6] = "OWWWWWWWW";
		str[7] = "OOOOOOOOO";
		str[8] = "OOOOOOOOO";
	}

	else if (id == 10)
	{
		str[0] = "WWWWWWWOO";
		str[1] = "WPPCPPWOO";
		str[2] = "WPPWPPWOO";
		str[3] = "WOCCCOWOO";
		str[4] = "WOOCOOWOO";
		str[5] = "WOCCCOWOO";
		str[6] = "WOOW*OWOO";
		str[7] = "WWWWWWWOO";
		str[8] = "OOOOOOOOO";
	}

    /* COPY THIS TO ADD NEW LEVELS
    	else if (id == x)
    {
    	str[0] = "";
    	str[1] = "";
    	str[2] = "";
    	str[3] = "";
    	str[4] = "";
    	str[5] = "";
    	str[6] = "";
    	str[7] = "";
    	str[8] = "";
    }
    */

    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            lvlar[i][j] = str[i][j];

}

Level::~Level()
{
}
