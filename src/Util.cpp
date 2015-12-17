#include "../inc/Util.h"

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