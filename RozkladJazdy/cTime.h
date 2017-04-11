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
	cTime(unsigned inhour = 0, unsigned inminute = 0);
	cTime(string input);
	void setTo(unsigned inhour, unsigned inminute);
	string toString();
	friend ostream& operator<<(ostream& out, cTime dana);
};
