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
 * @file Compiler.hh
 * @author 
 * > Discord: TheDuck#2454
 * @brief Header for Compiler.cc
 * @date 2022-12-19
 * 
 */
#ifndef __compiler_hh_
#define __compiler_hh_

#include <vector>

using std::vector;

#include "Start.hh"
#include "Lexer.hh"
#include "Common.hh"
#include "ColourMod.hh"
#include "Data.hh"

class COMPILER {
	public:
		/**
		 * @brief handles the args and returns the value
		 * @note needs __DATA__HandleArgs to first check if values are in right order and everything is correct otherwise it won't work
		 * @param Ember 
		 * @param StrSize 
		 * @return vector<string> 
		 */
		static vector<string> __DATA__HandleArgs(EMBERLANG &Ember, const int &StrSize);
		/**
		 * @brief Checks args if they are correct on error will return error code what it expects and what it got
		 * 
		 * @param Ember lexer
		 * @param ExpectedArg which args it should expect
		 * @param StrSize size of ExpectedArg
		 * @return int 
		 * 0: No errors
		 * 1: SyntaxError
		 * 2: ValueError 
		 */
		static auto __DATA__CheckArgs(EMBERLANG& Ember, const vector<string>& ExpectedArg, const int& StrSize);
		/**
		 * @brief Stores all the builtin functions
		 * 
		 */
		class Functions {
			public:
			/**
			 * @brief printf using std C library
			 * 
			 * @param Ember lexer
			 * @param Gas compiled output handler
			 */
			void __MBR____printf(EMBERLANG &Ember, GASCOMPILED &Gas);
			/**
			 * @brief returns to std C library
			 * 
			 * @param Ember lexer
			 * @param Gas 
			 */
			void __MBR____return(EMBERLANG &Ember, GASCOMPILED &Gas);
		};
		/**
		 * @brief General function to handle all identifiers
		 * 
		 * @param Ember lexer
		 */
		void Handle_identifiers(EMBERLANG &Ember, GASCOMPILED &Gas);
		/**
		 * @brief Finds something in string
		 * 
		 * @param str string
		 * @param search what it should find
		 * @return true 
		 * @return false 
		 */
		bool FindInString(string &str,string search);
};

#endif //__compiler_hh_