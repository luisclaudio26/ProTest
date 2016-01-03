#ifndef _IMPLICIT_SURFACE_H_
#define _IMPLICIT_SURFACE_H_

#include "Util.h"

class ImplicitSurface
{
public:
	//-1 if it's inside the surface, 0 if it's in the surface, 1 if it's outside
	virtual int in(vec_3d p) = 0;
	virtual vec_3d normal_at(vec_3d p) = 0;
};

#endif