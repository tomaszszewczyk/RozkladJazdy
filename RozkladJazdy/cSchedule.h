//Klasa przechowujaca plan wszystkich polaczen
#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include "cConnection.h"

using namespace std;

class cSchedule : public map<string, map<string, vector<cConnection> > >
{
private:
public:
	cSchedule() {}
	~cSchedule() {}
	//Dodawanie polaczenia wraz z sortowaniem
	void addConnection(cConnection polaczenie)
	{
		(*this)[polaczenie.getFrom()][polaczenie.getTo()].push_back(polaczenie);
		sort((*this)[polaczenie.getFrom()][polaczenie.getTo()].begin(),
				 (*this)[polaczenie.getFrom()][polaczenie.getTo()].end());
	}
};
