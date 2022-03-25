#include "pch.h"
#include <iostream> 
#include "Classes.h" 


Cd::Cd(const char* s1, const char* s2, int n, double x) {
	performers = new char[strlen(s1)+1];
	strcpy_s(performers,strlen(s1)+1, s1);
	label = new char[strlen(s2) + 1];
	strcpy_s(label, strlen(s2)+1 , s2);
	selections = n;
	playtime = x;
}


Cd::Cd() {
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0;
}

Cd::Cd(const Cd &d) {
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers)+1 , d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) +1, d.label);
	selections = d.selections;
	playtime = d.playtime;
}


Cd::~Cd() {
	delete[] performers;
	delete[] label;
}

Cd& Cd::operator=(const Cd&d) {
	if (this == &d) {
		return *this;
	}
	delete[] performers;
	delete[] label;

	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers)+1 , d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) +1, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

void Cd::Report() const {
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl << std::endl;
}

Classic::Classic(const char* s1, const  char* s2, const  char* s3, int n, double x)
	:Cd(s2, s3, n, x)
{
	mainName = new char[strlen(s1) + 1];
	strcpy_s(mainName, strlen(s1)+1 , s1);
}

Classic::Classic(const Cd&d, const char*s1)
	: Cd(d) {
	mainName = new char[strlen(s1) + 1];
	strcpy_s(mainName, strlen(s1)+1 , s1);
}

Classic::Classic() {
	mainName = nullptr;
}

Classic::Classic(const Classic &d)
	:Cd(d)
{
	mainName = new char[strlen(d.mainName) + 1];
	strcpy_s(mainName, strlen(d.mainName)+1, d.mainName);
}


Classic ::~Classic() {
	delete[] mainName;
}

Classic & Classic::operator=(const Classic& d) {
	if (this == &d) {
		return *this;
	}
	Cd::operator=(d);
	delete[] mainName;

	mainName = new char[strlen(d.mainName) + 1];
	strcpy_s(mainName, strlen(d.mainName)+1, d.mainName);
	return *this;
}

void Classic::Report() const {
	std::cout << "Main track: " << mainName << std::endl;
	Cd::Report();
}
