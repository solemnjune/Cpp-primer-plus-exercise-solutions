## Глава - 18, Задание - 1 

Ниже показана часть короткой программы:

```objectivec
int main () 
{ 
	using namespace std; 
	// Список double выведен из содержимого списка 
	auto q = average_list ({15.4, 10.7, 9.0}); 
	cout << q << endl; 
	// Список int выведен из содержимого списка 
	cout << average_list ({20, 30, 19, 17, 45, 38} ) << endl; 
	// Принудительное использование списка double 
	auto ad = average_list<double> ( {'A', 70, 65.33}); 
	cout << ad << endl; 
	
	return 0; 
}
```

Завершите программу, написав функцию ***averagelist()***. Она должна быть
шаблонной функцией, с параметром типа, который используется для указания
вида шаблона ***initialized_list***, применяемого в качестве параметра
функции, а также для указания возвращаемого типа функции.
