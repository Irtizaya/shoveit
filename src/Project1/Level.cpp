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
	if (id == 1){
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

	/* COPY THIS TO ADD NEW LEVELS
		else if (id == x){
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
