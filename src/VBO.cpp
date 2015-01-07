#include "defs.h"
#include "VBO.h"

VBO::VBO() : _id(0)
{

}

VBO::VBO(const Rect& rect, const Rect& rectTVerts) : _id(0)
{
	add(rect, rectTVerts);
	build();
}

VBO::~VBO()
{
	clear();
}

void VBO::clear()
{
	deleteBuffer();

	_vectorVerts.clear();
	_vectorTVerts.clear();
}

bool VBO::add(const Rect& rectVerts, const Rect& rectTVerts)
{
	float arVerts[][3] =
	{
		{rectVerts.getX(), rectVerts.getY(), 0.0f},
		{rectVerts.getX() + rectVerts.getWidth(), rectVerts.getY() + rectVerts.getHeight(), 0.0f},
		{rectVerts.getX(), rectVerts.getY() + rectVerts.getHeight(), 0.0f},

		{rectVerts.getX(), rectVerts.getY(), 0.0f},
		{rectVerts.getX() + rectVerts.getWidth(), rectVerts.getY(), 0.0f},
		{rectVerts.getX() + rectVerts.getWidth(), rectVerts.getY() + rectVerts.getHeight(), 0.0f},
	};

	float arTVerts[][2] =
	{
		{rectTVerts.getX(), rectTVerts.getY()},
		{rectTVerts.getX() + rectTVerts.getWidth(), rectTVerts.getY() + rectTVerts.getHeight()},
		{rectTVerts.getX(), rectTVerts.getY() + rectTVerts.getHeight()},

		{rectTVerts.getX(), rectTVerts.getY()},
		{rectTVerts.getX() + rectTVerts.getWidth(), rectTVerts.getY()},
		{rectTVerts.getX() + rectTVerts.getWidth(), rectTVerts.getY() + rectTVerts.getHeight()},
	};

	if(size_t nSize = sizeof(arVerts) / sizeof(arVerts[0][0]))
	{
		if(float* p_float = &arVerts[0][0])
		{
			for(size_t nIx = 0; nIx < nSize; nIx++)
			{
				_vectorVerts.push_back(p_float[nIx]);
			} // nIx
		}
	}
	
	if(size_t nSize = sizeof(arTVerts) / sizeof(arTVerts[0][0]))
	{
		if(float* p_float = &arTVerts[0][0])
		{
			for(size_t nIx = 0; nIx < nSize; nIx++)
			{
				_vectorTVerts.push_back(p_float[nIx]);
			} // nIx
		}
	}

	return true;
}

bool VBO::draw()
{
#if 0
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, &_vectorVerts[0]);

	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, &_vectorTVerts[0]);

	glDrawArrays(GL_TRIANGLES, 0, _vectorVerts.size() / 3);
	
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	return true;
#else
	if(0 != _id)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glBindBuffer(GL_ARRAY_BUFFER, _id);
		glVertexPointer(3, GL_FLOAT, 0, (void*)0);
		glTexCoordPointer(2, GL_FLOAT, 0, (void*)(_vectorVerts.size() * sizeof(_vectorVerts[0])));
		glDrawArrays(GL_TRIANGLES, 0, _vectorVerts.size() / 3);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);

		return true;
	}
	else
	{
		printf("0=m_nId\n");
	}
#endif

	return false;
}

bool VBO::build()
{
	deleteBuffer();

	glGenBuffers(1, &_id);
	glBindBuffer(GL_ARRAY_BUFFER, _id);

	vector<float> vectorAll;

	vectorAll.resize(_vectorVerts.size() + _vectorTVerts.size());

	memcpy(&vectorAll[0], &_vectorVerts[0], sizeof(_vectorVerts[0]) * _vectorVerts.size());
	memcpy(&vectorAll[_vectorVerts.size()], &_vectorTVerts[0], sizeof(_vectorTVerts[0]) * _vectorTVerts.size());

	glBufferData(GL_ARRAY_BUFFER, vectorAll.size() * sizeof(vectorAll[0]), &vectorAll[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}

bool VBO::deleteBuffer()
{
	if(0 != _id)
	{
		glBindBuffer(GL_ARRAY_BUFFER, _id);
		glDeleteBuffers(1, &_id);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		_id = 0;

		return true;
	}

	return false;
}
