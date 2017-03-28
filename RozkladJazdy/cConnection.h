#pragma once
#include <string>
#include "cTime.h"

using namespace std;

//Klasa opisujaca jedno polaczenie
class cConnection
{
private:
	string from;
	string to;
	int price;
	int triptime;
	cTime time;

public:
	cConnection();
	~cConnection();
};

