#ifndef _ATOM_H_
#define _ATOM_H_

#include <string>
#include "Util.h"

using std::string;

class Atom
{
private:
	vec_3d pos;
	Element e;

public:
	Atom() {}
	~Atom() {}

	//-------------------------
	//-------- Modify ---------
	//-------------------------
	void setPosition(vec_3d pos) { this->pos = pos; }
	void setElement(Element e) { this->e = e; }

	//-------------------------
	//-------- Access ---------
	//-------------------------
	Element element() { return this->e; }
	string info();
};

#endif