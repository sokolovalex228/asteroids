#ifndef POINT2F
#define POINT2F

#pragma once

class Point2f
{
public:

	inline Point2f()
	{
	}

	inline Point2f(float x, float y)
	{
		_xy[0] = x;
		_xy[1] = y;
	}

	inline Point2f(const Point2f& p)
	{
		operator=(p);
	}

	inline friend Point2f operator-(Point2f& p1, Point2f& p2)
	{
		return Point2f(p1[0] - p2[0], p1[1] - p2[1]);
	}

	inline Point2f& operator-()
	{
		_xy[0] = -_xy[0];
		_xy[1] = -_xy[1];

		return *this;
	}

	inline friend Point2f operator+(Point2f& p1, Point2f& p2)
	{
		return Point2f(p1[0] + p2[0], p1[1] + p2[1]);
	}

	inline float& operator[](int index)
	{
		return _xy[index];
	}

	inline operator float*()
	{
		return _xy;
	}

	inline Point2f& operator=(const Point2f& p)
	{
		_xy[0] = p.getX();
		_xy[1] = p.getY();

		return *this;
	}

	inline void setX(float x)
	{
		_xy[0] = x;
	}

	inline float getX() const
	{
		return _xy[0];
	}

	inline void setY(float y)
	{
		_xy[1] = y;
	}

	inline float getY() const
	{
		return _xy[1];
	}

private:
	float _xy[2];
};

#endif // POINT2F
