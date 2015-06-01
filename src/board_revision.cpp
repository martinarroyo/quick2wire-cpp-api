#include "board_revision.hpp"

#define CPUINFO_PATH "/proc/cpuinfo"

int revision(){
	std::ifstream f(CPUINFO_PATH);
	std::string str;
	std::string s("Revision");
	while(std::getline(f, str)){
		//printf("%s %d\n", str.c_str(), s.compare(0, s.length(), str.substr(0, s.length())));
		if(s.compare(0, s.length(), str.substr(0, s.length())) == 0){
			//printf("%s\n", str.c_str());
			if((str.compare(str.length() - 2, str.length() -1, "2") == 0) || (str.compare(str.length() - 2, str.length() - 1, "3") == 0)){
				return 1;
			}
			return 2;
		}
	}
	return 0;
}
