## Глава - 17, Задание - 6 

Рассмотрите определение класса, предложенное в упражнении ***5*** главы ***14***. Если
вы еще не делали это упражнение, выполните его сейчас. Затем сделайте
следующее.

Напишите программу, которая использует стандартный ввод-вывод ***C++*** и
файловый ввод-вывод в сочетании с данными типов ***employee***, ***manager***, ***fink*** и
***highf ink***, как определено в упражнении ***5*** из главы ***14***. Программа должна быть
аналогична главным строкам листинга ***17.17*** в том, что должна позволять
вносить новые данные в файл. При первом запуске программа должна запросить
данные у пользователя, показать все введенные записи и сохранить
информацию в файл. При последующих запусках она должна сначала прочитать и
отобразить данные файла, дать возможность пользователю добавить новые данные и
отобразить все данные снова. Единственное отличие должно состоять в том, что
данные должны быть представлены в виде массива указателей на тип ***employee***.
Таким образом, указатель может указывать на объект ***employee*** либо на объект
любого из трех производных от него типов. Сохраняйте массив маленьким,
чтобы облегчить его проверку программой; например, его размер можно
ограничить *10* элементами:

```objectivec
const int MAX = 10; // не более 10 объектов 
...
employee * рс[МАХ]; 
```

Для клавиатурного ввода программа должна использовать меню, чтобы
предоставить пользователю выбор типа создаваемого объекта. С меню должен быть
связан оператор ***switch***, позволяющий использовать операцию ***new*** для
создания объекта требуемого типа и присваивать адрес этого объекта указателю в
массиве ***рс***. Затем этот объект может вызвать виртуальную функцию ***setall()***
для запроса соответствующих данных от пользователя:

```objectivec
рс[i]->setall (); // вызывает функцию, соответствующую типу объекта
```

Чтобы обеспечить сохранение данных в файле, необходимо объявить
виртуальную функцию ***writeall()***:

```objectivec
for (i = 0; i < index; i++)
pc[i]->writeall (fout); // объект fout типа ofstream 
						// подключен к выходному файлу
```

> ***На заметку!*** 
В упражнении ***6*** используйте текстовый, а не бинарный ввод-вывод. (К сожалению,  
виртуальные объекты содержат указатели на таблицы указателей на виртуальные функции, и
***write()*** копирует эту информацию в файл. Объект, заполняемый методом ***read()*** из
файла, получает некорректные значения указателей на функции, что приводит к путанице в
поведении виртуальных функций.) Используйте символы новой строки для отделения каждого
поля данных от следующего — это облегчит идентификацию полей при вводе. Либо
можно все же применить бинарный ввод-вывод, но не записывать объекты как единое целое.
Вместо этого можно предусмотреть методы класса, которые применяют функции ***read()*** и
***write()*** к каждому отдельному члену класса, а не к объекту в целом. Таким образом,
>программа сможет записывать в файл только необходимые данные.

Сложность представляет восстановление данных из файла. Проблема состоит в
том, как программа узнает, какого типа объект будет восстановлен следующим:
***employee***, ***manager***, ***fink*** либо ***highfink***? Один из возможных подходов к решению 
этой проблемы заключается в следующем: при записи данных объекта
в файл предварить его целым числом, идентифицирующим тип следующего
объекта. Затем при вводе из файла программа может читать это целое число
и применять ***switch*** для создания объекта соответствующего типа для приема
данных:

```objectivec
enum classkind{Employee, Manager, Fink, Highfink}; // в заголовке класса
...
int classtype; 
while((fin » classtype).get(ch)){ // символ новой строки отделяет 
								  // целое число от данных 
	switch(classtype) { 
		case Employee : pc[i] = new employee; 
			break;
```

Затем можно использовать указатель, чтобы вызвать виртуальную функцию
***getall()*** для считывания информации:

```objectivec
pc[i++]->getall();
```
