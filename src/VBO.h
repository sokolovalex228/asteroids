#ifndef _VBO_H_
#define _VBO_H_

#include <vector>
using namespace std;

#include "Rect.h"

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

private:
	unsigned int _id;

	vector<float> _verts;
	vector<float> _tverts;
};

#endif
