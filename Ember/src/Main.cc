/**
 *  Copyright (C) 2022-12-19 TheDuck#2454 (Discord)
 *	
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *	
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *	
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <https://www.gnu.org/licenses/>
 * 
 * @file Main.cc
 * @author 
 * > Discord: TheDuck#2454
 * @brief Main file of the Ember programming language
 * @date 2022-12-19
 * 
 */
#include "Includes/Main.hh"

int main(int argc,char** argv){
	if(!(argc > 1)) {
		cout << "Ember version: " << __EMBER_VERSION__ << endl;
		exit(0);
	}

	bool DeleteASFile = true;
	string FileContents;
	string FileName="";
	string OutFileName = "ember.out";
	string tmp;

	// Handle all arguements
	for(int i = 1; i < argc; i++) {
		tmp = (string) argv[i];
		if(tmp == "-K"){
			DeleteASFile = false;
		} else if(tmp == "-o") {
			if(OutFileName != "ember.out") PreLexExit(6,"Cannot specify more than 1 output file"); 
			if((argc - i) == 1) PreLexExit(6,"Missing output file name");
			OutFileName = (string) argv[i+1];
			i++;
		} else if(tmp.at(0) == '-'){
			PreLexExit(6,"Uknown option"); 
		} else {
			if(FileName != "") PreLexExit(6,"Cannot specify more than 1 input file"); 
			FileName=tmp;
			std::ifstream inFile(FileName);
			
			if(inFile.is_open()){
				std::stringstream strStream;
				strStream << inFile.rdbuf();
				FileContents = strStream.str();
			} else {
				PreLexExit(2,("Could not open file: " + FileName).c_str()); 
			}
		}
	}

	// If filename is not defined then throw error
	if(FileName == "") {
		cerr << Colour::BRed() << "File not specified" << endl << Colour::Reset();
		exit(1);
	}

	// Load objects
	EMBERLANG Ember(argc, argv, FileContents, FileName);
	COMPILER Compiler;
	GASCOMPILED Gas;

	std::ofstream MyFile("Ember.Build.s");

	while(Ember.IsNotEOF()){
		Compiler.Handle_identifiers(Ember,Gas);
	}

	// Write the GNU AS compiled into file
	MyFile << "\t.global main" << endl << "\t.text" << endl << "main:" << endl;
	MyFile << Gas.SectionMain << endl;
	MyFile << Gas.SectionMainLast << endl;

	int x = 0;
	x += system(("gcc Ember.Build.s -o " + OutFileName).c_str());

	if(DeleteASFile == true) // remove assembly file unless specified not to
		x += system("rm Ember.Build.s");	
 
	return 0; 
}
