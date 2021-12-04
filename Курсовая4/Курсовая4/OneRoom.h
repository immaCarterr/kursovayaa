#pragma once
#include "Libraries.h"
#include "Flat.h"

class OneRoom : public Flat
{
public:
	static int counter;

	OneRoom();
	~OneRoom();

	static int GetCounter() { return counter; }

	void SetUnique(fstream& fs) override { }
	void PrintUnique(fstream& fs) override { }
	string GetUnique() override { return "1"; }
};

int OneRoom::counter = 0;

OneRoom::OneRoom() : Flat()
{
	counter++;
}

OneRoom::~OneRoom() {
	counter--;
}