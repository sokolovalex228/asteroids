#ifndef BUTTON_H
#define BUTTON_H

#include "Sprite.h"
#include <string>

class Button : public Sprite
{
public:
	Button();
	Button(const std::string& name);
	~Button();

private:
	std::string _name;
};

#endif // BUTTON_H
