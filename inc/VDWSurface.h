#ifndef _VAN_DER_WAALS_SURFACE_H_
#define _VAN_DER_WAALS_SURFACE_H_

#include "ImplicitSurface.h"
#include "Atom.h"
#include <vector>

using std::vector;

typedef struct {
	vec_3d center;
	double radius;
} vdwSphere;

class VDWSurface : public ImplicitSurface
{
private:
	vector<vdwSphere> surface_spheres;

public:

	//--------------------------------
	//--------- CTOR & DTOR ----------
	//--------------------------------	
	VDWSurface() {}
	VDWSurface(vector<Atom>& atoms);

	//-------------------------------
	//--------- OPERATIONS ----------
	//-------------------------------
	void push_atom(Atom a);

	//-------------------------------------------
	//--------- FROM IMPLICITSURFACE.h ----------
	//-------------------------------------------
	int in(vec_3d p) override;	
};

#endif