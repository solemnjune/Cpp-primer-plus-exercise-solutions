#include "Cpmv.h"

Cpmv::Cpmv() {
	pi = nullptr;
	std::cout << "Empty constructor was used!\n";
}
//-------------------------------------------------------------------------------------
Cpmv::Cpmv(std::string q, std::string z) {
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	std::cout << "Constructor with two strings was used!\n";
}
//-------------------------------------------------------------------------------------

Cpmv::Cpmv(const Cpmv& cp) {
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "Copy constructor was used!\n";
}
//-------------------------------------------------------------------------------------

Cpmv::Cpmv(Cpmv&& mv) {
	pi = mv.pi;
	mv.pi = nullptr;
	std::cout << "Move constructor was used!\n";
}
//-------------------------------------------------------------------------------------
Cpmv::~Cpmv() {
	delete pi;
	std::cout << "Destructor was used! \n";
}
//-------------------------------------------------------------------------------------
Cpmv& Cpmv::operator = (const Cpmv& cp) {
	if (this == &cp) {
		return *this;
	}
	delete pi;
	pi = new Info; // создание нового объекта необходимо на случай, если pi указывает на nullptr
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	std::cout << "Copy assignment operator was used!\n";
	return *this;
}
//-------------------------------------------------------------------------------------
Cpmv& Cpmv::operator = (Cpmv&& cp) {
	if (this == &cp) {
		return *this;
	}
	delete pi;
	pi = cp.pi;
	cp.pi = nullptr;
	std::cout << "Move assignment operator was used!\n";
	return *this;
}
//-------------------------------------------------------------------------------------
Cpmv Cpmv::operator+ (const Cpmv& obj) const {
	Cpmv temp = Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
	std::cout << "Plus operator was used!\n";
	return temp;
}
//-------------------------------------------------------------------------------------
void Cpmv::Display() const {
	std::cout << "qcode: " << pi->qcode << std::endl;
	std::cout << "zcode: " << pi->zcode << std::endl;
}
