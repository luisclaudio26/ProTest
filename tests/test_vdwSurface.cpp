#include <iostream>
#include "../inc/VDWSurface.h"
using std::cout;
using std::endl;

int main(int argc, char** args)
{
	Atom a;
	a.setElement( C );
	a.setPosition( (vec_3d){0.0, 0.0, 0.0} );

	//p1 is in the surface, p2 is inside, p3 is outside
	vec_3d p1 = {1.7, 0.0, 0.0}, p2 = {0.3, 0.5, 0.4}, p3 = {2.1, 2.0, 1.0};

	VDWSurface surf;
	surf.push_atom(a);

	cout<<"P1: "<<surf.in(p1)<<endl;
	cout<<"P2: "<<surf.in(p2)<<endl;
	cout<<"P3: "<<surf.in(p3)<<endl;

	return 0;
}