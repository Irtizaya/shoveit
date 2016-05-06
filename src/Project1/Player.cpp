#include "Player.h"


Player::Player()
{
}

void Player::move_down(Crate *C)
{
	for (i = 0; i < 4; i++)
	{
		if (gpositiony == 64 * C->posy[i] + 64 && gpositionx == 64 * C->posx[i])
		{
			C->posy[i] --;
			break;
		}
	}
	gpositiony -= 64;
}

void Player::move_up(Crate *C)
{
	for (i = 0; i < 4; i++)
	{
		if (gpositiony == 64 * C->posy[i] - 64 && gpositionx == 64 * C->posx[i])
		{
			C->posy[i] ++;
			break;
		}

	}
	gpositiony += 64;
}

void Player::move_left(Crate *C)
{
	for (i = 0; i < 4; i++)
	{
		if (gpositiony == 64 * C->posy[i] && gpositionx == 64 * C->posx[i] + 64)
		{
			C->posx[i] --;
			break;
		}
	}
	gpositionx -= 64;
}

void Player::move_right(Crate *C)
{
	for (i = 0; i < 4; i++)
	{
		if (gpositiony == 64 * C->posy[i] && gpositionx == 64 * C->posx[i] - 64)
		{
			C->posx[i] ++;
			break;
		}
	}
	gpositionx += 64;
}


Player::~Player()
{
}
