#include "pch.h"
#include "DMA.h"

//dma.cpp — методы классов с динамическим выделением памяти 
#include <cstring>


DMA::DMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}


DMA::DMA(const DMA & d)
{
	label = new char[std::strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	rating = d.rating;
}

DMA::~DMA() {
	delete[] label;
}

DMA &DMA::operator=(const DMA & d)
{
	if (this == &d)
		return *this;
	delete[] label;
	label = new char[std::strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	rating = d.rating;
	return *this;
}


std::ostream & operator<<(std::ostream & os, const DMA & d)
{
	os << "Label: " << d.label << std::endl; // название 
	os << "Rating: " << d.rating << std::endl; // рейтинг 
	return os;
}
//-------------------------------------------------------------------------------------------------
// Методы baseDMA 
//-------------------------------------------------------------------------------------------------
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if (this == &rs)
		return *this;
	DMA::operator=(rs);
	return *this;
}
//-------------------------------------------------------------------------------------------------
void baseDMA::view() const {
	std::cout << "Label: " << showLabel() << "; Rating: " << showRating() << std::endl;
}

//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << (const DMA&)rs;
	return os;
}
//-------------------------------------------------------------------------------------------------
// Методы lacksDMA 
//-------------------------------------------------------------------------------------------------
lacksDMA::lacksDMA(const char * c, const char * l, int r)
	: DMA(l, r)
{
	strncpy_s(color, c, 39);
	color[39] = '\0';
}
//-------------------------------------------------------------------------------------------------
lacksDMA::lacksDMA(const char * c, const DMA & rs)
	: DMA(rs)
{
	strncpy_s(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = ' \0 ';
}
//-------------------------------------------------------------------------------------------------
void lacksDMA::view() const {
	std::cout << "Label: " << showLabel() << "; Rating: " << showRating() 
	<<"; Color: "<< color	<< std::endl;

}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<< (std::ostream & os, const lacksDMA & Is)
{
	os << (const DMA &)Is;
	os << "Color: " << Is.color << std::endl; // цвет 
	return os;
}
//-------------------------------------------------------------------------------------------------
// Методы hasDMA 
hasDMA::hasDMA(const char * s, const char * l, int r)
	: DMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}
//-------------------------------------------------------------------------------------------------
hasDMA::hasDMA(const char * s, const DMA & rs)
	: DMA(rs)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}
//-------------------------------------------------------------------------------------------------
hasDMA::hasDMA(const hasDMA & hs)
	: DMA(hs) // вызывает конструктор копирования базового класса 
{
	style = new char[std::strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}
//-------------------------------------------------------------------------------------------------
hasDMA::~hasDMA()
{
	delete[] style;
}
//-------------------------------------------------------------------------------------------------
hasDMA & hasDMA::operator=(const hasDMA & hs)
{
	if (this == &hs)
		return *this;
	DMA::operator=(hs); // копирование базовой части 
	delete[] style; // подготовка к операции new для style 
	style = new char[std::strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}
//-------------------------------------------------------------------------------------------------
void hasDMA::view() const {
	std::cout << "Label: " << showLabel() << "; Rating: " << showRating()
		<< "; Style: " << style << std::endl;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
	os << (const DMA &)hs;
	os << "Style: " << hs.style << std::endl; // стиль 
	return os;
}
