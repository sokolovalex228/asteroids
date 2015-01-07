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
	
	inline void add(T* pT)
	{
		if(nullptr != pT)
		{
			vector<T*>::push_back(pT);
		}
	}
	
	inline T* addNew()
	{
		if(T* pT = new T())
		{
			vector<T*>::push_back(pT);
			return pT;
		}

		return nullptr;
	}
	
	void clear()
	{
		if(size_t size = getSize())
		{
			for(size_t i = 0; i < size; i++)
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
