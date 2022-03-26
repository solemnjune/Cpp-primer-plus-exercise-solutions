#include "pch.h"
#include "People.h"

//------------------------------------------------------------------------------------
//методы abstr_emp
//------------------------------------------------------------------------------------
abstr_emp::abstr_emp(): fname("no fname"), lname ("no lname"), job ("no job")
{
}
//------------------------------------------------------------------------------------
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
	const std::string & j): fname(fn), lname(ln), job(j)
{
}
//------------------------------------------------------------------------------------
abstr_emp::~abstr_emp(){}
//------------------------------------------------------------------------------------
void abstr_emp::ShowAll() const {
	std::cout << "First name: " << fname << std::endl;
	std::cout << "Last name: " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}
//------------------------------------------------------------------------------------
void abstr_emp::SetAll() {
	std::cout << "Enter first name: ";
	std::getline(std::cin, fname);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter job: ";
	std::getline(std::cin, job);
}
//------------------------------------------------------------------------------------
std::ostream &  operator<<(std::ostream & os, const abstr_emp & e) {
	os << "First name: " << e.fname << std::endl;
	os << "Last name: " << e.lname << std::endl;
	return os;
} 
//------------------------------------------------------------------------------------
//методы employee
//------------------------------------------------------------------------------------
employee::employee() :abstr_emp() {}
//------------------------------------------------------------------------------------
employee::employee(const std::string & fn, const std::string & ln,
	const std::string & j) : abstr_emp(fn, ln, j)
{
}
//------------------------------------------------------------------------------------
void employee::ShowAll() const {
	 std::cout << "Status: employee" << std::endl;
	 abstr_emp::ShowAll();
}
//------------------------------------------------------------------------------------
 void employee::SetAll() {
	 abstr_emp::SetAll();
} 

 //------------------------------------------------------------------------------------
//методы manager
//-------------------------------------------------------------------------------------
 manager::manager() :abstr_emp(), inchargeof(0)
 {
 }
 //------------------------------------------------------------------------------------
 manager::manager(const std::string & fn, const std::string & ln,
	 const std::string & j, int ico): abstr_emp(fn,ln,j), inchargeof(ico)
 {
 }
 //------------------------------------------------------------------------------------
 manager::manager(const abstr_emp & e, int ico):abstr_emp(e), inchargeof(ico)
 {
 }
 //------------------------------------------------------------------------------------
 manager::manager(const manager & m):abstr_emp(m) {
	 inchargeof = m.inchargeof;
 }
 //------------------------------------------------------------------------------------
 void manager::ShowAll() const {
	 std::cout << "Status: manager" << std::endl;
	 abstr_emp::ShowAll();
	 std::cout << "In charge of " << inchargeof <<" employees"<< std::endl;
 }
 //------------------------------------------------------------------------------------
 void manager::SetAll() {
	 abstr_emp::SetAll();
	 std::cout << "Enter how many people this manager is charge of: ";
	 std::cin >> inchargeof;
 }
 //------------------------------------------------------------------------------------
 //методы fink
//-------------------------------------------------------------------------------------
 fink::fink() :abstr_emp(), reportsto("No reports")
 {
 }
 //-------------------------------------------------------------------------------------
 fink::fink(const std::string & fn, const std::string & ln,
	 const std::string & j, const std::string & rpo) :abstr_emp(fn,ln,j), reportsto(rpo)
 {
 }
 //-------------------------------------------------------------------------------------
 fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo)
 {
 }
 //-------------------------------------------------------------------------------------
 fink::fink(const fink & e):abstr_emp(e)
 {
	 reportsto = e.reportsto;
 }
 //-------------------------------------------------------------------------------------
 void  fink::ShowAll() const {
	 std::cout << "Status: fink" << std::endl;
	 abstr_emp::ShowAll();
	 std::cout << "Report to " << reportsto  << std::endl;
 }
 //-------------------------------------------------------------------------------------
 void  fink::SetAll() {
	 abstr_emp::SetAll();
	 std::cout << "Enter to whom this fink reports to: ";
	 std::getline(std::cin, reportsto);
 }
 //------------------------------------------------------------------------------------
//методы fink
//-------------------------------------------------------------------------------------
 highfink::highfink():abstr_emp(),manager(),fink()
 {
 }
 //-------------------------------------------------------------------------------------
 highfink::highfink(const std::string & fn, const std::string & ln,
	 const std::string & j, const std::string & rpo, int ico)
	 :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
 {
 }
 //-------------------------------------------------------------------------------------
 highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico):abstr_emp(e),manager(e, ico), fink(e, rpo)
 {
 }
 //-------------------------------------------------------------------------------------
 highfink::highfink(const fink & f, int ico): fink(f)
 {
	 manager::InChargeOf() = ico;
 }
 //-------------------------------------------------------------------------------------
 highfink::highfink(const manager & m, const std::string & rpo):manager(m)
 {
	 fink::ReportsTo() = rpo;
 }
 //-------------------------------------------------------------------------------------
 highfink::highfink(const highfink & h):abstr_emp(h),manager(h),fink(h) {

 }
 //-------------------------------------------------------------------------------------
 void highfink::ShowAll() const {
	 std::cout << "Status: highfink" << std::endl;
	 abstr_emp::ShowAll();
	 std::cout << "Reports to " << fink::ReportsTo() << std::endl;
	 std::cout << "In charge of " << manager::InChargeOf() << " employees" << std::endl;
 }
 //-------------------------------------------------------------------------------------
 void highfink::SetAll() {
	 abstr_emp::SetAll();
	 std::cout << "Enter to whom this fink reports to: ";
	 std::getline(std::cin, fink::ReportsTo());
	 std::cout << "Enter how many people this manager is charge of: ";
	 std::cin >> manager::InChargeOf();
 }
 
