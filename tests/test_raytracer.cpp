#include "../inc/Raytracer.h"
#include "../inc/VDWSurface.h"

int main()
{
	Atom a; a.setElement( C ); 
			a.setPosition( (vec_3d){0.0, 0.0, 0.0} );
	Atom b; b.setElement( O );
			b.setPosition( (vec_3d){0.9, 0.0, 0.0} );
	Atom c; c.setElement( N );
			c.setPosition( (vec_3d){0.0, -1.2, -0.6} );

	VDWSurface s; 
	s.push_atom(a);
	s.push_atom(b);
	s.push_atom(c);

	Raytracer::instance()->drawSurface(&s, 700, 700);
	return 0;
}