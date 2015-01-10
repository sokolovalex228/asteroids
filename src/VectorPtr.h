#ifndef _VECTOR_PTR_H_
#define _VECTOR_PTR_H_

#include <vector>
using namespace std;

template <class T>
class VectorPtr :
	public vector<T*>
{

public:
	VectorPtr()
	{

	}

	virtual ~VectorPtr()
	{
		clear();
	}

	inline T* getAt(size_t nIndex) const
	{
		return vector<T*>::operator[](nIndex);
	}

	inline size_t getSize()
	{
		return vector<T*>::size();
	}

	inline T* add(T* pT)
	{
		if(nullptr != pT)
		{
			vector<T*>::push_back(pT);
		}

		return pT;
	}

	inline T* addNew()
	{
		return add(new T());
	}

	T* detach(T* pT)
	{
		if(size_t size = getSize())
		{
			for(size_t i = 0; i < size; ++i)
			{
				if(vector<T*>::operator[](i) == pT)
				{
					vector<T*>::erase(vector<T*>::begin() + i);
					break;
				}
			}
		}

		return pT;
	}

	void clear()
	{
		if(size_t size = getSize())
		{
			for(size_t i = 0; i < size; ++i)
			{
				if(T* pT = vector<T*>::operator[](i))
				{
					delete pT;
				}
			}

			vector<T*>::clear();
		}
	}

};

#endif
