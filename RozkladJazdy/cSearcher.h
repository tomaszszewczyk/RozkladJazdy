#pragma once
#include <string>
#include "cConnection.h"
#include "cSchedule.h"
#include "cTime.h"

using namespace std;

class cSearcher
{
public:
  enum conClass {fast, cheap};
  static cConnection searcher(string from, string to, conClass type);
};
