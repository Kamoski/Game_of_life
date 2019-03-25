#include "Cell.h"



Cell::Cell()
	:
	isAlive(0)
{
}


Cell::~Cell()
{
}

void Cell::kill()
{
	isAlive = false;
}

void Cell::revive()
{
	isAlive = true;
}

bool Cell::checkIfLives()
{
	return isAlive;
}
