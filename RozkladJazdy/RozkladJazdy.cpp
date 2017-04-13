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
#include "cTrip.h"

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

	    string from, to, now;
	    cin >> from;
	    cout << "Do: ";
	    cin >> to;
			cout << "Od godziny: ";
			cin >> now;

			cTrip fastResult = cSearcher::searcher(schedule, cTime(now), from, to, cSearcher::fast);
			cTrip cheapResult = cSearcher::searcher(schedule, cTime(now), from, to, cSearcher::fast);

			cout << "Najszybsza trasa:" << endl << fastResult << endl;
			cout << "Najtansza trasa:" << endl << cheapResult << endl;
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
