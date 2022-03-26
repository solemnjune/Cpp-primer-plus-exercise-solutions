#pragma once
#include <iostream>
#include <stdexcept>
//-------------------------------------------------------------------------------------------------
class bad_means :public std::logic_error {
	double a;
	double b;
protected:
	double get_a() { return a; }
	double get_b() { return b; }
public:
	bad_means(double x, double y, const std::string what_arg= "bad mean" ): a(x), b(y), logic_error(what_arg){}
	virtual void display() = 0;
};
//-------------------------------------------------------------------------------------------------
class bad_hmean :public bad_means
{

public:
	bad_hmean(double x, double y, const std::string what_arg = "Error in hmean(): invalid arguments: a = -b! \n") : bad_means(x,y, what_arg) {}
	virtual void display();
};
//-------------------------------------------------------------------------------------------------
class bad_gmean :public  bad_means
{
public:
	bad_gmean(double x, double y,  const std::string what_arg = "Error in gmean(): gmean() arguments should be >= 0! \n") : bad_means(x, y, what_arg) {}
	virtual void display();

};
//-------------------------------------------------------------------------------------------------
void bad_hmean::display() {
	std::cout << what();
	std::cout << get_a() << " = -(" << get_b() << ") \n";

}
//-------------------------------------------------------------------------------------------------
void bad_gmean::display() {
	std::cout << what();
	if (get_a() < 0 && get_b() < 0) {
		std::cout << "Both operators are less, than zero: "
			<< get_a() << " < 0 " << get_b() << " < 0" << std::endl;
	}
	else {
		std::cout << (get_a() < 0 ? get_a() : get_b()) <<" < 0"<< std::endl;
	}
}
