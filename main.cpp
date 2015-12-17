#include <iostream>
#include <vector>
#include "inc/PDBParser.h"
using std::cout;
using std::endl;

int main(int argc, char** args)
{
	if(argc < 2) return 0;

	vector<Atom> atoms;
	PDBParser in;

	in.parse(args[1], atoms);
	for(int i = 0; i < atoms.size(); i++)
		cout<<atoms[i].info()<<"VDW rad "<<Util::instance()->van_der_waals_radius( atoms[i].element() )<<endl;

	return 0;
}