#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T data; // хранимые данные элемента
	Node* Next, *Prev; // указатели на соседние элементы
};

template <class T>
class List
{
	Node<T>* Head, *Tail; // указатели на крайние элементы
	int Count; // количество элементов в листе
public:
	List() : Head(NULL), Tail(NULL), Count(0) {};
	~List();

	void Show(); // получение данных из списка
	void Add(T data); // добавление элемента в конец списка
	void Delete(); // удаление элемента из конца списка

	bool operator == (const List<T>&);  //перегрузка оператора ==

	//перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, const List<T>& List)
	{
		Node<T>* temp = List.Head;
		while (temp != NULL)
		{
			os << temp->data << " ";
			temp = temp->Next;
		}
		os << endl;
		return os;
	}
};

template <class T>
List<T>::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

template <class T>
void List<T>::Add(T data)
{
	Node<T>* temp = new Node<T>;
	temp->Next = NULL;
	temp->data = data;

	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
	Count++;
}

template <class T>
void List<T>::Delete()
{
	Node<T>* temp = Tail;
	Tail = Tail->Prev;
	Tail->Next = NULL;
	Count--;
	delete temp;
}

template <class T>
void List<T>::Show()
{
	Node<T>* temp = Head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->Next; 
	}
	cout << "\n";
}

template <class T>
bool List<T>::operator == (const List<T>& List)
{
	if (Count != List.Count)
	{
		return false;
	}

	Node<T>* element_List1, *element_List2;
	element_List1 = Head;
	element_List2 = List.Head;

	while (element_List1 != NULL)
	{
		if (element_List1->data != element_List2->data)
		{
			return false;
		}

		element_List1 = element_List1->Next;
		element_List2 = element_List2->Next;
	}

	return true;
}

void readNumber(int &size)
{
	bool isNotCorrect = true;
	while (isNotCorrect) {
		while (!(cin >> size))
		{
			cout << "Некорректные данные! Повторите ввод ..\n";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if (size > 1) {
			isNotCorrect = false;
		}
		else {
			cout << "Минимальное количество элементов списка = 2! Повторите ввод ..\n";
		}
	}
	
}

template <class T>
void readElements(List<T>& List, int size) {
	int element;
	while (size > 0)
	{
		cout << "Элемент списка: ";
		cin >> element;
		List.Add(element);
		size--;
	} 
}

template <class T>
void isEqual(List<T>& firstList, List<T>& secondList)
{
	if (firstList == secondList)
	{
		cout << "Списки равны." << endl;
	}
	else
	{
		cout << "Списки неравны." << endl;
	}
}

int main()
{
	/*List<char> firstList; 
	firstList.Add('f');
	firstList.Add('=');
	firstList.Add('4');
	firstList.Add('-');

	List<char> secondList; 
	secondList.Add('f'); 
	secondList.Add('=');
	secondList.Add('4');
	secondList.Add('+');*/
	
	setlocale(LC_ALL, "Russian");
	
	List<int> firstList;
	List<int> secondList;

	int firstsize = 0, secondsize = 0;

	cout << "Введите количество элементов первого списка: ";
	readNumber(firstsize);
	readElements(firstList, firstsize);

	cout << "Введите количество элементов второго списка: ";
	readNumber(secondsize);
	readElements(secondList, secondsize); //*/
	
	cout << firstList << secondList;

	isEqual(firstList, secondList);

	firstList.Delete();	
	secondList.Delete();
	cout << firstList << secondList;
}