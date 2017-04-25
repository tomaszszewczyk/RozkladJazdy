//Klasa opisujaca wektor polaczen

#pragma once
#include <vector>
#include <iostream>
#include "cConnection.h"

class cTrip : public vector<cConnection>
{
private:
  int tripTime;
  int price;
public:
  cTrip() : tripTime(0), price(0) {}
  cTrip(cConnection aConnection) : tripTime(0), price(0)
  {
    add(aConnection);
  }
  void add(cConnection aConnection)
  {
    (*this).push_back(aConnection);
    tripTime += aConnection.getTripTime();
    price += aConnection.getPrice();
  }
  void add(cTrip aTrip)
  {
    if(aTrip.size() == 0)
      return; //ignore

    (*this).insert((*this).end(), aTrip.begin(), aTrip.end());
    tripTime += aTrip.tripTime;
    price += aTrip.price;
  }
  static bool cheaper(cTrip a, cTrip b) { return a.price < b.price; }
  static bool quicker(cTrip a, cTrip b) { return a.tripTime < b.tripTime; }
  friend ostream& operator<<(ostream& out, cTrip data)
  {
    out << "Czas: " << data.tripTime << endl;
    out << "Cena: " << data.price << endl;
    out << "Trasa: " << data[0].getFrom();
    for(int i = 0; i < data.size(); i++)
      cout << " [" << data[i].getStart() << "] -> [" << data[i].getStart() + data[i].getTripTime() << "] " << data[i].getTo();
    return out;
  }
};
