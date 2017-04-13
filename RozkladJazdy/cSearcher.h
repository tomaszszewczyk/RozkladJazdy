#pragma once
#include <string>
#include <vector>
#include "cConnection.h"
#include "cSchedule.h"
#include "cTime.h"
#include "cTrip.h"
#include "cConnection.h"
#include "debug.h"

using namespace std;

class cSearcher
{
public:
  enum conClass {fast, cheap, any};
  static cTrip searcher(cSchedule schedule, cTime now, string from, string to, conClass type, vector<string> visited = vector<string>());
};
