#include <iostream>
#include <string>

using namespace std;


class Product
{
protected:
	string name;
	string brand;
	float price;

public:
	Product(string name = "", string brand = "", float price = 0.0)
	{
		cout << "Constructor Product..." << endl;

		this->name = name;
		this->brand = brand;
		this->price = price;
	}

	~Product()
	{
		cout << "Destructor Product" << endl;		
	}

	void print_name();
	void print_info();	
};

void Product::print_name() 
{
	cout << "Product" << endl;
}

void Product::print_info()
{
	cout << "Name is " << name << endl;
	cout << "Brand is " << brand << endl;
	cout << "Price is " << price << endl;
}

class Transport : public virtual Product
{
	int speed;
	int capacity_of_people;

public:
	Transport(string name = "", string brand = "", float price = 0.0, int speed = 0, int capacity_of_people = 0.0) : Product(name, brand, price) {
		
		cout << "Constructor Transport..." << endl;

		this->speed = speed;
		this->capacity_of_people = capacity_of_people;
	}

	~Transport()
	{
		cout << "Destructor Transport" << endl;
	}

	void print_name();
	void print_info();
	void change_speed(float new_speed);
};

void Transport::change_speed(float new_speed) 
{
	speed = new_speed;
}

void Transport::print_name()
{
	cout << "Transport" << endl;
}

void Transport::print_info()
{
	Product::print_info();
	cout << "Speed is " << speed << endl;
	cout << "Capacity of people of transport is " << capacity_of_people << endl;
}

class Electronics : public virtual Product
{
protected:
	float battery_capacity;
	float amount_of_memory;

public:
	Electronics(string name = "", string brand = "", float price = 0.0, float battery_capacity = 0.0, float amount_of_memory = 0.0) : Product(name, brand, price) {

		cout << "Constructor Electronics..." << endl;

		this->battery_capacity = battery_capacity;
		this->amount_of_memory = amount_of_memory;
	}

	~Electronics()
	{
		cout << "Destructor Electronics" << endl;
	}

	void print_name();
	void print_info();
	void change_battery(float new_battery);
};

void Electronics::change_battery(float new_battery)
{
	battery_capacity = new_battery;
}

void Electronics::print_name()
{
	cout << "Electronics" << endl;
}

void Electronics::print_info()
{
	Product::print_info();
	cout << "Battery capacity is " << battery_capacity << endl;
	cout << "Amount of memory is " << amount_of_memory << endl;
}

class Electrocar : public Transport, public Electronics
{
protected:
	string software_version;
	string body_type;

public:
	Electrocar(string name = "", string brand = "", float price = 0.0, int speed = 0, int capacity_of_people = 0.0, float battery_capacity = 0.0, float amount_of_memory = 0.0, string software_version = "", string body_type = "")
		:		
		Transport(name, brand, price, speed, capacity_of_people),
		Electronics(name, brand, price, battery_capacity, amount_of_memory),
		Product(name,brand,price)
		{

		cout << "Constructor Electrocar..." << endl;

		this->software_version = software_version;
		this->body_type = body_type;
	}

	~Electrocar()
	{
		cout << "Destructor Electrocar" << endl;
	}

	void print_info();
	void change_body(string new_body);
};

void Electrocar::change_body(string new_body) {
	body_type = new_body;
}

void Electrocar::print_info()
{	
	Transport::print_info();
	cout << "Battery capacity is " << battery_capacity << endl;
	cout << "Amount of memory is " << amount_of_memory << endl;
	cout << "Software version is " << software_version << endl;
	cout << "Body type is " << body_type << endl;
}

void readNumber(float &num) 
{
	while (!(cin >> num))
	{
		cout << "Invalid input !!!Repeat ...\n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}


void readNumber(int &num)
{
	while (!(cin >> num))
	{
		cout << "Invalid input !!!Repeat...\n";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}


int main()
{
	/*Electrocar el("Model3", "Tesla", 181700, 225, 4, 6, 23, "rtrre", "sedan");
	Electrocar *car = &el;

	car->Transport::print_name();
	car-> Transport::print_info();
	car->change_speed(106);
	car->Transport::print_info();

	car->Electronics::print_name();
	car->Electronics::print_info();
	car->change_battery(188);
	car->Electronics::print_info();

	car->print_info();
	car->change_body("eeee");
	car->print_info();
	car->Product::print_name();*/
	
	string name, brand, software_version, body_type;
	float price,  battery_capacity, amount_of_memory;
	int speed, capacity_of_people;

	cout << "Enter product name: ";
	cin >> name;
	cout << "Enter product brand: ";
	cin >> brand;
	cout << "Enter product price: ";
	readNumber(price);	
	cout << "Enter speed: ";
	readNumber(speed);
	cout << "Enter capacity of people: ";
	readNumber(capacity_of_people);


	Transport tr(name, brand, price, speed, capacity_of_people);
	tr.print_name();
	tr.print_info();

	cout << "Enter new speed: ";
	readNumber(speed);

	tr.change_speed(speed);
	tr.print_info();

	cout << "Enter battery capacity: ";
	readNumber(battery_capacity);
	cout << "Enter amount of memory: ";
	readNumber(amount_of_memory);

	Electronics el(name, brand, price, battery_capacity, amount_of_memory);
	el.print_name();
	el.print_info();

	cout << "Enter new battery capacity: ";
	readNumber(battery_capacity);

	el.change_battery(battery_capacity);
	el.print_info();

	cout << "Enter Software version: ";
	cin >> software_version;
	cout << "Enter body type: ";
	cin >> body_type;

	Electrocar elcar(name, brand, price, speed, capacity_of_people, battery_capacity, amount_of_memory, software_version, body_type);

	elcar.print_info();

	cout << "Enter new body type: ";
	cin >> body_type;

	elcar.change_body(body_type);
	elcar.print_info();

	elcar.Electronics::print_name();
	elcar.Transport::print_name();
	elcar.Product::print_name();
}

