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
 * @file ColourMod.cc
 * @author 
 * > Discord: TheDuck#2454
 * @brief Changes the colour of the output on the console
 * @date 2022-12-19
 * 
 */

#include "Includes/ColourMod.hh"

#if defined(__USING_BASH__)
namespace Colour{
	void Check(int &code){
		if(code != 0)
			std::cerr<<"Error while printint in colour\nAborting"<<endl;
		
	}

	string Reset() {return "\033[0m";}
	//regular
	string Black() {return "\033[0;30m";}
	string Red() {return "\033[0;31m";}
	string Green() {return "\033[0;32m";}
	string Yellow() {return "\033[0;33m";}
	string Blue() {return "\033[0;34m";}
	string Purple() {return "\033[0;35m";}
	string Cyan() {return "\033[0;36m";}
	string White() {return "\033[0;37m";}
	//Bold
	string BBlack() {return "\033[1;30m";}
	string BRed() {return "\033[1;31m";}
	string BGreen() {return "\033[1;32m";}
	string BYellow() {return "\033[1;33m";}
	string BBlue() {return "\033[1;34m";}
	string BPurple() {return "\033[1;35m";}
	string BCyan() {return "\033[1;36m";}
	string BWhite() {return "\033[1;37m";}

};
/**
 * @brief For Windows use only
 * 
 */
#else
/**
 * @brief Simple namespace which changes the colouroutput
 * 
 */
namespace Colour{
	void Check(int &code){
		if(code != 0)
			std::cerr<<"Error while printint in colour\nAborting"<<endl;
	}
	//Make own script here for changing colour for other platforms
	string Reset(){return "";}
	//regular
	string Black() {return "";} 
	string Red() {return "";} 
	string Green() {return "";} 
	string Yellow() {return "";} 
	string Blue() {return "";} 
	string Purple() {return "";} 
	string Cyan() {return "";} 
	string White() {return "";} 
	//Bold
	string BBlack() {return "";} 
	string BRed() {return "";} 
	string BGreen() {return "";} 
	string BYellow() {return "";} 
	string BBlue() {return "";} 
	string BPurple() {return "";} 
	string BCyan() {return "";} 
	string BWhite() {return "";} 
};

#endif