#pragma once
#include <string>
#include <vector>
#include "cConnection.h"
#include "cSchedule.h"
#include "cTime.h"

using namespace std;

class cSearcher
{
public:
  enum conClass {fast, cheap};
  static vector<cConnection> searcher(cSchedule rozklad, string from, string to, conClass type);
};
