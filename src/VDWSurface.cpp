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
	return 0;
}