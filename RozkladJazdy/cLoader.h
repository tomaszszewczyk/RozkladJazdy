//Klasa statyczna realizujaca ladowanie danych z pliku
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cSchedule.h"
#include "debug.h"

using namespace std;

class cLoader
{
public:
  static cSchedule loadFromFile(string filename);
};
