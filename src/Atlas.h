#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <map>
#include <string>
using namespace std;

#include "Rect.h"

class Atlas
{
public:
	Atlas();
	virtual ~Atlas();

	Rect get(const string& name);
	void add(const string& name, const Rect& rect);

private:
	map<string, Rect> _map;
};

#endif
