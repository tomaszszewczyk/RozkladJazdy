#pragma once
#include <string>
#include "cTime.h"

using namespace std;

//Klasa opisujaca jedno polaczenie
class cConnection
{
private:
	string linia;
	string from;
	string to;
	int price;
	int triptime;
	cTime time;

public:
	cConnection();
	~cConnection();
  string getFrom() {return from;}
	string getTo() {return to;}
};
