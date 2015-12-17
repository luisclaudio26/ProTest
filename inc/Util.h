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
	static Util* ptr_instance;

	map<string,Element> dict;

public:
	static Util* instance() {
		if(!ptr_instance)
			ptr_instance = new Util();
		return ptr_instance;
	}

	Util();
	~Util() { delete ptr_instance; }

	Element str_to_elem(string e);
};

#endif