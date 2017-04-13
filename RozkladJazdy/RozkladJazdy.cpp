// RozkladJazdy.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <fstream>
#include "cLoader.h"
#include "cConnection.h"
#include "cSchedule.h"
#include "cSearcher.h"
#include "cTime.h"
#include "debug.h"

using namespace std;

int main()
{
	try
	{
		cSchedule rozklad = cLoader::loadFromFile("rozklad.txt");

		while(1)
		{
	    cout << endl << "Wyszukaj polaczenia." << endl << "Z: ";

	    string from, to;

	    cin >> from;
	    cout << "Do: ";
	    cin >> to;

			cSearcher::searcher(rozklad, from, to, cSearcher::fast);
		}
	}
	catch (string error)
	{
		cout << error << endl;
		cout << "Wystapil blad podczas wykonania programu" << endl;
	}
    return 0;
}
