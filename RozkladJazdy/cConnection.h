//Klasa opisujaca jedno polacznie
// Zaliczenie MiTP 2017, Tomasz Szewczyk

#pragma once
#include <string>
#include <iostream>
#include "cTime.h"

using namespace std;

//Klasa cConnecion
class cConnection
{
private:
	string lineName;	//Nazwa linii
	string from;			//Miasto wyjazdu
	string to;				//Miato docelowe
	int price;				//Cena
	int tripTime;			//Czas podrozy
	cTime time;				//Godzina wyjazdu

public:
	//Kontruktory
	cConnection() {}
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

	~cConnection() {}

	//Podstawowe gettery
  string getFrom() {return from;}
	string getTo() {return to;}

	//wypisywanie polaczenia
	friend ostream& operator<<(ostream& out, cConnection dana)
	{
	  cout << dana.from << " (" << dana.time << ") -> " << dana.to << " (" << dana.time+dana.tripTime << ")";
	  return out;
	}
	bool operator<(cConnection input) { return time < input.time; }
};
