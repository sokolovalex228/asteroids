#include "Screen1.h"
#include "Asteroid.h"
#include "Button.h"

Screen1::Screen1()
{
	reset();
}

Screen1::~Screen1()
{

}

void Screen1::reset()
{
	_leftDown = false;
	_rightDown = false;

	_stepMove = 10.0f;

	_msTimeStep = 10;
	_msTimeShoot = 2000;
	_msTimeBetweenShoot = 0;
}

bool Screen1::init()
{
	_root.addChild(new Button("left"));
	_root.addChild(new Button("right"));

	_root.addChild(new Asteroid());


	return false;
}

void Screen1::draw()
{
	Object::drawObject(&_root);
}
