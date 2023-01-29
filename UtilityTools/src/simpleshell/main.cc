#include <iostream>
#include <unistd.h>
#include <limits.h>

int main(int argc , char** argv) {
	std::string prefix , buffer;
	if(argc == 1) { // only 1 arg supplied
		prefix = "";
	} else {
		for(int i = 1; i < argc; i++) // starting at second arg because the first is the location of the binary
			prefix += (std::string) argv[i] + " "; // added space at end otherwise everything clups together
	}
  	char hostname[HOST_NAME_MAX+1];
  	gethostname(hostname, HOST_NAME_MAX+1);

	std::string _USER = getlogin();
	std::string _HOST = hostname;

	while(1) {
		std::cout << _USER << "@" << _HOST << ">> ";
		getline(std::cin , buffer); // gets all of cin in a string

    	if (std::cin.eof()) {// checks for EOF removing this will cause an infinte loop on EOF
			std::cout << std::endl << "Exit." << std::endl;
			break;
		}

		int errcode = system((prefix + buffer).c_str());
		std::cout << "Exited with code: " << errcode << std::endl;
		buffer.erase(); // buffer gets cleared
	}
}