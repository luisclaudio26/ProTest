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
		double diff = dist_centers - s->radius;

		//if distance is (roughly) equal to radius, return 0
		//if is not equal and is less then radius, return -1
		//do nothing (that is, return 1) otherwise
		if( fabs(diff) < EPSILON )
			out = 0;
		else if( diff < 0 )
			out = -1;
	}

	return out;
}

vec_3d VDWSurface::normal_at(vec_3d p)
{
	int closest = 0;
	double dist_closest = 10000.0;

	//look for closest atom
	for(int i = 0; i < this->surface_spheres.size(); i++)
	{
		vec_3d sphere_center = this->surface_spheres[i].center;
		double dist_current = p.dist2( sphere_center );

		if( dist_current < dist_closest )
		{
			closest = i;
			dist_closest = dist_current;
		}
	}

	//compute p - center_closest_atom
	return (p - this->surface_spheres[closest].center).unit();
}