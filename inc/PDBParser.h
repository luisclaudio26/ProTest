#ifndef _PDB_PARSER_H_
#define _PDB_PARSER_H_

#include <vector>
#include "Atom.h"
using std::vector;

class PDBParser
{
public:
	void parse(char* filepath, vector<Atom>& atoms);
};

#endif