#ifndef INFOSPRITE_H
#define INFOSPRITE_H

#include "Rect.h"

class InfoSprite
{
public:
	InfoSprite();
	InfoSprite(const Rect& rect, int cols);
	~InfoSprite();

	inline Rect& getRect()
	{
		return _rect;
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
