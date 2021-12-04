#pragma once
#include "Libraries.h"
#include "Subclasses.h"

using namespace std;

class Buyer
{
	Fio fio;
	string number;
	Adress adress;
public:
	Buyer();

	Fio GetFio() { return fio; }
	string GetNumber() { return number; }
	Adress GetAdress() { return adress; }

	void SetInformation();

	friend fstream& operator>>(fstream& fs, Buyer& obj);
	friend fstream& operator<<(fstream& fs, Buyer& obj);
	friend void BuyFlat();
	friend void AddBuyer(Buyer* obj);
};

Buyer::Buyer()
{
	number = "-";
}

void Buyer::SetInformation() {
	cout << "������� ���:" << endl; fio.Set();
	cout << "\n������� ����� ��������: "; cin >> number;
}