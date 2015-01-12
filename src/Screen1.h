#ifndef _SCREEN1_H_
#define _SCREEN1_H_

#include "Object.h"

class Screen1
{
public:
	Screen1();
	~Screen1();

	bool init();
	void reset();
	void draw();

	inline Object* getRoot()
	{
		return &_root;
	}

private:
	Object _root;

	float _stepMove;

	int _msTimeStep;
	int _msTimeShoot;
	int _msTimeBetweenShoot;

	bool _leftDown;
	bool _rightDown;
};

#endif

