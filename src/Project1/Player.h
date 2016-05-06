#pragma once
#include"Crate.h"
class Player
{
public:
	Player();
	int gpositionx =64* 4, gpositiony = 64*4, i;
	void move_right(Crate *C);
	void move_left(Crate *C);
	void move_up(Crate *C);
	void move_down(Crate *C);
	~Player();
};

