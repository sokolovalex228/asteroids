#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "defs.h"

class Texture
{
public:
	Texture();
	Texture(const char* fileName);
	virtual ~Texture();

	void clear();

	bool load(const char* fileName);
	bool draw();

private:
	uint _id;
	uint _width;
	uint _height;
	uint _bpp;
};

#endif
