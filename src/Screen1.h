#ifndef _SCREEN1_H_
#define _SCREEN1_H_

class Screen1
{
public:
	Screen1();
	~Screen1();

private:

	float _stepMove;

	int _msTimeStep;
	int _msTimeShoot;
	int _msTimeBetweenShoot;

	bool _leftDown;
	bool _rightDown;
};

#endif

