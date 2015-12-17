#ifndef _UTIL_H_
#define _UTIL_H_

#include <map>
#include <string>
using std::string;
using std::map;

typedef struct {
	double x, y, z;
} vec_3d;

enum Element {
	C,
	N,
	O	
};

class Util
{
private:
	Util();
	static Util* ptr_instance;

	map<string,Element> dict;
	map<Element,double> vdw_radius;

public:
	~Util() { delete Util::ptr_instance; }

	static Util* instance() {
		if(! Util::ptr_instance)
			Util::ptr_instance = new Util();
		return Util::ptr_instance;
	}

	//------------------------
	//-------- TOOLS ---------
	//------------------------
	Element str_to_elem(string e);
	double van_der_waals_radius(Element e); //IN ANGSTROM!
};

#endif