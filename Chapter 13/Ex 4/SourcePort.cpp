#include "pch.h"
#include "port.h"

// Методы Port
//------------------------------------------------------------------------------------------------------------------------

Port::Port(const char* br, const char* st, int b) {
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strncpy_s(style, st, 19);
	style[19] = '\0';
	bottles = b;
}
//------------------------------------------------------------------------------------------------------------------------

Port::Port(const Port & p) {
	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strncpy_s(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
}
//------------------------------------------------------------------------------------------------------------------------

Port & Port::operator= (const Port & p) {
	if (this == &p) {
		return *this;
	}
	delete[] brand;

	brand = new char[strlen(p.brand) + 1];
	strcpy_s(brand, strlen(p.brand) + 1, p.brand);
	strncpy_s(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
	return *this;
}
//------------------------------------------------------------------------------------------------------------------------

Port & Port::operator+= (int b) {
	bottles += b;
	return *this;
}
//------------------------------------------------------------------------------------------------------------------------

Port & Port::operator-= (int b) {
	if (bottles < b) {
		std::cout << "You can't subtract more bottles, than you have" << std::endl;
		return *this;
	}
	else {
		bottles -= b;
		return *this;
	}
}
//------------------------------------------------------------------------------------------------------------------------

 void Port::Show() const {
	 std::cout << "Brand: " << brand << std::endl;
	 std::cout << "Kind: " << style << std::endl;
	 std::cout << "Bottles: " << bottles << std::endl;

}
//------------------------------------------------------------------------------------------------------------------------

 ostream & operator<<(ostream & os, const Port & p) {
	 os << p.brand << ", " << p.style << ", " << p.bottles;
	 return os;
 }
//------------------------------------------------------------------------------------------------------------------------
 // Методы VintagePort
//------------------------------------------------------------------------------------------------------------------------

 VintagePort::VintagePort() {
	 nickname = new char[1];
	 nickname[0] = '\0';
	 year = 0;
 }
 //------------------------------------------------------------------------------------------------------------------------
 VintagePort::VintagePort(const char* br, int b, const char* nn, int y):Port(br,"vintage",b) {
	 nickname = new char[strlen(nn) + 1];
	 strcpy_s(nickname, strlen(nn) + 1, nn);
	 year = y;
 }
 //------------------------------------------------------------------------------------------------------------------------
 VintagePort::VintagePort(const VintagePort & vp):Port(vp) {
	 nickname = new char[strlen(vp.nickname) + 1];
	 strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	 year = vp.year;
 }
 //------------------------------------------------------------------------------------------------------------------------
 VintagePort & VintagePort::operator=(const VintagePort & vp) {
	 if (this == &vp) {
		 return *this;
	 }
	 Port::operator=(vp);
	 nickname = new char[strlen(vp.nickname) + 1];
	 strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	 year = vp.year;
	 return *this;
 }
 //------------------------------------------------------------------------------------------------------------------------
 void VintagePort::Show() const {
	 Port::Show();
	 std::cout << "Nickname: " << nickname << std::endl;
	 std::cout << "Year: " << year << std::endl;

 }
 //------------------------------------------------------------------------------------------------------------------------
 ostream & operator<<(ostream & os, const VintagePort & vp) {
	 os << (const Port &)vp;
	 os << ", " << vp.nickname << ", " << vp.year;
	 return os;
  }
