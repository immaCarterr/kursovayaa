#pragma once
#include "Libraries.h"
#include "Flat.h"

class TwoRoom : public Flat
{
public:
	static int counter;

	TwoRoom();
	~TwoRoom();

	static int GetCounter() { return counter; }

	void SetUnique(fstream& fs) override { }
	void PrintUnique(fstream& fs) override { }
	string GetUnique() override { return "2"; }
};

int TwoRoom::counter = 0;

TwoRoom::TwoRoom() : Flat()
{
	counter++;
}

TwoRoom::~TwoRoom() {
	counter--;
}