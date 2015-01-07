#include "Atlas.h"

Atlas::Atlas()
{
}


Atlas::~Atlas()
{
}

Rect Atlas::get(const string& name)
{
	if(0 < _map.size())
	{
		map<string, Rect>::iterator it = _map.find(name);

		if(_map.end() != it)
		{
			return it->second;
		}
	}

	return Rect(0.0f, 0.0f, 0.99999f, 0.99999f);
}

void Atlas::add(const string& name, const Rect& rect)
{
	_map.insert(map<string, Rect>::value_type(name, rect));
}
