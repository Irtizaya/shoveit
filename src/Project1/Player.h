#pragma once
#include"Crate.h"

class Player
{
public:
	Player();
	Player(int x, int y);
	int plx;
	int ply;
	void move_up();
	void move_down();
	void move_right();
	void move_left();
	~Player();
};

