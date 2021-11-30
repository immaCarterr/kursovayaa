#pragma once
#include "Libraries.h"
#include "Flat.h"

class ThreeRoom : public Flat
{
public:
	static int counter;

	ThreeRoom();
	~ThreeRoom();

	static int GetCounter() { return counter; }

	void SetUnique(fstream& fs) override { }
	void PrintUnique(fstream& fs) override { }
	string GetUnique() override { return "3"; }
};

int ThreeRoom::counter = 0;

ThreeRoom::ThreeRoom() : Flat()
{
	counter++;
}

ThreeRoom::~ThreeRoom() {
	counter--;
}