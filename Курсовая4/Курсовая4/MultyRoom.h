#pragma once
#include "Libraries.h"
#include "Flat.h"
#include "Functions.h"

class MultyRoom : public Flat
{
private:
	string roomsNum;
public:
	static int counter;

	MultyRoom();
	~MultyRoom();

	static int GetCounter() { return counter; }

	void SetInformation() override {
		Flat::SetInformation();
		cout << "\nВведите количество комнат: "; cin >> roomsNum;
	}

	void SetUnique(fstream& fs) override { fs >> roomsNum; }
	void PrintUnique(fstream& fs) override { fs << " " << roomsNum; }
	string GetUnique() override { return roomsNum; }
};

int MultyRoom::counter = 0;

MultyRoom::MultyRoom() : Flat()
{
	counter++;
	roomsNum = "0";
}

MultyRoom::~MultyRoom() {
	counter--;
}