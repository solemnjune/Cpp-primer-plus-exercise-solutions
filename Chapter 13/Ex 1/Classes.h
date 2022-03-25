#pragma once
// Базовый класс 
class Cd  // представляет компакт-диск 
{
private:
	char performers[50];
	char label[20];
	int selections; // количество сборников 
	double playtime; // время воспроизведения в минутах 
public:
	Cd(const char* s1, const char* s2, int n, double x);
	//Cd(const Cd & d); не нужна
	Cd();
	virtual ~Cd(); 
	virtual void Report() const; // выводит все данные о компакт-диске 
	//Cd & operator= (const Cd & d); не нужна
};


class Classic:public Cd
{
private:
	char mainName[50];
public:
	Classic(const char* s1, const  char* s2, const  char* s3, int n, double x);
	Classic(const Cd&d, const  char*s3);
	Classic();
	virtual void Report() const;
};
