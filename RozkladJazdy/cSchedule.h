#pragma once
//Plan wszystkich polaczen
#include <vector>
#include <map>
#include "cConnection.h"

using namespace std;

class cSchedule : public map<string, map<string, vector<cConnection> > >
{
private:
public:
	cSchedule();
	~cSchedule();
	void addConnection(cConnection polaczenie)
	{
		(*this)[polaczenie.getFrom()][polaczenie.getTo()].push_back(polaczenie);
	}
};
