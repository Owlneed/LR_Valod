#include <iostream>

using namespace std;

class bMoney
{
	long double money;

public:
	bMoney(long double = 0.0); //конструктор

	long double get_value(); //функция-компонент класса bMoney

	//friend-объявление функции-операци
	friend bMoney operator*(long double, bMoney const&); 
	friend bMoney operator/(long double, bMoney const&);
	//функции-операции 
	bMoney operator+(long double);
	bMoney operator-(long double);
	bMoney operator%(long double);
};

bMoney::bMoney(long double value) //определение конструктора
{
	money = value;
}

long double bMoney::get_value()
{
	return money;
}

bMoney operator*(long double value, bMoney const& moneyObj)
{
	return value * moneyObj.money;
}

bMoney operator/(long double value, bMoney const& moneyObj)
{
	return value / moneyObj.money;
}

bMoney bMoney::operator+(long double value)
{
	return value + money;
}

bMoney bMoney::operator-(long double value)
{
	return value - money;
}

bMoney bMoney::operator%(long double value)
{
	return fmod(value, money); // остаток от деления с помощью % в С++ можно использовать только с целочисленными переменными, для дробных используется функция fmod
}

int main()
{
	setlocale(LC_ALL,"Russian");
	long double x = 0.0, y = 0.0, value = 0.0;

	cout << "Введите первое значение: ";
	cin >> x;
	bMoney first(x);

	cout << "Введите второе значение: ";
	cin >> y;
	bMoney second(y);

	cout << "Введите вещественное число: x.x";
	cin >> value;

	cout << endl << value << " * " << first.get_value() << " = ";
	first = value * first;
	cout << first.get_value() << endl;

	cout << endl << value << " / " << first.get_value() << " = ";
	first = value / first;
	cout << first.get_value() << endl;

	cout << endl << value << " * " << second.get_value() << " = ";
	second = value * second;
	cout << second.get_value() << endl;

	cout << endl << value << " / " << second.get_value() << " = ";
	second = value / second;
	cout << second.get_value() << endl;

	cout << endl << second.get_value() << " + " << value << " = ";
	second = second + value;
	cout << second.get_value() << endl;

	cout << endl << second.get_value() << " - " << value << " = ";
	second = second - value;
	cout << second.get_value() << endl;

	cout << endl << second.get_value() << " % " << value << " = ";
	second = second % value;
	cout << second.get_value() << endl;
}



