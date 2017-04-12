#pragma once
#include <string>
#include <iostream>
#include "cTime.h"

using namespace std;

//Klasa opisujaca jedno polaczenie
class cConnection
{
private:
	string lineName;
	string from;
	string to;
	int price;
	int tripTime;
	cTime time;

public:
	cConnection();
	cConnection(string aLineName,
							string aFrom,
							string aTo,
							int aPrice,
							int aTripTime,
							cTime aTime) :
															lineName(aLineName),
															from(aFrom),
															to(aTo),
															price(aPrice),
															tripTime(aTripTime),
															time(aTime) {}

	~cConnection();
  string getFrom() {return from;}
	string getTo() {return to;}
	friend ostream& operator<<(ostream& out, cConnection dana);
};
