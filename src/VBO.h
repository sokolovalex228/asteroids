#ifndef _VBO_H_
#define _VBO_H_

#include "Rect.h"

#include <vector>

using namespace std;

class VBO
{
public:
	VBO();
	VBO(const Rect& rect, const Rect& rectTVerts);
	virtual ~VBO();

	bool add(const Rect& rect, const Rect& rectTVerts);
	bool build();

	bool deleteBuffer();

	void clear();
	bool draw();

	unsigned int _id;

	vector<float> _vectorVerts;
	vector<float> _vectorTVerts;
};

#endif
