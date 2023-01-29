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
 * @file Start.hh
 * @author 
 * > Discord: TheDuck#2454
 * @brief Store common macros in struct
 * @date 2022-12-19
 * 
 */
#ifndef __start_hh_
#define __start_hh_

#include "Common.hh"
/**
 * @brief assigns a variable to the preprocessor defined macros
 * 
 */
class {
	public:
	const string time = __TIME__;
	const string file = __FILE__;
	const string date = __DATE__;
	const string times = __TIMESTAMP__;
	const string version = __VERSION__;
}MacroData;

#endif //__start_hh_