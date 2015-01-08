#include "Texture.h"
#include "Utils.h"

Texture::Texture() : _id(0)
{

}

Texture::Texture(const char* fileName): _id(0)
{
	load(fileName);
}

Texture::~Texture()
{
	clear();
}

void Texture::clear()
{
	if(0 != _id)
	{
		glBindTexture(GL_TEXTURE_2D, _id);
		glDeleteTextures(1, &_id);

		_id = 0;
	}
}

bool Texture::load(const char* fileName)
{
	vector<uchar> data;

	clear();

	if(true == Utils::loadPNGToMemory(fileName, &_width, &_height, &_bpp, data))
	{
		glGenTextures(1, &_id);
		glBindTexture(GL_TEXTURE_2D, _id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &data[0]);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		return true;
	}

	return false;
}

bool Texture::draw()
{
	if(0 != _id)
	{
		glBindTexture(GL_TEXTURE_2D, _id);
		glEnable(GL_TEXTURE_2D);

		return true;
	}

	return false;
}
