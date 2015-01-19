#include "GameAsteroids.h"

GameAsteroids gameAsteroids;

GameAsteroids::GameAsteroids() : _width(0), _height(0)
{

}

GameAsteroids::~GameAsteroids()
{
}

bool GameAsteroids::run()
{
	printf("%s\n", __FUNCTION__);
	return true;
}

void GameAsteroids::done()
{

}

void GameAsteroids::clearScreen()
{
	glClearColor((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void GameAsteroids::drawCamera()
{

}

void GameAsteroids::draw()
{
	clearScreen();

	drawCamera();

	screen1.draw();
}

void GameAsteroids::mouseMove(int x, int y)
{

}

void GameAsteroids::mouseLeft(int x, int y, bool down)
{

}

void GameAsteroids::setViewport(int width, int height)
{
	_width = width;
	_height = height;

	glViewport(0, 0, _width, _height);

	printf("_width=%d, _height=%d\n", _width, _height);
}

void GameAsteroids::resize(int width, int height)
{
	setViewport(width, height);
}

bool GameAsteroids::initialize()
{
	screen1.init();
	Point3f p;
	VectorPtr<Point3f> v;

	return false;
}
