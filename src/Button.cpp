#include "Button.h"

Button::Button()
{

}

bool Button::construct(const std::string& name, const Rect& verts, const Rect& tverts)
{
	_name = name;

	return Sprite::construct(verts, tverts);
}

Button::~Button()
{

}

