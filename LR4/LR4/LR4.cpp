#include <iostream>
#include <string>
using namespace std;

class Products
{
	string* product_type;
	float* price;
	float* mass;

	string choose_product(int type)
	{
		switch (type)
		{
		case 1:
			return "Молоко";
			break;
		case 2:
			return "Сосиски";
			break;
		case 3:
			return "Печенье";
			break;
		default:
			exit(0);
			break;
		}
	}

public:
	Products(float price_value, float mass_value, int product_type_value)
	{
		cout << "Создание продукта..." << endl;

		product_type = new string(choose_product(product_type_value));
		cout << "Тип продукта - " << *product_type << endl;

		price = new float(price_value);
		cout << "Цена продукта - " << *price << endl;

		mass = new float(mass_value);
		cout << "Масса продукта - " << *mass << endl;
	}

	~Products()
	{
		delete price;
		delete mass;
		delete product_type;
	}
};

class Milk : Products
{
	string* package_type;
	float* fat;

public:
	Milk(float price_value, float mass_value, int product_type_value, string package_type_value, float fat_value) : Products(price_value, mass_value, product_type_value)
	{
		cout << endl << "Дополнительная информация: " << endl;

		package_type = new string(package_type_value);
		cout << "Тип упаковки - " << *package_type << endl;

		fat = new float(fat_value);
		cout << "Жирность - " << *fat << endl;
	}

	~Milk()
	{
		delete package_type;
		delete fat;
	}
};

class Sausages : Products
{
	string* type;
	int* amount;

public:
	Sausages(float price_value, float mass_value, int product_type_value, string type_value, int amount_value) : Products(price_value, mass_value, product_type_value)
	{
		cout << endl << "Дополнительная информация: " << endl;

		type = new string(type_value);
		cout << "Тип - " << *type << endl;

		amount = new int(amount_value);
		cout << "Количество - " << *amount << endl;
	}

	~Sausages()
	{
		delete type;
		delete amount;
	}
};

class Cookies : Products
{
	string* manufacturer;
	bool* contains_chocolate;

public:
	Cookies(float price_value, float mass_value, int product_type_value, string manufacturer_value, int contains_chocolate_value) : Products(price_value, mass_value, product_type_value)
	{
		cout << endl << "Дополнительная информация: " << endl;

		manufacturer = new string(manufacturer_value);
		cout << "Изготовитель - " << *manufacturer << endl;

		contains_chocolate = new bool(contains_chocolate_value);
		if (contains_chocolate)
		{
			cout << "Содержит шоколад" << endl;
		}
		else
		{
			cout << "Не содержит шоколад" << endl;
		}
	}

	~Cookies()
	{
		delete manufacturer;
		delete contains_chocolate;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	float price_value, mass_value, fat_value;
	int product_type_value, amount_value, contains_chocolate_value, i = 0;;
	string manufacturer_value, type_value, package_type_value;
	Milk* milk_obj = NULL;
	Sausages* sausages_obj = NULL;
	Cookies* cookies_obj = NULL;

	while (true)
	{
		cout << endl << "Введите цену: ";
		cin >> price_value;

		cout << "Введите массу: ";
		cin >> mass_value;

		cout << "Введите тип продукта: " << endl << "1. Молоко\n2. Сосиски\n3. Печенье\n";
		cin >> product_type_value;

		switch (product_type_value)
		{
		case 1:
			cout << "Введите тип упаковки: ";
			cin >> package_type_value;

			cout << "Введите жирность: ";
			cin >> fat_value;

			milk_obj = new Milk(price_value, mass_value, product_type_value, package_type_value, fat_value);

			break;
		case 2:
			cout << "Тип: ";
			cin >> type_value;

			cout << "Количество: ";
			cin >> amount_value;

			sausages_obj = new Sausages(price_value, mass_value, product_type_value, type_value, amount_value);

			break;
		case 3:
			cout << "Введите производителя: ";
			cin >> manufacturer_value;

			cout << "Содержит шоколад?\n1. Да\n2. Нет " << endl;
			cin >> i;
			if (i == 1)
			{
				contains_chocolate_value = true;
			}
			else
			{
				contains_chocolate_value = false;
			}

			cookies_obj = new Cookies(price_value, mass_value, product_type_value, manufacturer_value, contains_chocolate_value);

			break;
		default:
			if (milk_obj != NULL)
			{
				delete milk_obj;
			}
			if (sausages_obj != NULL)
			{
				delete sausages_obj;
			}
			if (cookies_obj != NULL)
			{
				delete cookies_obj;
			}
			exit(0);
			break;
		}
	}
}