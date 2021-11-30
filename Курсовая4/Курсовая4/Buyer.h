#pragma once
#include "Libraries.h"
#include "Subclasses.h"

using namespace std;

class Buyer
{
	Fio fio;
	int age;
	Adress adress;
public:
	Buyer();

	Fio GetFio() { return fio; }
	int GetAge() { return age; }
	Adress GetAdress() { return adress; }

	void SetInformation();

	friend fstream& operator>>(fstream& fs, Buyer& obj);
	friend fstream& operator<<(fstream& fs, Buyer& obj);
	friend void BuyFlat();
	friend void AddBuyer(Buyer* obj);
};

Buyer::Buyer()
{
	age = 0;
}

void Buyer::SetInformation() {
	cout << "Введите ФИО:" << endl; fio.Set();
	cout << "\nВведите возраст: "; cin >> age;
}