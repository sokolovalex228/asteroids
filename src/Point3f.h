#ifndef _POINT3F_H_
#define _POINT3F_H_

class Point3f
{
public:

	inline Point3f()
	{
		//_xy[0] =_xy[1] = _xy[2] = 0.0f;
	}

	inline Point3f(float x, float y, float z)
	{
		_xy[0] = x;
		_xy[1] = y;
		_xy[2] = z;
	}

	inline Point3f(const Point3f& p)
	{
		operator=(p);
	}

	inline friend Point3f operator-(Point3f& p1, Point3f& p2)
	{
		return Point3f(p1[0] - p2[0], p1[1] - p2[1], p1[2] - p2[2]);
	}

	inline Point3f& operator-()
	{
		_xy[0] = -_xy[0];
		_xy[1] = -_xy[1];
		_xy[2] = -_xy[2];

		return *this;
	}

	inline friend Point3f operator+(Point3f& p1, Point3f& p2)
	{
		return Point3f(p1[0] + p2[0], p1[1] + p2[1], p1[2] + p2[2]);
	}

	inline float& operator[](int index)
	{
		return _xy[index];
	}

	inline operator float*()
	{
		return _xy;
	}

	inline Point3f& operator=(const Point3f& p)
	{
		_xy[0] = p.getX();
		_xy[1] = p.getY();
		_xy[2] = p.getZ();

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

	inline void setZ(float z)
	{
		_xy[2] = z;
	}

	inline float getZ() const
	{
		return _xy[2];
	}

private:
	float _xy[3];
};

#endif
