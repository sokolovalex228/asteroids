#ifndef PVECTOR_H
#define PVECTOR_H

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
		if(size_t nSize = getSize())
		{
			for(size_t nIx = 0; nIx < nSize; nIx++)
			{
				if(T* pT = vector<T*>::operator[](nIx))
				{
					delete pT;
				}
			} // nIx
			
			vector<T*>::clear();
		}
	}
	
};

#endif // PVECTOR_H
