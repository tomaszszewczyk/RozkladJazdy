// RozkladJazdy.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <fstream>
#include "cLoader.h"
#include "debug.h"

using namespace std;

int main()
{
	try
	{
		cSchedule rozklad = cLoader::loadFromFile("rozklad.txt");
	}
	catch (string error)
	{
		cout << error << endl;
		cout << "Wystapil blad podczas wykonania programu" << endl;
	}
    return 0;
}
