#pragma once
#include <iostream> 
#include <string> 
#include <fstream>

class abstr_emp
{
private:
    std::string fname; // имя abstr_emp 
    std::string lname; // фамилия abstr_emp 
    std::string job;
protected:
    enum classkind { Employee = 1, Manager, Fink, Highfink };

public:
    abstr_emp();
    abstr_emp(const std::string& fn, const std::string& ln,
        const std::string& j);
    virtual void ShowAll() const; // выводит все данные с именами 
    virtual void SetAll(); // запрашивает значения у пользователя 
    friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);// Выводит только имя и фамилию 
    virtual ~abstr_emp() = 0; // виртуальный базовый класс 
    virtual void WriteAll(std::fstream &file);
    virtual void GetAll(std::fstream& file);
    friend bool createEmp(abstr_emp*& pc);
    friend void fromFileEmp(abstr_emp*& pc, std::fstream & file);

};
class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string& fn, const std::string& ln,
        const std::string& j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::fstream &file);
    virtual void GetAll(std::fstream& file);
};
class manager : virtual public abstr_emp
{
private:
    int inchargeof; // количество управляемых abstr_emp 
protected:
    int InChargeOf() const { return inchargeof; } // вывод 
    int& InChargeOf() { return inchargeof; } // ввод 
public:
    manager();
    manager(const std::string& fn, const std::string& ln,
        const std::string& j, int ico = 0);
    manager(const abstr_emp& e, int ico);
    manager(const manager& m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::fstream &file);
    virtual void GetAll(std::fstream& file);

};
class fink : virtual public abstr_emp
{
private:
    std::string reportsto; // кому выводить отчеты 
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string& ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo);
    fink(const abstr_emp& e, const std::string& rpo);
    fink(const fink& e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::fstream &file);
    virtual void GetAll(std::fstream& file);

};
class highfink : public manager, public fink // надзор за управляющими 
{
public:
    highfink();
    highfink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo, int ico);
    highfink(const abstr_emp& e, const std::string& rpo, int ico);
    highfink(const fink& f, int ico);
    highfink(const manager& m, const std::string& rpo);
    highfink(const highfink& h);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(std::fstream &file);
    virtual void GetAll(std::fstream& file);

};
