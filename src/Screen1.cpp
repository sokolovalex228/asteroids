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
	//const char* fileName = "data/out_atlas.png";
	const char* fileName = "data/asteroid.png";

	if(true == _texture_atlas.load(fileName))
	{
		printf("(%s) id=%d\n", fileName, _texture_atlas.getId());

		_texture_atlas.draw();
	}
	else
	{
		printf("Error: (%s)\n", fileName);
	}

	fflush(stdout);

	if(Button* pButton = new Button())
	{
		pButton->construct("left", Rect(0,0, 100, 100), Rect(0, 0, 1, 1));

		_root.addChild(pButton);
	}

//	_root.addChild(new Button("right"));

	_root.addChild(new Asteroid());


	return false;
}

void Screen1::draw()
{
	Object::drawObject(&_root);
}
