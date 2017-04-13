//Klasa przechowujaca godzine i minute odjazdu

#pragma once
#include <string>
#include <cstdio>
#include <iostream>
#include "debug.h"
using namespace std;

class cTime
{
	unsigned hour;
	unsigned minute;
public:
	cTime(unsigned inhour = 0, unsigned inminute = 0){ setTo(inhour, inminute); }
	cTime(string input);
	void setTo(unsigned inhour, unsigned inminute);
	string toString();
	friend ostream& operator<<(ostream& out, cTime dana);
	void delay(int minuty);
	cTime operator+(int min);
	bool operator<(cTime input);
};
