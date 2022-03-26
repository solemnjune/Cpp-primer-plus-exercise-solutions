#pragma once
template <class T>
class QueueTp
{
private:
	// Определения области действия класса 
	// Node - вложенная структура, локальная для данного класса 
	struct Node {
		T item;
		struct Node* next;
		//~node() { delete item; }
	};
	enum { Q_SIZE = 10 };
	// Закрытые члены класса 
	Node* front;			// указатель на начало QueueTp 
	Node* rear;			// указатель на конец QueueTp 
	int items;				// текущее количество элементов в QueueTp 
	const int qsize;		// максимальное количество элементов в QueueTp 

	// Упреждающие объявления для предотвращения открытого копирования 
	QueueTp(const QueueTp & q) : qsize(0) { }
	QueueTp & operator=(const QueueTp & q) { return *this; }
public:
	QueueTp(int qs = Q_SIZE); // создание очереди с предельным размером qs 
	~QueueTp();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const T &item); // добавление элемента в конец 
	bool dequeue(T &item);		// удаление элемента из начала 
};
//-------------------------------------------------------------------------------------------------
template <class T>
QueueTp<T>::QueueTp(int qs) : qsize(qs) {
	front = rear = nullptr; 
	items = 0;
}
//-------------------------------------------------------------------------------------------------

template <class T>
QueueTp<T>::~QueueTp() {
	Node* temp;
	while (front != nullptr)		// пока очередь не пуста 
	{
		temp = front;			// сохранение адреса начального элемента 
		front = front->next;	// переустановка указателя на следующий элемент 
		delete temp;			// удаление предыдущего начального элемента 
	}
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool QueueTp<T>::isempty() const {
	return items == 0;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool QueueTp<T>::isfull() const {
	return items == qsize;

}
//-------------------------------------------------------------------------------------------------
template <class T>
int QueueTp<T>::queuecount() const {
	return items;

}
//-------------------------------------------------------------------------------------------------
template <class T>
bool QueueTp<T>::enqueue(const T &item) {
	if (isfull())
		return false;
	Node* add = new Node; // создание узла 

	// При неудачном выполнении операция new генерирует исключение std::bad_alloc 
	add->item = item;		// занесение указателей на узлы 
	add->next = nullptr;		// или nullptr; 
	items++;
	if (front == nullptr)		// если очередь пуста, 
		front = add;		// элемент помещается в начало 
	else
		rear->next = add;	// иначе он помещается в конец 
	rear = add;				// указатель конца указывает на новый узел 
	return true;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool QueueTp<T>::dequeue(T &item) {
	if (front == nullptr)
		return false;
	item = front->item;		// в item заносится первый элемент из очереди 
	items--;
	Node* temp = front;	// сохранение местоположения первого элемента 
	front = front->next;	// сдвиг указателя начала на следующий элемент 
	delete temp;			// удаление предыдущего первого элемента 
	 
	if (items == 0)
		rear = nullptr;
	return true;
}
