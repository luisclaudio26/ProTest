#include "../inc/Util.h"

Util* Util::ptr_instance = 0;

Util::Util()
{
	//Initialize entries
	this->dict["C"] = C;
	this->dict["N"] = N;
	this->dict["O"] = O;
}

Element Util::str_to_elem(string e)
{
	return this->dict[e];
}