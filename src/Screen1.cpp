#include "Screen1.h"

Screen1::Screen1()
{
	_leftDown = false;
	_rightDown = false;

	_stepMove = 10.0f;

	_msTimeStep = 10;
	_msTimeShoot = 2000;
	_msTimeBetweenShoot = 0;
}

Screen1::~Screen1()
{

}

