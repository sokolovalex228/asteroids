#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
using namespace std;

#include "defs.h"

namespace Utils
{
	bool loadPNGToMemory(const char* fileName, uint* width, uint* height, uint* bpp, vector<uchar>& r_vector_uchar_Out);
	bool loadFromAssets(const char* fileName, std::vector<char>& buffer);

	inline float getRandom()
	{
		return (float)rand() / (RAND_MAX + 1.0f);
	}

	inline float getRandomZero()
	{
		return getRandom() * 2.0f - 1.0f;
	}

};

#endif
