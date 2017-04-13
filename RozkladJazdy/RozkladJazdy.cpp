// Program rozklad jazdy.
// Zaliczenie MiTP 2017, Tomasz Szewczyk

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
	//Glowny blok programu
	try
	{
		//Wczytywanie danych z pliku
		cSchedule schedule = cLoader::loadFromFile("rozklad.txt");

		//Petla glowna
		while(1)
		{
			//Wczytywanie danych do wyszukiwania
	    cout << endl << "Wyszukaj polaczenia." << endl << "Z: ";

	    string from, to;
	    cin >> from;
	    cout << "Do: ";
	    cin >> to;

			cSearcher::searcher(schedule, from, to, cSearcher::fast);
		}
	}
	//Bezpieczne zakoczenie programu + wypisanie bledow
	catch (string error)
	{
		cout << error << endl;
		cout << "Wystapil blad podczas wykonania programu" << endl;
	}
    return 0;
}
