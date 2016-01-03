#ifndef _UTIL_H_
#define _UTIL_H_

#include <map>
#include <string>
#include <cmath>
using std::string;
using std::map;

struct _vec_3d {
	double x, y, z;

	struct _vec_3d unit() {
		double norm = l2_norm();

		struct _vec_3d out;
		out.x = x / norm;
		out.y = y / norm;
		out.z = z / norm;

		return out;
	}

	void operator=(struct _vec_3d lhs) {
		x = lhs.x;
		y = lhs.y;
		z = lhs.z;
	}

	struct _vec_3d operator*(double lhs) {
		struct _vec_3d out;
		out.x = x * lhs;
		out.y = y * lhs;
		out.z = z * lhs;
		return out;
	}

	struct _vec_3d operator-(struct _vec_3d lhs) {
		return (struct _vec_3d){x-lhs.x, y-lhs.y, z-lhs.z};
	}

	struct _vec_3d operator+(struct _vec_3d lhs) {
		return (struct _vec_3d){x+lhs.x, y+lhs.y, z+lhs.z};
	}

	void operator+=(struct _vec_3d lhs) {
		x += lhs.x;
		y += lhs.y;
		z += lhs.z;
	}

	struct _vec_3d cross(struct _vec_3d lhs) {
		double s1 = y*lhs.z - z*lhs.y;
		double s2 = z*lhs.x - x*lhs.z;
		double s3 = x*lhs.y - y*lhs.x;

		return (struct _vec_3d){s1, s2, s3};
	}

	double dist2(struct _vec_3d lhs) {
		return (x-lhs.x)*(x-lhs.x) + (y-lhs.y)*(y-lhs.y) + (z-lhs.z)*(z-lhs.z);
	}

	double dist(struct _vec_3d lhs) {
		return sqrt( dist2(lhs) );
	}

	double l2_norm() {
		return sqrt(x*x + y*y + z*z);
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