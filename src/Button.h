#ifndef BUTTON_H
#define BUTTON_H

#include "Sprite.h"
#include <string>

class Button : public Sprite
{
public:
	Button();
	virtual ~Button();

	bool construct(const std::string& name, const Rect& verts, const Rect& tverts);

private:
	std::string _name;
};

#endif // BUTTON_H
