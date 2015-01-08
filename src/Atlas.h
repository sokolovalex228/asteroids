#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <map>
#include <string>
#include <vector>
using namespace std;

#include "InfoSprite.h"

class Atlas
{
public:
	Atlas();
	virtual ~Atlas();

	InfoSprite get(const string& name);
	void add(const string& name, const InfoSprite& info);

	bool load(const char* fileName);
	bool save(const char* fileName);

	void clear();

private:
	map<string, InfoSprite> _map;
};

#endif
