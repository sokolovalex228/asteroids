#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Object.h"
#include "VBO.h"
#include "Anim.h"

class Sprite : public Object
{
public:
	Sprite();
	virtual ~Sprite();

	bool construct(const Rect& verts, const Rect& tverts);

	virtual void draw();


private:
	VBO _vbo;
	VectorPtr<Anim> _anims;
};

#endif

