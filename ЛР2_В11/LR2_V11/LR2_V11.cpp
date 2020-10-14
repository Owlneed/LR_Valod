#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, del,ch;
	cout << "Количество элементов стека = ";
	cin >> n;

	if (n > 0) {

		Stack first(n); //инициализация объекта first

		int ct = 0;
		while (ct++ < n)
		{
			cout << "[" << ct << "] - ";
			cin >> ch;
			first.push(ch); // добавляем элементы в стек
		}

		cout << "Элементы стека:\n";
		first.printStack();

		int ct2 = 0;
		cout << "Количество элементов, которые необходимо удалить = ";
		cin >> del;
		if (del > 0 && del <= n) {
			while (ct2++ < del)
			{
				first.pop(); // удаляем элементы из стека
			}
			cout << "Верхний элемент: " << first.peek() << endl;
			cout << "Размер стека: " << first.size() << endl;
		}
		else if (del == 0) {
				cout << "Верхний элемент: " << first.peek() << endl;
				cout << "Размер стека: " << first.size() << endl;
		}
		else{
			cout << "Число должно быть положительным или равным нулю, а также быть меньше, чем количество элементов стека!";
		}

		return 0;
	}
	else {
		cout << "Введите положительное число!";
	}
}





