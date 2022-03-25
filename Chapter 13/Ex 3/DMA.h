#pragma once
// dma.h — наследование и динамическое выделение памяти     
#include <iostream>


class DMA {
private:
	char* label;
	int rating;
protected:
	const char* showLabel() const { return label; }
	const int showRating() const { return rating; }
public:
	DMA(const char* l = "null", int r = 0);
	DMA(const DMA &d);
	virtual ~DMA();
	DMA& operator=(const DMA & d);
	virtual void view() const = 0;
	friend std::ostream & operator<<(std::ostream & os, const DMA & rs);
};



//-------------------------------------------------------------------------------------------------
// Базовый класс, использующий динамическое вьщеление памяти 
class baseDMA:public DMA
{
private:
public:
	baseDMA(const char * l = "null", int r = 0) :DMA(l, r) {};
	baseDMA(const baseDMA & rs) :DMA(rs) {};
	virtual ~baseDMA() {};
	baseDMA & operator=(const baseDMA & rs);
	void view() const ;
	friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};
//-------------------------------------------------------------------------------------------------
// Производный класс без динамического вьщеления памяти 
// Деструктор не нужен 
// Используется неявный конструктор копирования 
// Используется неявная операция присваивания 
class lacksDMA : public DMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * с = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const DMA & rs);
	void view() const;
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};
//-------------------------------------------------------------------------------------------------
// Производный класс с динамическим выделением памяти 
class hasDMA : public DMA
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const DMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & rs);
	void view() const;
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
};
//-------------------------------------------------------------------------------------------------
