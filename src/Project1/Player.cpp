#include "Player.h"

Player::Player()
{
	plx = -99;
	ply = -99;
}

Player::Player(int x, int y)
{
	plx = x;
	ply = y;
}

void Player::move_up(int x, Wall W[][81], Crate C[][81])
{
	int i, j;
	//COLLISION CHECK
	for (i = 0; i < 81; i++){ //WALL
		if (W[x][i].wallx == plx && W[x][i].wally == ply + 1)
				return;
	}

	for (i = 0; i < 81; i++){ //BOX
		if (C[x][i].crx == plx && C[x][i].cry == ply + 1){
			for (j = 0; j < 81; j++){ //WALL BEHIND BOX
				if (W[x][j].wallx == plx && W[x][j].wally == ply + 2)
					return;
			}
				C[x][i].cry += 1;
				ply += 1;
				return;
			}
	}
	
	//MOVE UP
	ply += 1;
}

void Player::move_right(int x, Wall W[][81], Crate C[][81])
{
	int i, j;
	//COLLISION CHECK
	for (i = 0; i < 81; i++){ //WALL
		if (W[x][i].wally == ply && W[x][i].wallx == plx + 1)
			return;
	}

	for (i = 0; i < 81; i++){ //BOX
		if (C[x][i].cry == ply && C[x][i].crx == plx + 1){
			for (j = 0; j < 81; j++){ //WALL BEHIND BOX
				if (W[x][j].wally == ply && W[x][j].wallx == plx + 2)
					return;
			}
			C[x][i].crx += 1;
			plx += 1;
			return;
		}
	}

	//MOVE RIGHT
	plx += 1;
}

void Player::move_left(int x, Wall W[][81], Crate C[][81])
{
	int i, j;
	//COLLISION CHECK
	for (i = 0; i < 81; i++){ //WALL
		if (W[x][i].wally == ply && W[x][i].wallx == plx - 1)
			return;
	}

	for (i = 0; i < 81; i++){ //BOX
		if (C[x][i].cry == ply && C[x][i].crx == plx - 1){
			for (j = 0; j < 81; j++){ //WALL BEHIND BOX
				if (W[x][j].wally == ply && W[x][j].wallx == plx - 2)
					return;
			}
			C[x][i].crx -= 1;
			plx -= 1;
			return;
		}
	}

	//MOVE LEFT
	plx -= 1;
}

void Player::move_down(int x, Wall W[][81], Crate C[][81])
{
	int i, j;
	//COLLISION CHECK
	for (i = 0; i < 81; i++){ //WALL
		if (W[x][i].wallx == plx && W[x][i].wally == ply - 1)
			return;
	}

	for (i = 0; i < 81; i++){ //BOX
		if (C[x][i].crx == plx && C[x][i].cry == ply - 1){
			for (j = 0; j < 81; j++){ //WALL BEHIND BOX
				if (W[x][j].wallx == plx && W[x][j].wally == ply - 2)
					return;
			}
			C[x][i].cry -= 1;
			ply -= 1;
			return;
		}
	}

	//MOVE DOWN
	ply -= 1;
}

Player::~Player()
{
}
