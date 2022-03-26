#pragma once
#include <valarray>
#include <iostream>
#include <string>
#include "Pair.h"

//------------------------------------------------------------------------------------------------------------------------------------------------
typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;
//------------------------------------------------------------------------------------------------------------------------------------------------



class Wine : private PairArray, private std::string {

	int years;

public:
	// Инициализация label значением l, количество лет - у,
	// годы урожая - yr[], количество бутылок - bot[]
	Wine(const char* l, int у, const int yr[], const int bot[]);
	// Инициализация label значением l, количество лет - у,
	// создаются объекты массива размером у
	Wine(const char* l, int y) : std::string(l), years(y) {}
	Wine() :std::string("Null"), years(0) {}
	inline  std::string& Label() { return (std::string&)(*this); }
	void GetBottles();
	int sum() const;
	void Show() ;
};
