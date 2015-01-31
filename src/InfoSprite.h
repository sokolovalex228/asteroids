#ifndef INFOSPRITE_H
#define INFOSPRITE_H

#include "Rect.h"

class InfoSprite
{
public:
	InfoSprite();
	InfoSprite(const Rect& rect, int cols);
	virtual ~InfoSprite();

	inline void setRect(const Rect& rect)
	{
		_rect = rect;
	}

	inline Rect& getRect()
	{
		return _rect;
	}

	inline void setCols(int cols)
	{
		_cols = cols;
	}

	inline int getCols() const
	{
		return _cols;
	}

private:
	Rect _rect;
	int _cols;
};

#endif
