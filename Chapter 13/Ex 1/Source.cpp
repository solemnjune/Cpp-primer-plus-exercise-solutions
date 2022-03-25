#include "pch.h"
#include <iostream> 
#include "Classes.h" 


Cd::Cd(const char* s1, const char* s2, int n, double x) {
	strncpy_s(performers, s1,49);
	performers[49] = '\0';
	strncpy_s(label, s2,19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::~Cd() {

}
Cd::Cd() {
	strncpy_s(performers, "null",5);
	strncpy_s(label, "null", 5);
	selections = 0;
	playtime = 0;
}

void Cd::Report() const{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl<<std::endl;
}

Classic::Classic(const char* s1, const  char* s2, const  char* s3, int n, double x)
				:Cd(s2, s3, n, x)
{
	strncpy_s(mainName, s1, 49);
	mainName[49] = '\0';
}

Classic::Classic(const Cd&d, const char*s1)
				: Cd(d) {
	strncpy_s(mainName, s1, 49);
	mainName[49] = '\0';
}

Classic::Classic()  {
	strncpy_s(mainName, "null", 5);
}

void Classic::Report() const {
	std::cout << "Main track: " << mainName << std::endl;
	Cd::Report();
}
