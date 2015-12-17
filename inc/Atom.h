#ifndef _ATOM_H_
#define _ATOM_H_

#include <string>
#include "Util.h"

using std::string;

class Atom
{
private:
	double x, y, z;
	Element e;

public:
	string info();
};

#endif