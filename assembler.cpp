//*******************************************************
// File:   assembler.cpp
// Author: Daniel Benedí García
// Date:   24-March-2020
// Coms:   A simple assembler. You give the schematic of
// 			your ISA and the program to translate.
//*******************************************************

#include <iostream>
#include <fstream>
#include "Translator.hpp"

using namespace std;

int main(int argc, char* argv[]){
	if(argc < 3 || argc > 4){
		cout << "Usage: " << argv[0] << " <schemeISA> <asmfile> [ <binOutput> ]." << endl;
		return 85;
	}
	
	ifstream scheme(argv[1]), prog(argv[2]);
	if(!scheme.is_open() || !prog.is_open()){
		cerr << "Couldn't open given files." << endl;
		scheme.close();
		prog.close();
		return -1;
	}
	
	ofstream out;

	if(argc == 4){
		out.open(argv[3]);
	}

	Translator schemed(scheme);
	string operation = "";

	while(!prog.eof()){
		getline(prog, operation);
		int op = schemed.translate(operation);

		cout << operation << " " << hex << op << dec << endl;

		if(argc == 4){
			out.write((char *)&op, sizeof(int));
		}
	}

	return 0;
}

