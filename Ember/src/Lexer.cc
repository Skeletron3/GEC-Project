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
 * @file Lexer.cc
 * @author 
 * > Discord: TheDuck#2454
 * @brief Lexer for the Ember programming language
 * @date 2022-12-19
 * 
 */
#include "Includes/Lexer.hh"

EMBERLANG::EMBERLANG(int IN_argc,char** IN_argv,string IN_code,string FileName){
	Code = IN_code;
	Data.InputArgInfo.argv = IN_argv;
	Data.InputArgInfo.argc = IN_argc;
	Data.FileInfo.file = FileName;
}

void EMBERLANG::init(int IN_argc,char** IN_argv,string IN_code,string FileName){
	Code = IN_code;
	Data.InputArgInfo.argv = IN_argv;
	Data.InputArgInfo.argc = IN_argc;
	Data.FileInfo.file = FileName;
}

EMBERLANG::~EMBERLANG(){}

void EMBERLANG::EnableSpaces(){
	Data.Spaces=true;
}

void EMBERLANG::DisableSpaces(){
	Data.Spaces=false;
}

void EMBERLANG::EnableTabs(){
	Data.Tabs=true;
}

void EMBERLANG::DisableTabs(){
	Data.Tabs=false;
}

void EMBERLANG::EnableNewlines(){
	Data.Newlines=true;
}

void EMBERLANG::DisableNewlines(){
	Data.Newlines=false;
}

void EMBERLANG::EnableComments(){
	Data.Comments=true;
}
void EMBERLANG::DisableComments(){
	Data.Comments=false;
}

bool EMBERLANG::SpacesCondition(){
	return Data.Spaces;
}
bool EMBERLANG::TabsCondition(){
	return Data.Tabs;
}
bool EMBERLANG::NewlinesCondition(){
	return Data.Newlines;
}
bool EMBERLANG::CommentsCondition(){
	return Data.Comments;
}

void EMBERLANG::AsignType(int type){
	Data.Key=Types[type];
}

inline void EMBERLANG::Next(){
	Data.pos++;
	Data.clinecharacter++;
}
inline void EMBERLANG::Prev(){
	Data.pos--;
	Data.clinecharacter--;
}

inline char EMBERLANG::Get(){
	return Code[Data.pos];
}

void EMBERLANG::Reset(){
	Data.Value="";
	Data.Key="";
	Data.start=0;
	Data.NUMBERS = false; 
	Data.LETTERS = false;
}

void EMBERLANG::replaceAll( string &str, const string &search, const string &replace ) {
	for( size_t cpos = 0; ; cpos += replace.length() ) {
		cpos = str.find( search, cpos );
		if( cpos == string::npos ) break;
		str.erase( cpos, search.length() );
		str.insert( cpos, replace );
	}
}

void EMBERLANG::Exit(int code,string details1){
	if(code == 0) {
		cout<<Colour::BGreen()<<ExitCodes[code]<<endl;
	} else {
		cerr<<Colour::BRed()<<details1<<endl<<Colour::BCyan();
		std::ifstream f(Data.FileInfo.file);
		string s;
		for (int ii = 1; ii <= Data.cline; ii++) std::getline(f, s);

		f.close();
		cerr<<Data.cline<<setw(5)<<" | "<<s<<endl;
		 
		cerr << Colour::BYellow()<<"INFO:"<<endl;
		cerr << setw(15) << "LINE: "		<< Data.cline 					<< endl;
		cerr << setw(15) << "COL: "			<< Data.clinecharacter 			<< endl;			
		cerr << setw(15) << "FILE: "		<< Data.FileInfo.file 			<< endl;
		cerr << setw(15) << "g++ VERSION: "	<< MacroData.version 			<< endl;

	}
	exit(code);
}

void EMBERLANG::LoopAgain(int &i){
	i++;
}

void EMBERLANG::LoopAgain(int &i,int Amount){
	i+=Amount;
}

void EMBERLANG::Auto_Append(){
	Data.Value+=Get();
}

void EMBERLANG::Manual_Append(string appendchar){
	Data.Value+=appendchar;
}

void EMBERLANG::Lex(){
	for(int i = 1; i > 0;i--){
		Reset();
		//switch to match all cases
		switch(Get()){
			//handle EOF
			case '\0':
				AsignType(4);
				Data.Value += "EOF";
				Next();
				break;
			//handle letters and numbers for identifiers will return number if only numbers are present
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				Data.start = Data.pos;
				while(isdigit(Get()) || isalpha(Get()) || Get() == '_'){
					if(isdigit(Get()))
						Data.NUMBERS = true;
					else 
						Data.LETTERS = true;
					Auto_Append();
					Next();
				}
				if(Data.NUMBERS == true && Data.LETTERS == true)
					AsignType(0);
				else if(Data.NUMBERS == true && Data.LETTERS == false)
					AsignType(1);
				else 
					AsignType(0);
				break;
				
			//handle comments
			case '/':
				Data.start=Data.pos;
				Next();
				if(Get() == '*'){
					AsignType(23);
					Next();
					// Loops untill * and checks if next is /
					while(1){
						if(Get() == '*'){
							Next();
							if(Get() == '/') {
								Prev();
								break;
							} else
								Prev();

						// Error checking
						} else if(Get() == '\0')
							Exit(1,"SyntaxError:\n\tExpected: \"*/\"\n\tRecieved: EOF");
						else if(Get() == '\n') {
							// Checks for newline so the line system isn't messed up
							Data.cline++;
							Data.clinecharacter = 0; // Reset current character
						}
						Auto_Append();
						Next();
					}
					Next();
					if(Get() != '/'){
						string a = "SyntaxError:\n\tExpected: \"/\"\n\tRecieved: ";
						a += Get();
						Exit(1,a);
					}
					Next();
				} else if(Get()=='/'){
					AsignType(23);
					Next();
					while(1){
						Auto_Append();
						Next();
						if(Get()=='\0' || Get()=='\n'){
							if(Get() == '\n') {
								Data.cline++;
								Data.clinecharacter = 0; // Reset current character
							}
							break;
						}
					}	

				} else{
					AsignType(5); 
					Auto_Append();
				}
				if(!CommentsCondition()){
					LoopAgain(i);
				}
				break;
			
			//handle all others
			case '^':
			case '*':
			case '+':
			case '-':
			case '=':
				Data.start=Data.pos;
				AsignType(5);
				Auto_Append();
				Next();
				break;
			case '(':
			case ')':
				Data.start=Data.pos;
				AsignType(6); 
				Auto_Append();
				Next();
				break;

			case '{':
			case '}':
				Data.start=Data.pos;
				AsignType(7); 
				Auto_Append();
				Next();
				break;

			case '[':
			case ']':
				Data.start=Data.pos;
				AsignType(12);
				Auto_Append();
				Next();
				break;

			case '\\':
				Data.start=Data.pos;
				Next();
				switch(Get()){
					case 'n':
						AsignType(24);
						Manual_Append("\\n");
						break;

					case 't':
						AsignType(24);
						Manual_Append("\\t");
						break;

					case 'r':
						AsignType(24);
						Manual_Append("\\r");
						break;

					case 'v':
						AsignType(24);
						Manual_Append("\\v");
						break;

					case '0':
						AsignType(24);
						Manual_Append("\\0");
						break;

					case '\\':
						AsignType(24);
						Manual_Append("\\\\");
						break;

					case '"':
						AsignType(24);
						Manual_Append("\\\"");
						break;

					case '\'':
						AsignType(24);
						Manual_Append("\\\\'");
						break;

					case '\b':
						AsignType(24);
						Manual_Append("\\b'");
						break;

					default:
						string a = "SyntaxError:\n\tExpected: valid escape char\n\tRecieved: ";
						a+=Get();
						Exit(1,a);
						break;
						
				}
				Next();
				break;
			
			/*
			 * Finding the correct ascii codes and escape characters is seeming to be a little chalenging once found other escape characters
			 * will go here along with \t and \n
			 * 
			 */
			case '\t':
				Data.start=Data.pos;
				if(!TabsCondition()){
					LoopAgain(i);
					Next();
				} else {
					AsignType(11);
					Auto_Append();
					Next();
				}
				break;
			case '\n':
				Data.start=Data.pos;
				Data.cline++;
				Data.clinecharacter = 0; // Reset current character
				if(!NewlinesCondition()){
					LoopAgain(i);
					Next();
				} else {
					AsignType(9);
					Auto_Append();
					Next();
				}
				break;
			//Handle strings
			case '"':
				Data.start=Data.pos;
				Next();
				AsignType(14);
				while(1){
					if(Get() == '\0'){
						Exit(1,"SyntaxError:\n\tExpeced: \"\"\"\n\tRecieved: EOF");
					} else if(Get() == '\"'){
						break;
					} else {
						// Escape
						if(Get() == '\\'){
							Next();
							switch(Get()){
								case 'n':
									Manual_Append("\\n");
									break;

								case 't':
									Manual_Append("\\t");
									break;

								case 'v':
									Manual_Append("\\v");
									break;	

								case 'r':
									Manual_Append("\\r");
									break;

								case 'f':
									Manual_Append("\\f");
									break;

								case 'b':
									Manual_Append("\\b");
									break;

								case 'a':
									Manual_Append("\\a");
									break;

								case '\\':
									Manual_Append("\\\\");
									break;

								case '?':
									Manual_Append("\\?");
									break;

								case '"':
									Manual_Append("\\\"");
									break;

								case '\'':
									Manual_Append("\\'");
									break;

								case '0':
									Manual_Append("\\0");
									break;

								default:
									string a = "SyntaxError:\n\tExpected: valid escape char\n\tRecieved: ";
									a+=Get();
									Exit(1,a);
							}
						} else {
							switch(Get()){
								case '\n':
									Data.cline++;
									Data.clinecharacter = 0; // Reset current character
									Manual_Append("\\n");
									break;

								case '\t':
									Manual_Append("\\t");
									break;

								case '\v':
									Manual_Append("\\v");
									break;	

								case '\r':
									Manual_Append("\\r");
									break;

								case '\f':
									Manual_Append("\\f");
									break;

								case '\b':
									Manual_Append("\\b");
									break;

								case '\a':
									Manual_Append("\\a");
									break;

								case '\\':
									Manual_Append("\\\\");
									break;

								case '\?':
									Manual_Append("\\?");
									break;

								case '\"':
									Manual_Append("\\\"");
									break;

								case '\'':
									Manual_Append("\\'");
									break;

								case '\0':
									Manual_Append("\\0");
									break;

								default:
									Auto_Append();
									break;																									
							}	
						}
					}
					Next();
				}
				Next();
				break;
				
			case '\'':
				Data.start=Data.pos;
				Next();
				AsignType(13);
				if(Get() == '\0' || Get() == '\''){
					string a = "SyntaxError:\n\tExpected: char\n\tRecieved: ";
					a+=Get();
					Exit(1,a);
				}
				// Handle escape
				if(Get() == '\\'){
					Next();
					switch (Get()) {
						case 'n':
							Manual_Append("\\n");
							break;

						case 't':
							Manual_Append("\\t");
							break;

						case 'v':
							Manual_Append("\\v");
							break;

						case 'r':
							Manual_Append("\\r");
							break;

						case 'f':
							Manual_Append("\\f");
							break;

						case 'b':
							Manual_Append("\\b");
							break;

						case 'a':
							Manual_Append("\\a");
							break;

						case '\\':
							Manual_Append("\\\\");
							break;

						case '?':
							Manual_Append("\\?");
							break;

						case '"':
							Manual_Append("\\\"");
							break;

						case '\'':
							Manual_Append("\\'");
							break;

						case '0':
							Manual_Append("\\0");
							break;

						default:
							string a = "SyntaxError:\n\tExpected: valid escape char\n\tRecieved: ";
							a+=Get();
							Exit(1,a);
							break;
					}
				} else {
					switch(Get()){
						case '\n':
							Data.cline++;
							Data.clinecharacter = 0; // Reset current character
							Manual_Append("\\n");
							break;

						case '\t':
							Manual_Append("\\t");
							break;

						case '\v':
							Manual_Append("\\v");
							break;	

						case '\r':
							Manual_Append("\\r");
							break;

						case '\f':
							Manual_Append("\\f");
							break;

						case '\b':
							Manual_Append("\\b");
							break;

						case '\a':
							Manual_Append("\\a");
							break;

						case '\\':
							Manual_Append("\\\\");
							break;

						case '\?':
							Manual_Append("\\?");
							break;

						case '\"':
							Manual_Append("\\\"");
							break;

						case '\'':
							Manual_Append("\\'");
							break;

						case '\0':
							Manual_Append("\\0");
							break;

						default:
							Auto_Append();
							Next();
							if(Get() != '\''){
								string a = "SyntaxError:\n\tExpected: \"'\"\n\tRecieved: ";
								a+=Get();
								Exit(1,a);
							}
							Next();	
							break;
					}
				}
				break;

			//handle spaces
			case ' ':
				Data.start=Data.pos;
				if(!SpacesCondition()){
					LoopAgain(i);
					Next();
				} else{
					Data.start=Data.pos;
					while(Get()==' '){
						Auto_Append();
						Next();
					}
					AsignType(2);
				}
				break;

			case '.':
				Data.start=Data.pos;
				AsignType(15);
				Auto_Append();
				Next();
				break;

			case ':':
				Data.start=Data.pos;
				AsignType(16);
				Auto_Append();
				Next();
				break;

			case ';':
				Data.start=Data.pos;
				AsignType(17);
				Auto_Append();
				Next();
				break;

			case '>':
				Data.start=Data.pos;
				AsignType(18);
				Auto_Append();
				Next();
				break;

			case '<':
				Data.start=Data.pos;
				AsignType(19);
				Auto_Append();
				Next();
				break;

			case '|':
				Data.start=Data.pos;
				AsignType(22);
				Auto_Append();
				Next();
				break;
			/*
			 * All macros will begin in % instead of #,
			 * for example they will look like: 
			 * 	%if()
			 * 	%install()
			 * 	%define
			 * 	etc...
			*/
			case '%':
				Data.start=Data.pos;
				AsignType(21);
				Auto_Append();
				Next();
				break;	

			default:
				Data.start=Data.pos;
				AsignType(20);
				Auto_Append();
				Next();
				break;
		
		}
	}
}

bool EMBERLANG::IsEOF(){   
	return (Data.Key=="EOF") ? true : false;
}

bool EMBERLANG::IsNotEOF(){
	return (Data.Key=="EOF") ? false : true;
	
}

int EMBERLANG::GetPos(){
	return Data.pos;
}

int EMBERLANG::GetSavePos() {
	return Data.specialsave;
}

void EMBERLANG::SetPos(int NewPos){
	Data.pos = NewPos;
}

void EMBERLANG::SavePos(){
	Data.specialsave = Data.pos;
}

void EMBERLANG::SavePos(int NewPos) {
	Data.specialsave = NewPos;
}