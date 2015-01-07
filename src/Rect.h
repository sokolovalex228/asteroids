#ifndef _RECT_H_
#define _RECT_H_

#include "defs.h"

class Rect
{
public:

	Rect() : _x(0.0f), _y(0.0f), _width(0.0f), _height(0.0f)
	{
	}

	Rect(float x, float y, float width, float height) : _x(x), _y(y), _width(width), _height(height)
	{

	}

	Rect(const Rect& rect)
	{
		operator=(rect);
	}

	Rect& operator=(const Rect& rect)
	{
		_x = rect.getX();
		_y = rect.getY();
		_width = rect.getWidth();
		_height = rect.getHeight();

		return *this;
	}

	static Rect fromAbs(double x1, double y1, double x2, double y2)
	{
		return Rect(x1, y1, x2 - x1, y2 - y1);
	}

	inline float getX() const
	{
		return _x;
	}

	inline float getY() const
	{
		return _y;
	}

	inline float getWidth() const
	{
		return _width;
	}

	inline float getHeight() const
	{
		return _height;
	}

private:
	float _x;
	float _y;
	float _width;
	float _height;
};

#endif

