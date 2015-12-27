#include "../inc/VDWSurface.h"

VDWSurface::VDWSurface(vector<Atom>& atoms)
{
	for(auto at = atoms.begin(); at != atoms.end(); ++at)
		this->push_atom( *at );
}

void VDWSurface::push_atom(Atom a)
{
	vdwSphere s;
	s.center = a.getPosition();
	s.radius = Util::instance()->van_der_waals_radius( a.element() );

	this->surface_spheres.push_back( s );
}

int VDWSurface::in(vec_3d p)
{
	int out = 1;

	for(auto s = surface_spheres.begin(); s != surface_spheres.end(); ++s)
	{
		double dist_centers = s->center.dist( p );

		//if distance is (roughly) equal to radius, return 0
		//if is not equal and is less then radius, return -1
		//do nothing (that is, return 1) otherwise
		if( dist_centers - s->radius < EPSILON )
			out = 0;
		else if( dist_centers - s->radius < 0)
			out = -1;
	}

	return out;
}