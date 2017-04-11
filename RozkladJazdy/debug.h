#pragma once
#include <string>
#include <iostream>

using namespace std;

template<class TYP>
void debugger(string comment, TYP dana)
{
  cout << "\tDebug   " << comment << " = " << dana << endl;
}
