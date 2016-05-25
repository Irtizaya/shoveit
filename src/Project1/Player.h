#pragma once
#include"Crate.h"
#include"Wall.h"

class Player
{
public:
	Player();
	Player(int x, int y);
	int plx;
	int ply;
	void move_up(int x, Wall W[][81], Crate C[][81]);
	void move_down(int x, Wall W[][81], Crate C[][81]);
	void move_right(int x, Wall W[][81], Crate C[][81]);
	void move_left(int x, Wall W[][81], Crate C[][81]);
	~Player();
};

