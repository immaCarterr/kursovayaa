#pragma once
#include "Libraries.h"
#include "Subclasses.h"
#include "Functions.h"

int INTS(int& num);
int INTS(float& num);

class Flat {
protected:
	int buildYear;
	int floor;
	float price;
	Adress adress;
	int balconyNum;
	float area;
	float ceilingHigh;
public:
	Flat();

	int GetBuildYear() { return buildYear; }
	int GetFloor() { return floor; }
	float GetPrice() { return price; }
	Adress GetAdress() { return adress; }
	int GetBalconyNum() { return balconyNum; }
	float GetArea() { return area; }
	float GetCeilingHigh() { return ceilingHigh; }

	virtual void SetInformation();
	virtual void SetUnique(fstream& fs) = 0;
	virtual void PrintUnique(fstream& fs) = 0;
	virtual string GetUnique() = 0;

	friend fstream& operator>>(fstream& fs, Flat& obj);
	friend fstream& operator<<(fstream& fs, Flat& obj);
};

Flat::Flat() {
	buildYear = 0;
	floor = 0;
	price = 0;
	balconyNum = 0;
	area = 0;
	ceilingHigh = 0;
}

void Flat::SetInformation() {
	cout << "������� ��� ��������� ����: "; INTS(buildYear);
	cout << "\n������� ����: "; INTS(floor);
	cout << "\n������� ����� ���� ��������(� $): "; INTS(price);
	cout << "\n������� �����:\n\n"; adress.SetInformation();
	cout << "\n������� ���������� ��������(0 - ���� �� ���): "; INTS(balconyNum);
	cout << "\n������� ����� ������� ��������(� �2): "; INTS(area);
	cout << "\n������� ������ ��������(� �.): "; INTS(ceilingHigh);
}