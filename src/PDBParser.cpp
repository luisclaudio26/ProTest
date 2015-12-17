#include "../inc/PDBParser.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const int PDB_COLUMN_NUMBER = 80;

const int PDB_X_COLUMN = 31;
const int PDB_Y_COLUMN = 39;
const int PDB_Z_COLUMN = 47;
const int PDB_COORD_SIZE = 8;

const int PDB_ELEM_COLUMN = 77;
const int PDB_ELEM_SIZE = 2;

void PDBParser::parse(char* filepath, vector<Atom>& atoms)
{
	fstream fs(filepath, fstream::in);
	if(!fs.is_open()) return;

	while(!fs.eof())
	{
		//Read line
		string lineIn; getline(fs, lineIn);
		if(lineIn.size() != PDB_COLUMN_NUMBER) continue;

		//Create atom and push
		vec_3d v;
		v.x = stod( lineIn.substr(PDB_X_COLUMN-1, PDB_COORD_SIZE) );
		v.y = stod( lineIn.substr(PDB_Y_COLUMN-1, PDB_COORD_SIZE) );
		v.z = stod( lineIn.substr(PDB_Z_COLUMN-1, PDB_COORD_SIZE) );

		Element e;
		e = Util::instance()->str_to_elem( lineIn.substr(PDB_ELEM_COLUMN-1, PDB_ELEM_SIZE) );

		Atom aux; 
		aux.setPosition( v ); aux.setElement( e );
		atoms.push_back(aux);
	}

	fs.close();
}