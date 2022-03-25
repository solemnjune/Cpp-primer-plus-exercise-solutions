## Глава - 13, Задание - 4 

Союз программистов-меценатов собирает коллекцию бутылочного портвейна.
Для ее описания администратор союза разработал класс ***Port***:

```objectivec
#include <iostream> 
using namespace std; 
class Port // портвейн 
{ 
private: 
	char * brand; 
	char style[20]; // например, tawny (золотистый), ruby (рубиновый), vintage (марочный) 
	int bottles = 0; 
public: 
	Port(const char* br = "none", const char* st = "none", int b = 0) ; 
	Port(const Port & p) ; // конструктор копирования 
	virtual ~Port() { delete [] brand; } 
	Port & operator= (const Port & p) ; 
	Port & operator+=(int b) ; // добавляет b к bottles 
	Port & operator-= (int b) ; // вычитает b из bottles, если это возможно 
	int BottleCount() const { return bottles; } 
	virtual void Show() const; 
	friend ostream & operator« (ostream & os, const Port & p) ; 
};
```

Метод ***Show ()*** выводит информацию в следующем формате:

```objectivec
Brand: Gallo 
Kind: tawny 
Bottles: 20
```

Функция ***operator << ()*** представляет информацию в следующем формате (без
символа новой строки в конце):

```objectivec
Gallo, tawny, 20
```

Завершив определения методов для класса ***Port***, администратор написал 
производный класс ***Vintage Port***, прежде чем был уволен:

```objectivec
class VintagePort : public Port // style обязательно = "vintage" 
{ 
private: 
	char* nickname; // т.е. "The Noble", "Old Velvet" и т.д. 
	int year; 		// год сбора 
public: 
	VintagePort(); 
	VintagePort(const char* br, int b, const char* nn, int y); 
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete [] nickname; } 
	VintagePort & operator=(const VintagePort & vp); 
	void Show() const; 
	friend ostream & operator«(ostream & os, const VintagePort & vp); 
}; 
```

Вам поручено завершить разработку класса ***VintagePort***.

*а.* - Первое задание — нужно заново создать определения методов ***Port***, т.к.
предыдущий администратор уничтожил свой код.

*б.* - Второе задание — объясните, почему одни методы переопределены, а другие
нет.

*в.* - Третье задание — объясните, почему функции ***operator = ()*** и ***operator << ()***
не определены как виртуальные.

*г.* - Четвертое задание — обеспечьте определения для методов ***VintagePort***.
