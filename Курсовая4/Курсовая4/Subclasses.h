#pragma once
#include "Libraries.h"

using namespace std;

class Adress
{
	string city;
	string street;
	string houseNum;
	string flatNum;
public:
	Adress();
	string GetCity() { return city; }
	string GetStreet() { return street; }
	string GetHouseNum() { return houseNum; }
	string GetFlatNum() { return flatNum; }

	void SetInformation();
	friend fstream& operator>>(fstream& fs, Adress& obj);
	friend bool operator==(Adress obj1, Adress obj2);

	Adress& operator=(Adress obj) {
		this->city = obj.city;
		this->street = obj.street;
		this->houseNum = obj.houseNum;
		this->flatNum = obj.flatNum;
		return *this;
	}
};

Adress::Adress()
{
	city = "-";
	street = "-";
	houseNum = "-";
	flatNum = "-";
}

void Adress::SetInformation() {
	cout << "¬ведите город: "; cin >> city;
	cout << "\n¬ведите улицу: "; cin >> street;
	cout << "\n¬ведите номер дома: "; cin >> houseNum;
	cout << "\n¬ведите номер квартиры: "; cin >> flatNum;
}

class Fio {
	string name;
	string surname;
	string patronymic;
public:
	Fio();
	void Set();
	string GetName() { return name; }
	string GetSurname() { return surname; }
	string GetPatronymic() { return patronymic; }

	friend fstream& operator>>(fstream& fs, Fio& obj);
	friend bool operator==(Fio obj1, Fio obj2);
};

Fio::Fio() {
	name = "-";
	surname = "-";
	patronymic = "-";
}

void Fio::Set() {
	cout << "¬ведите им€: "; cin >> name;
	cout << "\n¬ведите фамилию: "; cin >> surname;
	cout << "\n¬ведите отчество: "; cin >> patronymic;
}