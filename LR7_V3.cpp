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
	List(const List& list) : List()
	{
		Node<T>* node = list.Head;
		while (node) {
			Add(node->data);
			node = node->Next;
		}
	}
	~List();

	void Show(); // получение данных из списка
	void Add(T data); // добавление элемента в конец списка
	void Delete(); // удаление элемента из конца списка

	bool operator == (const List<T>&); //перегрузка оператора ==

	//перегрузка оператора вывода
	friend ostream& operator<<(ostream& os, const List<T>& L)
	{
		Node<T>* temp = L.Head;
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
bool List<T>::operator == (const List<T>& L)
{
	if (Count != L.Count)
	{
		return false;
	}

	Node<T>* t1, *t2;
	t1 = Head;
	t2 = L.Head;

	while (t1 != NULL)
	{
		if (t1->data != t2->data)
		{
			return false;
		}

		t1 = t1->Next;
		t2 = t2->Next;
	}

	return true;
}

template <class T>
class Transaction //класс поддержки транзакций
{
	T* that; //текущее значение 
	T* prev; //предыдущее значение 
public:
	Transaction() : prev(NULL), that(new T) {}
	Transaction(const Transaction& obj) : prev(NULL), that(new T(*(obj.that))) {}
	~Transaction()
	{
		delete that;
		delete prev;
	}
	Transaction& operator= (const Transaction& obj);
	void Show(int);
	int BeginTransaction(); //начало транзакции
	void Commit(); //закрепление транзакции
	void DeleteTransaction(); //отмена транзакции
	T* operator->();
};

template <class T>
Transaction<T>& Transaction<T>::operator= (const Transaction<T>& obj)
{
	if (this != &obj)
	{
		delete that;
		that = new T(*(obj.that));
	}
	return *this;
}

template <class T>
T* Transaction<T>::operator->()
{
	return that;
}

template <class T>
void Transaction<T>::Show(int fl)
{
	cout << "Object state ";
	if (!fl)
	{
		cout << "Before the transaction " << endl;
	}
	else
	{
		cout << "After the transaction " << endl;
	}

	if (prev)
	{
		cout << "prev = ";
		prev->Show();
	}
	else
	{
		cout << "prev = NULL" << endl;
	}
	cout << "that = ";
	that->Show();
}

template <class T>
int Transaction<T>::BeginTransaction()
{
	delete prev;
	prev = that;
	that = new T(*prev);

	if (!that)
	{
		return 0;
	}

	that->Add(9);

	return 1;
}

template <class T>
void Transaction<T>::Commit()
{
	delete prev;
	prev = NULL;
}

template <class T>
void Transaction<T>::DeleteTransaction()
{
	if (prev != NULL)
	{
		delete that;
		that = prev;
		prev = NULL;
	}
}

template <class T>
void isEqual(List<T>& transaction, List<T>& transaction2)
{
	if (transaction == transaction2)
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
	Transaction<List<int>> transaction;
	transaction->Add(4);
	transaction->Add(2);
	transaction->Add(8);
	transaction.Show(0);

	if (transaction.BeginTransaction())
	{
		transaction.Show(1);
		transaction.Commit();
	}
	transaction.Show(0);

	if (transaction.BeginTransaction())
	{
		transaction.Show(1);
		transaction.Commit();
	}
	transaction.Show(0);


	transaction.BeginTransaction();
	transaction->Add(2);
	transaction.Show(1);
	transaction.DeleteTransaction();
	transaction.Show(0);

}


