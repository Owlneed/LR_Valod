#include <iostream>

using namespace std;

 // Константа для размера стека
#define SIZE 10

class Stack
{
	int* arr;
	int top; 
	int capacity; 
public:
	Stack(int size = SIZE); 	// Объявление конструктора
	~Stack();   				// Объявление деструктора

	 //Объявление функций для работы со стеком
	void push(int); 
	int pop(); 
	int peek(); 
	void printStack(); 
	int size(); 
};

// Конструктор для создания стека
Stack::Stack(int size) //определение конструктора
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

// Деструктор для освобождения памяти
Stack::~Stack() //определение деструктора
{
	delete[] arr;
}

// Добавление элемента в стек
void Stack::push(int x)
{
	arr[++top] = x;
}

// Удаление верхнего элемента из стека
int Stack::pop()
{
	cout << "Удалить:" << peek() << endl;

	// уменьшаем размера стека на 1 и возвращаем верхний элемент стека
	return arr[top--];
}

// Функция для возвращения конкретного элемента из стека
int Stack::peek()
{
	return arr[top];
}

// Функция, которая возвращает размер стека
int Stack::size()
{
	return top + 1;
}

// Вывод стека, с использованием рекурсии
void Stack::printStack()
{
	if (top < 0)
	{
		return;
	}
	int x = arr[top--];  // удалить
	cout << x << " " << endl;
	printStack();
	arr[++top] = x;   // добавить
}

