#ifndef _GAMEASTEROIDS_H_
#define _GAMEASTEROIDS_H_

#include "defs.h"

#include "VectorPtr.h"
#include "Point3f.h"
#include "VBO.h"
#include "Screen1.h"

class GameAsteroids
{
public:
	GameAsteroids();
	~GameAsteroids();

	bool initialize();
	void draw();
	void mouseMove(int x, int y);
	void mouseLeft(int x, int y, bool down);
	void resize(int width, int height);
	void done();

private:
	bool run();
	void clearScreen();
	void drawCamera();

	void setViewport(int width, int height);

private:
	Screen1 screen1;
	int _widthView;
	int _heightView;
};

extern GameAsteroids gameAsteroids;

#endif
