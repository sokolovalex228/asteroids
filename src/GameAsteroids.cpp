#include "GameAsteroids.h"

GameAsteroids gameAsteroids;

GameAsteroids::GameAsteroids() : _widthView(0), _heightView(0)
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, _widthView, _heightView);
	glOrtho(_widthView / -2.0, _widthView / 2.0, _heightView / -2.0, _heightView / 2.0, -1000.0, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void GameAsteroids::draw()
{
	clearScreen();

	drawCamera();

	screen1.draw();

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glutWireSphere(200.0f, 10, 10);
}

void GameAsteroids::mouseMove(int x, int y)
{

}

void GameAsteroids::mouseLeft(int x, int y, bool down)
{
	if(true == down)
	{

	}
	else
	{

	}
}

void GameAsteroids::setViewport(int width, int height)
{
	_widthView = width;
	_heightView = height;

	glViewport(0, 0, _widthView, _heightView);

	printf("_width=%d, _height=%d\n", _widthView, _heightView);
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
