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
 * @file ColourMod.hh
 * @author 
 * > Discord: TheDuck#2454
 * @brief Header for ColourMod.cc
 * @date 2022-12-19
 * 
 */

#ifndef __colourmod_hh_
#define __colourmod_hh_

#include "Common.hh"

namespace Colour {
	// Checks for errors
	void Check(int &code);
	// Resets the colour
	string Reset();
	// regular
	string Black();
	string Red();
	string Green();
	string Yellow();
	string Blue();
	string Purple();
	string Cyan();
	string White();
	// Bold
	string BBlack();
	string BRed();
	string BGreen();
	string BYellow();
	string BBlue();
	string BPurple();
	string BCyan();
	string BWhite();

};

#endif //__colourmod_hh_
