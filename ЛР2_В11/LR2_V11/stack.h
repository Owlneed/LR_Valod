#include <iostream>

using namespace std;

 // ��������� ��� ������� �����
#define SIZE 10

class Stack
{
	int* arr;
	int top; 
	int capacity; 
public:
	Stack(int size = SIZE); 	// ���������� ������������
	~Stack();   				// ���������� �����������

	 //���������� ������� ��� ������ �� ������
	void push(int); 
	int pop(); 
	int peek(); 
	void printStack(); 
	int size(); 
};

// ����������� ��� �������� �����
Stack::Stack(int size) //����������� ������������
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

// ���������� ��� ������������ ������
Stack::~Stack() //����������� �����������
{
	delete[] arr;
}

// ���������� �������� � ����
void Stack::push(int x)
{
	arr[++top] = x;
}

// �������� �������� �������� �� �����
int Stack::pop()
{
	cout << "�������:" << peek() << endl;

	// ��������� ������� ����� �� 1 � ���������� ������� ������� �����
	return arr[top--];
}

// ������� ��� ����������� ����������� �������� �� �����
int Stack::peek()
{
	return arr[top];
}

// �������, ������� ���������� ������ �����
int Stack::size()
{
	return top + 1;
}

// ����� �����, � �������������� ��������
void Stack::printStack()
{
	if (top < 0)
	{
		return;
	}
	int x = arr[top--];  // �������
	cout << x << " " << endl;
	printStack();
	arr[++top] = x;   // ��������
}

