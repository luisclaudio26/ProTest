#ifndef _UTIL_H_
#define _UTIL_H_

#include <map>
#include <string>
#include <cmath>
using std::string;
using std::map;

struct _vec_3d {
	double x, y, z;


	double dist2(struct _vec_3d lhs) {
		return (x-lhs.x)*(x-lhs.x) + (y-lhs.y)*(y-lhs.y) + (z-lhs.z)*(z-lhs.z);
	}

	double dist(struct _vec_3d lhs) {
		return sqrt( dist2(lhs) );
	}
};
typedef _vec_3d vec_3d;

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