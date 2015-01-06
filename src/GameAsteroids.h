#ifndef GAMEASTEROIDS_H
#define GAMEASTEROIDS_H

#include "defs.h"

#include "VectorPtr.h"
#include "Point2f.h"

class GameAsteroids
{
public:
	GameAsteroids();
	~GameAsteroids();

	bool init();
	bool run();
	bool done();

	void render();
	void mouseMove(int x, int y);
	void mouseLeft(int x, int y, bool down);
	void resize(int width, int height);
	void initialize();
};

extern GameAsteroids gameAsteroids;

#endif // GAMEASTEROIDS_H
