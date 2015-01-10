#include "Screen1.h"
#include "Asteroid.h"

Screen1::Screen1()
{
	_leftDown = false;
	_rightDown = false;

	_stepMove = 10.0f;

	_msTimeStep = 10;
	_msTimeShoot = 2000;
	_msTimeBetweenShoot = 0;

	_root.addChild(new Asteroid());
}

Screen1::~Screen1()
{

}

