#ifndef _VAN_DER_WAALS_SURFACE_H_
#define _VAN_DER_WAALS_SURFACE_H_

#include "ImplicitSurface.h"

class VDWSurface : public ImplicitSurface
{
private:
public:
	int in(vec_3d p) override;	
};

#endif