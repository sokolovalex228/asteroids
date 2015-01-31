#ifndef OBJECT_H
#define OBJECT_H

#include "defs.h"
#include "VectorPtr.h"

class Object
{
public:
	Object();
	virtual ~Object();

	virtual bool construct();

	virtual void draw();

	static void drawObject(Object* pObjectRoot)
	{
		pObjectRoot->draw();

		int size = pObjectRoot->getSizeChildren();

		for(int i = 0; i < size; ++i)
		{
			drawObject(pObjectRoot->getChild(i));
		}
	}

	inline Object* addChild(Object* pObject)
	{
		_children.add(pObject);
		pObject->setParent(this);

		return pObject;
	}

	inline Object* detachChild(Object* pObject)
	{
		_children.detach(pObject);
		pObject->setParent(nullptr);

		return pObject;
	}

	inline void setParent(Object* pObject)
	{
		_parent = pObject;
	}

	inline Object* getParent() const
	{
		return _parent;
	}

	inline int getSizeChildren() const
	{
		return _children.size();
	}

	inline Object* getChild(int index)
	{
		return _children[index];
	}

	inline void detach()
	{
		if(nullptr != _parent)
		{
			_parent->detachChild(this);
		}
	}

private:
	Object* _parent;
	VectorPtr<Object> _children;
};

#endif
