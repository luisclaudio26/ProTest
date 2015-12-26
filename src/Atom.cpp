#include "../inc/Atom.h"

string Atom::info()
{
	string out("");

	out.append( std::to_string(this->pos.x) + " ");
	out.append( std::to_string(this->pos.y) + " ");
	out.append( std::to_string(this->pos.z) );

	return out;
}