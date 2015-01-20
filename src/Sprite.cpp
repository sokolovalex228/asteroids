#include "Sprite.h"

Sprite::Sprite()
{

}

bool Sprite::construct(const Rect& verts, const Rect& tverts)
{
	if(true == _vbo.add(verts, tverts))
	{
		_vbo.build();
		return true;
	}

	return false;
}

Sprite::~Sprite()
{

}

void Sprite::draw()
{
	_vbo.draw();
}

