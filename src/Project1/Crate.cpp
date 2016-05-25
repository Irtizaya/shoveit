#include "Crate.h"

Crate::Crate()
{
	crx = -99;
	cry = -99;
	crstat = 0;
}

Crate::Crate(int x, int y)
{
	crx = x;
	cry = y;
	crstat = 1;
}

Crate::~Crate()
{
}
