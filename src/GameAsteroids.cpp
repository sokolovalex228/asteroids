#include "GameAsteroids.h"

GameAsteroids gameAsteroids;

GameAsteroids::GameAsteroids()
{

}

GameAsteroids::~GameAsteroids()
{
}

bool GameAsteroids::init()
{
	screen1.init();
	Point3f p;
	VectorPtr<Point3f> v;

	return false;
}

bool GameAsteroids::run()
{
	printf("%s\n", __FUNCTION__);
	return true;
}

bool GameAsteroids::done()
{
	return true;
}

void GameAsteroids::draw()
{
	glClearColor((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void GameAsteroids::mouseMove(int x, int y)
{

}

void GameAsteroids::mouseLeft(int x, int y, bool down)
{

}

void GameAsteroids::resize(int width, int height)
{

}

void GameAsteroids::initialize()
{

}
