#include "../inc/Raytracer.h"
#include "../inc/VDWSurface.h"

int main()
{
	Atom a; a.setElement( C ); 
			a.setPosition( (vec_3d){0.0, 0.0, 0.0} );
	Atom b; b.setElement( O );
			b.setPosition( (vec_3d){0.9, 0.0, 0.0} );

	VDWSurface s; 
	s.push_atom(a);
	s.push_atom(b);

	Raytracer::instance()->drawSurface(&s, 600, 600);
	return 0;
}