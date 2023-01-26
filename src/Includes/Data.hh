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
 * @file Data.hh
 * @author 
 * > Discord: TheDuck#2454
 * @brief Header for Data.cc
 * @date 2022-12-19
 * 
 */
#ifndef __data_hh_
#define __data_hh_

#include "Common.hh"
#include "ColourMod.hh"

#include <unordered_map>
#include <algorithm>

#define GLOBAL_ARRAY_SIZE 30
/**
 * @brief All lexer types e.g. identifier , bracket...
 * 
 */
extern "C" string Types[GLOBAL_ARRAY_SIZE];
/**
 * @brief All exit codes for Ember
 * 
 */
extern "C" string ExitCodes[GLOBAL_ARRAY_SIZE];
/**
 * @brief Exit without using any data from lexer
 * 
 * @param Code Error code
 * @param details Details for exit
 */
void PreLexExit(int Code, string details);

// GNU assembly compiled text
class GASCOMPILED {
	public:
	static string SectionMain;
	static string SectionMainLast;
	static int Counter;
};

// Optimsation to msg and then ending of it
extern "C" std::unordered_map<int, string> MBR_MSGES;

#endif //__data_hh_