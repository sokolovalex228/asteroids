#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Object.h"
#include "VBO.h"

class Sprite : public Object
{
public:
	Sprite();
	virtual ~Sprite();

	virtual void draw();

private:
	VBO _vbo;
};

#endif

