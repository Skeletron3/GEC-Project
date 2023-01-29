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
 * @file Data.cc
 * @author 
 * > Discord: TheDuck#2454
 * @brief Stores important data for Ember
 * @date 2022-12-19
 * 
 */
#include "Includes/Data.hh"

string Types[GLOBAL_ARRAY_SIZE] = {
	"IDENTIFIER",	 // 0
	"NUMBER",		 // 1
	"SPACE",		 // 2
	"UKNOWN",		 // 3
	"EOF",			 // 4
	"OPERATOR",		 // 5
	"BRACKET",		 // 6
	"CURLYBRACKET",	 // 7
	"BACKSLASH",	 // 8
	"NEWLINE",		 // 9
	"RETURN",		 // 10
	"TAB",			 // 11
	"SQUAREBRACKET", // 12
	"CHAR",			 // 13
	"STRING",		 // 14
	"PERIOD",		 // 15
	"COLON",		 // 16
	"SEMICOLON",	 // 17
	"GREATERTHAN",	 // 18
	"LESSTHAN",		 // 19
	"UKNOWN",		 // 20
	"MACRO",	 	 // 21
	"PIPE",			 // 22
	"COMMENT",		 // 23
	"ESCAPE_CHAR",	 // 24
};

string ExitCodes[GLOBAL_ARRAY_SIZE] = {
	"Executed with success", 	// 0
	"SyntaxError: ",		 	// 1
	"FileNotFoundError: ",	 	// 2
	"NameError: ",				// 3
	"MemoryError: ",			// 4
	"UknownError: ",			// 5
	"Error: ",					// 6
};

void PreLexExit(int Code, string details) {
	if (Code == 0) {
		cout << Colour::BGreen() << ExitCodes[0] << endl;
	} else {
		cerr << Colour::BRed() << ExitCodes[Code] << details << endl;
		exit(Code);
	}
}

string GASCOMPILED::SectionMain="";
string GASCOMPILED::SectionMainLast="";
int GASCOMPILED::Counter = 1;

std::unordered_map<int, string> MBR_MSGES = {};