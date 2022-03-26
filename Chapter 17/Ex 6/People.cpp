#include "People.h"

//------------------------------------------------------------------------------------
//методы abstr_emp
//------------------------------------------------------------------------------------
abstr_emp::abstr_emp() : fname("no fname"), lname("no lname"), job("no job")
{
}
//------------------------------------------------------------------------------------
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
	const std::string& j) : fname(fn), lname(ln), job(j)
{
}
//------------------------------------------------------------------------------------
abstr_emp::~abstr_emp() {}
//------------------------------------------------------------------------------------
void abstr_emp::ShowAll() const {
	std::cout << "First name: " << fname << std::endl;
	std::cout << "Last name: " << lname << std::endl;
	std::cout << "Job: " << job << std::endl;
}
//------------------------------------------------------------------------------------
void abstr_emp::SetAll() {
	std::cout << "Enter first name, or type \"quit\" to quit: ";
	std::getline(std::cin, fname);
	if (fname == "quit") {
		return;
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, lname);
	std::cout << "Enter job: ";
	std::getline(std::cin, job);
}
//------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
	os << "First name: " << e.fname << std::endl;
	os << "Last name: " << e.lname << std::endl;
	return os;
}
//------------------------------------------------------------------------------------
void abstr_emp::WriteAll(std::fstream &file) {
	file << fname << '\n' << lname << '\n' << job;
}
//------------------------------------------------------------------------------------
void abstr_emp::GetAll(std::fstream& file) {
	getline(file, fname);
	getline(file, lname);
	getline(file, job);
}
//------------------------------------------------------------------------------------
//методы employee
//------------------------------------------------------------------------------------
employee::employee() :abstr_emp() {}
//------------------------------------------------------------------------------------
employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j) : abstr_emp(fn, ln, j)
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
void employee::WriteAll(std::fstream& file) {
	file << '1' << ' ';
	abstr_emp::WriteAll(file);
	file << '\n';
}
//------------------------------------------------------------------------------------
void employee::GetAll(std::fstream& file) {
	abstr_emp::GetAll(file);
}
//------------------------------------------------------------------------------------
//методы manager
//-------------------------------------------------------------------------------------
manager::manager() :abstr_emp(), inchargeof(0)
{
}
//------------------------------------------------------------------------------------
manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}
//------------------------------------------------------------------------------------
manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{
}
//------------------------------------------------------------------------------------
manager::manager(const manager& m) : abstr_emp(m) {
	inchargeof = m.inchargeof;
}
//------------------------------------------------------------------------------------
void manager::ShowAll() const {
	std::cout << "Status: manager" << std::endl;
	abstr_emp::ShowAll();
	std::cout << "In charge of " << inchargeof << " employees" << std::endl;
}
//------------------------------------------------------------------------------------
void manager::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter how many people this manager is charge of: ";
	std::cin >> inchargeof;
}
//------------------------------------------------------------------------------------
void manager::WriteAll(std::fstream& file) {
	file << '2' << ' ';
	abstr_emp::WriteAll(file);
	file << '\n' << InChargeOf() << '\n';
}
//------------------------------------------------------------------------------------
void manager::GetAll(std::fstream& file) {
	abstr_emp::GetAll(file);
	file >> InChargeOf();
	file.get();
}
//------------------------------------------------------------------------------------
//методы fink
//-------------------------------------------------------------------------------------
fink::fink() :abstr_emp(), reportsto("No reports")
{
}
//-------------------------------------------------------------------------------------
fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}
//-------------------------------------------------------------------------------------
fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e), reportsto(rpo)
{
}
//-------------------------------------------------------------------------------------
fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}
//-------------------------------------------------------------------------------------
void  fink::ShowAll() const {
	std::cout << "Status: fink" << std::endl;
	abstr_emp::ShowAll();
	std::cout << "Report to " << reportsto << std::endl;
}
//-------------------------------------------------------------------------------------
void  fink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter to whom this fink reports to: ";
	std::getline(std::cin, reportsto);
}
//------------------------------------------------------------------------------------
void fink::WriteAll(std::fstream& file) {
	file << '3' << ' ';
	abstr_emp::WriteAll(file);
	file << '\n' << ReportsTo() << '\n';
}
//------------------------------------------------------------------------------------
void fink::GetAll(std::fstream& file) {
	abstr_emp::GetAll(file);
	getline(file, ReportsTo());
}
//------------------------------------------------------------------------------------
//методы highfink
//-------------------------------------------------------------------------------------
highfink::highfink() :abstr_emp(), manager(), fink()
{
}
//-------------------------------------------------------------------------------------
highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}
//-------------------------------------------------------------------------------------
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}
//-------------------------------------------------------------------------------------
highfink::highfink(const fink& f, int ico) : fink(f)
{
	manager::InChargeOf() = ico;
}
//-------------------------------------------------------------------------------------
highfink::highfink(const manager& m, const std::string& rpo) : manager(m)
{
	fink::ReportsTo() = rpo;
}
//-------------------------------------------------------------------------------------
highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h) {
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
//------------------------------------------------------------------------------------
void highfink::WriteAll(std::fstream& file) {
	file << '4' << ' ';
	abstr_emp::WriteAll(file);
	file << '\n' << fink::ReportsTo() << '\n';
	file << manager::InChargeOf() << '\n';
}
//------------------------------------------------------------------------------------
void highfink::GetAll(std::fstream& file) {
	abstr_emp::GetAll(file);
	getline(file, fink::ReportsTo());
	file >> manager::InChargeOf();

}
//-------------------------------------------------------------------------------------
// дружественные функция
//-------------------------------------------------------------------------------------
bool createEmp(abstr_emp* &pc ) {
	using namespace std;
	int classType;
		cout << "Enter the which type of employee you need to create: \n";
		cout << "1 for employee, 2 for manager, 3 for fink, 4 for highfink \n";
		cin >> classType;
		cin.get();
	switch (classType)
	{
	case abstr_emp::Employee:
		pc = new employee;
		pc->SetAll();
		break;
	case abstr_emp::Manager:
		pc = new manager;
		pc->SetAll();
		break;
	case abstr_emp::Fink:
		pc = new fink;
		pc->SetAll();
		break;
	case abstr_emp::Highfink:
		pc = new highfink;
		pc->SetAll();
		break;
	default:
		cout << "Error in creating new class: wrong classType!";
		exit(EXIT_FAILURE);
		break;
	}
	if (pc->fname == "quit") {
		delete pc;
		return 1;
	}
		return 0;
}
//-------------------------------------------------------------------------------------
void fromFileEmp(abstr_emp*& pc, std::fstream& file) {
	using namespace std;
	int classType;
	file >> classType;
	file.get();
	switch (classType)
	{
	case abstr_emp::Employee:
		pc = new employee;
		pc->GetAll(file);
		break;
	case abstr_emp::Manager:
		pc = new manager;
		pc->GetAll(file);
		break;
	case abstr_emp::Fink:
		pc = new fink;
		pc->GetAll(file);
		break;
	case abstr_emp::Highfink:
		pc = new highfink;
		pc->GetAll(file);
		break;
	default:
		cout << "Error in creating new class from file: wrong classType!";
		exit(EXIT_FAILURE);
		break;
	}
}
