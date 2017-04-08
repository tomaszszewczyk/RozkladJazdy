#pragma once
//Plan wszystkich polaczen
#include <vector>
#include <map>
#include "cConnection.h"

using namespace std;

class cSchedule
{
private:
	map<string, vector<cConnection> > miasta;
public:
	cSchedule();
	~cSchedule();
};

