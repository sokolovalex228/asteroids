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

	static Rect fromAbs(float x1, float y1, float x2, float y2)
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

	inline void fromFloatArray(float arr[4][2])
	{
		_x = arr[0][0];
		_y = arr[0][1];

		_width = arr[1][0] - _x;
		_height = arr[2][1] - _y;
	}

	inline void toFloatArray(float arr[4][2])
	{
		arr[0][0] = _x;
		arr[0][1] = _y;

		arr[1][0] = _x + _width;
		arr[1][1] = _y;

		arr[2][0] = _x + _width;
		arr[2][1] = _y + _height;

		arr[3][0] = _x;
		arr[3][1] = _y + _height;
	}


private:
	float _x;
	float _y;
	float _width;
	float _height;
};

#endif

