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
 * @file Lexer.hh
 * @author 
 * > Discord: TheDuck#2454
 * @brief Header for Lexer.cc
 * @date 2022-12-19
 * 
 */
#ifndef __lexer_hh_
#define __lexer_hh_

#include "Common.hh"
#include "Data.hh"
#include "Start.hh"
#include "ColourMod.hh"
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <filesystem>

// Identifier types declared extern
extern string Types[30];
// exit codes declared extern
extern string ExitCodes[30];
/**
 * @brief Actual class that holds entire lexer
 * 
 */
class EMBERLANG {
	public:
		/**
		 * @brief Code that needs to be lexed
		 * 
		 */
		string Code;
		/**
		 * @brief Class that holds all the config data
		 * 
		 */
		class {
			public:
			/**
			 * @brief Position of the code
			 * 
			 */
			int pos	 				= 0;
			/**
			 * @brief Used as a general save while lexing so if anything happens it can try again from start
			 * 
			 */
			int start   			= 0;
			/**
			 * @brief Shows the current line
			 * 
			 */
			int cline				= 1;
			/**
			 * @brief Gets the characted position from a line rather than entire code
			 * 
			 */
			int clinecharacter		= 0;
			/**
			 * @brief Offset used to make changed to where the error shows
			 * 
			 */
			int cerr_line_offset 	= 2;
			/**
			 * @brief Special save for saving outside of the lexer and happens between tokens rather than characters
			 * 
			 */
			int specialsave			= 0;
			/**
			 * @brief Shows the key of the lexed
			 * 
			 */
			string Key;
			/**
			 * @brief Shows the value of the lexed
			 * 
			 */
			string Value;
			/**
			 * @brief Settings for spaces
			 * 
			 */
			bool Spaces		= false;
			/**
			 * @brief Settings for tabs
			 * 
			 */
			bool Tabs		= false;
			/**
			 * @brief Settings for newlines
			 * 
			 */
			bool Newlines	= false;
			/**
			 * @brief Settings for comments
			 * 
			 */
			bool Comments   = false;
			/**
			 * @brief General save for working with things that have both numbers and letters. Helps in sorting out identifiers from numbers there identifiers can also contain digits
			 * 
			 */
			bool NUMBERS	= false;
			/**
			 * @brief General save for working with things that have both numbers and letters. Helps in sorting out identifiers from numbers there identifiers can also contain digits
			 * 
			 */
			bool LETTERS	= false;
			/**
			 * @brief Class that holds data about run and input
			 * 
			 */
			class {
				public:
				/**
				 * @brief all the arguements supplied
				 * 
				 */
				char** 	argv;
				/**
				 * @brief Amount of arguements suplied
				 * 
				 */
				int 	argc;
			}InputArgInfo;
			/**
			 * @brief Class that holds data about the file that is being lexed
			 * 
			 */
			class {
				public:
				/**
				 * @brief File (from directory from where it was run)
				 * 
				 */
				string file;
			}FileInfo;

		}Data;
	/**
	 * @brief Construct a new EMBERLANG object
	 * 
	 * @param IN_argc Amount of arguements
	 * @param IN_argv All arguements
	 * @param IN_code Code to be lexed
	 * @param FileName Name of file t be lexed
	 */
	EMBERLANG(int IN_argc,char** IN_argv,string IN_code,string FileName);
	/**
	 * @brief Class constructor as a function
	 * 
	 * @param IN_argc Amount of arguements
	 * @param IN_argv All arguements
	 * @param IN_code Code to be lexed
	 * @param FileName Name of file t be lexed
	 */
	void init(int IN_argc,char** IN_argv,string IN_code,string FileName);
	/**
	 * @brief Destroy the EMBERLANG object
	 * 
	 */
	~EMBERLANG();
	/**
	 * @brief Enables spaces
	 * 
	 */
	void EnableSpaces();
	/**
	 * @brief Disables spaces
	 * 
	 */
	void DisableSpaces();
	/**
	 * @brief Checks if spaces are enabled or not. Returns true if they are enabled else false
	 * 
	 * @return true 
	 * @return false 
	 */
	bool SpacesCondition();
	/**
	 * @brief Enables tabs
	 * 
	 */
	void EnableTabs();
	/**
	 * @brief Disabled tabs
	 * 
	 */
	void DisableTabs();
	/**
	 * @brief Checks if tabs are enabled or not. Returns true if they are enabled else false
	 * 
	 * @return true 
	 * @return false 
	 */
	bool TabsCondition();
	/**
	 * @brief Enables newlines
	 * 
	 */
	void EnableNewlines();
	/**
	 * @brief Disables newlines
	 * 
	 */
	void DisableNewlines();
	/**
	 * @brief Checks if newlines are enabled or not. Returns true if they are enabled else false
	 * 
	 * @return true 
	 * @return false 
	 */
	bool NewlinesCondition();
	/**
	 * @brief Enables comments
	 * 
	 */
	void EnableComments();
	/**
	 * @brief Disables comments
	 * 
	 */
	void DisableComments();
	/**
	 * @brief Checks if comments are enabled or not. Returns true if they are enabled else false
	 * 
	 * @return true 
	 * @return false 
	 */
	bool CommentsCondition();
	/**
	 * @brief Assigns the Key
	 * 
	 * @param type Type of key
	 */
	void AsignType(int type);
	/**
	 * @brief Changes the position up by 1
	 * 
	 */
	inline void Next();
	/**
	 * @brief Changes the position down by 1
	 * 
	 */
	inline void Prev();
	/**
	 * @brief Gets the character at the position
	 * 
	 * @return char 
	 */
	inline char Get();
	/**
	 * @brief Resets all data at each cycle so it won't damage the process
	 * 
	 */
	void Reset();
	/**
	 * @brief Exits with error code and details
	 * 
	 * @param code error code
	 * @param details1 details for exit
	 */
	void Exit(int code,string details1);
	/**
	 * @brief Will loop again
	 * 
	 * @param i variable to loop
	 */
	void LoopAgain(int &i);
	/**
	 * @brief Will loop again with certain amount
	 * 
	 * @param i variable to loop
	 * @param Amount amount to loop by
	 */
	void LoopAgain(int &i,int Amount);
	/**
	 * @brief Automatically gets the character from the position and appends it
	 * 
	 */
	void Auto_Append();
	/**
	 * @brief 
	 * 
	 * @param appendchar 
	 */
	void Manual_Append(string appendchar);
	/**
	 * @brief Main lexer which will lex everything (core of this program)
	 * 
	 */
	void Lex();
	/**
	 * @brief Checks if the Code has reached \0: returns true if it has reached
	 * 
	 * @return true 
	 * @return false 
	 */
	bool IsEOF();
	/**
	 * @brief Checks if the Code has reached \0: returns false if it has reached
	 * 
	 * @return true 
	 * @return false 
	 */
	bool IsNotEOF();
	/**
	 * @brief Replaces every occurrence of a substring in a string
	 * 
	 * @param s string
	 * @param search from 
	 * @param replace to
	 */
	void replaceAll( string &s, const string &search, const string &replace );
	/**
	 * @brief Replaces every occurrence of a substring in a string but returns it rather than modifying original
	 * 
	 * @param s string
	 * @param search from
	 * @param replace to
	 * @return string end result
	 */
	string returnReplaceAll( string s, const string search, const string replace );
	/**
	 * @brief Gets current poition
	 * 
	 * @return int 
	 */
	int GetPos();
	/**
	 * @brief Gets the saved position of special
	 * 
	 * @return int 
	 */
	int GetSavePos();
	/**
	 * @brief Changes the position
	 * 
	 * @param NewPos 
	 */
	void SetPos(int NewPos);
	/**
	 * @brief Saves position in a special int but saves current position
	 * 
	 */
	void SavePos();
	/**
	 * @brief Saves position in a special int 
	 * 
	 * @param NewPos 
	 */
	void SavePos(int NewPos);


};
#endif //__lexer_hh_