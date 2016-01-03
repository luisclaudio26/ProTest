#include "../inc/Raytracer.h"
#include "../inc/VDWSurface.h"

int main()
{
	Atom a; a.setElement( C ); 
			a.setPosition( (vec_3d){0.0, 0.0, 0.0} );
	
	VDWSurface s; 
	s.push_atom(a);

	Raytracer::instance()->drawSurface(&s, 800, 600);
	return 0;
}