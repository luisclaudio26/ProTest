#include <iostream>
#include <vector>
#include "inc/PDBParser.h"
using namespace std;

int main(int argc, char** args)
{
	if(argc < 2) return 0;

	vector<Atom> atoms;
	PDBParser in;

	in.parse(args[1], atoms);
	
	return 0;
}