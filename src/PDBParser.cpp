#include "../inc/PDBParser.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

const int PDB_COLUMN_NUMBER = 80;

void PDBParser::parse(char* filepath, vector<Atom>& atoms)
{
	fstream fs(filepath, fstream::in);
	if(!fs.is_open()) return;

	while(!fs.eof())
	{
		string lineIn; getline(fs, lineIn);
		if(lineIn.size() != PDB_COLUMN_NUMBER) continue;

		//Create atom and push
	}

	fs.close();
}