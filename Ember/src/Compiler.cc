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
 * @file Compiler.cc
 * @author 
 * > Discord: TheDuck#2454
 * @brief Compiler for the Ember programming language
 * @date 2022-12-19
 * 
 */

//https://stackoverflow.com/questions/6212665/why-is-eax-zeroed-before-a-call-to-printf
#include "Includes/Compiler.hh"

bool COMPILER::FindInString(string &str , string search) {
	return (str.find(search) != string::npos) ? true : false;

}

// use of auto as creating a return class will create complications in other words: can't be bothered to do it
auto COMPILER::__DATA__CheckArgs(EMBERLANG& Ember, const vector<string>& ExpectedArg, const int& StrSize){
	Ember.SavePos(); // Saves current position
	Ember.Lex(); // next token
	// define whta has to be returned in auto
	struct ret {
		int Code; 
		string Return1;
		string Return2;
	};

	if(Ember.Data.Value != "(") {
		Ember.SetPos(Ember.GetSavePos());
		return ret{
			1,
			Ember.Data.Value,
			"("
		};
	}

	for(int i = 0; i < StrSize; i++) {
		Ember.Lex();
		if(StrSize - i == 1){
			if(Ember.Data.Key != ExpectedArg[i]){
				Ember.SetPos(Ember.GetSavePos());
				return ret{
					2,
					Ember.Data.Key,
					ExpectedArg[i]
				};
			}
		} else {
			if(Ember.Data.Key != ExpectedArg[i]) {
				Ember.SetPos(Ember.GetSavePos());
				return ret{
					2,
					Ember.Data.Key,
					ExpectedArg[i]
				};
			}

			Ember.Lex();
			if(Ember.Data.Value != ","){
				Ember.SetPos(Ember.GetSavePos());
				return ret{
					1,
					Ember.Data.Value,
					","
				};
			}
		}
	}

	Ember.Lex();
	if(Ember.Data.Value != ")") {
		Ember.SetPos(Ember.GetSavePos());
		return ret{
			1,
			Ember.Data.Value,
			")"
		};
	}

	Ember.SetPos(Ember.GetSavePos());
	return ret{
		0,
		"",
		""
	};
}


vector<string> COMPILER::__DATA__HandleArgs(EMBERLANG& Ember, const int& StrSize){
	Ember.SavePos();
	Ember.Lex();

	vector<string> INPUT(StrSize);

	// All error checking is done by function __DATA__CheckArgs leaving this free to asume everything is right
	for(int i = 0; i < StrSize; i++) {
		Ember.Lex();
		if((StrSize - i) == 1){
			INPUT[i] = Ember.Data.Value;
		} else {
			INPUT[i] = Ember.Data.Value;
			Ember.Lex();
		}
	}

	Ember.Lex();
	return INPUT;
}


void COMPILER::Functions::__MBR____printf(EMBERLANG &Ember , GASCOMPILED &Gas){
	Ember.SavePos();
	bool found = false;
	int var;
	vector<string> ExpectedParam(1);
	ExpectedParam[0] = "STRING";

	auto x = __DATA__CheckArgs(Ember,ExpectedParam,ExpectedParam.size());
	if(x.Code == 1) Ember.Exit(1,"Compiler1\nSyntaxError:\n\tExpected: "+x.Return2+"\n\tRecieved: "+x.Return1);
	else if(x.Code == 2) Ember.Exit(6,"Compiler2\nDataError:\n\tExpected: "+x.Return2+"\n\tRecieved: "+x.Return1);
	
	
	vector<string> str = __DATA__HandleArgs(Ember,ExpectedParam.size());
	
	Ember.Lex();
	if(Ember.Data.Value != ";") Ember.Exit(1,"Compiler3\nSyntaxError:\n\tExpected: ;\n\tRecieved: "+x.Return1);
	
	for(const auto& n : MBR_MSGES) // Checks if it can find a previously defined string returns the position in array and if found
		if(n.second == str[0]) {
			found = true;
			var = n.first;
		}

	if(str[0] != "") {
		Gas.SectionMain+="\tpush %rbx\n";
		if(found) {
			Gas.SectionMain+="\tlea .mbr.msg"+std::to_string(var)+" (%rip), %rdi\n"; // Will go to a previosly defined string with same value
		} else {
			Gas.SectionMain+="\tlea .mbr.msg"+std::to_string(Gas.Counter)+" (%rip), %rdi\n"; // No previos string exists with this value
			Gas.SectionMainLast+=".mbr.msg"+std::to_string(Gas.Counter)+": .asciz \""+str[0]+"\"\n"; // Define new string
			MBR_MSGES[Gas.Counter] = str[0];
			++Gas.Counter;		
		}
		
		Gas.SectionMain+="\tmov $0, %eax\n";
		Gas.SectionMain+="\tcall printf@plt\n";
		Gas.SectionMain+="\tpop %rbx\n";
		Gas.SectionMain+="\n";
	}

}

void COMPILER::Functions::__MBR____return(EMBERLANG &Ember , GASCOMPILED &Gas){
	Ember.SavePos();
	Ember.EnableNewlines();
	vector<string> ExpectedParam(1);
	ExpectedParam[0] = "NUMBER";

	auto x = __DATA__CheckArgs(Ember,ExpectedParam,ExpectedParam.size());
	if(x.Code == 1) Ember.Exit(1,"Compiler4\nSyntaxError:\n\tExpected: "+x.Return2+"\n\tRecieved: "+x.Return1);
	else if(x.Code == 2) Ember.Exit(6,"Compiler5\nDataError:\n\tExpected: "+x.Return2+"\n\tRecieved: "+x.Return1);
	
	
	vector<string> str = __DATA__HandleArgs(Ember,ExpectedParam.size());

	Ember.Lex();
	if(Ember.Data.Value != ";") Ember.Exit(1,"Compiler6\nExpected \";\"");

	if(std::stoi(str[0]) == 0) Gas.SectionMain+="\txor %rax, %rax\n"; // 0's out %rax
	else Gas.SectionMain+="\tmov $"+std::to_string(std::stoi(str[0]))+", %rax\n"; //required so it will remove unneeded 0's
	
	Gas.SectionMain+="\tret\n"; // return to std c library
}


void COMPILER::Handle_identifiers(EMBERLANG &Ember , GASCOMPILED &Gas){
	Functions func;
	Ember.Lex();
	Ember.SavePos();

	if(Ember.Data.Key == "IDENTIFIER") {
		if(Ember.Data.Value == "printf") func.__MBR____printf(Ember,Gas);
		else if(Ember.Data.Value == "return") func.__MBR____return(Ember,Gas);
		else Ember.Exit(1,"Unrecognised: "+Ember.Data.Value);
	}
	

}