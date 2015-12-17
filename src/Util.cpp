#include "../inc/Util.h"

#include <iostream>

Util* Util::ptr_instance = 0;

//--------------------------------------
//------------- INTERNAL ---------------
//--------------------------------------
static void init_element_dict(map<string,Element>& dict)
{
	dict["C"] = C;
	dict["N"] = N;
	dict["O"] = O;
}

static void init_vdw_radii_table(map<Element,double>& table)
{
	//Data from WolframAlpha.com, in ANGSTROM!
	table[C] = 1.7;
	table[N] = 1.55;
	table[O] = 1.52;
}

//-----------------------------------------
//------------- FROM UTIL.H ---------------
//-----------------------------------------
Util::Util()
{
	init_element_dict(this->dict);
	init_vdw_radii_table(this->vdw_radius);
}

Element Util::str_to_elem(string e)
{
	string trimmed = e.substr(e.find_first_of(' ')+1, 
								e.size() - e.find_first_of(' '));
	
	return this->dict[trimmed];
}

double Util::van_der_waals_radius(Element e)
{
	return this->vdw_radius[e];
}