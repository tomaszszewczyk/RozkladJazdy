// RozkladJazdy.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	try
	{
		//Wczytywanie danych z pliku
		ifstream file;
		file.open("rozklad.txt");
		if(file.is_open())
		{
			//Iterowanie po liniach
			bool koniec_linii = false;
			while(!koniec_linii)
			{
				//Wczytanie nazwy linii
				string linia;
				file >> linia;
				cout << "Linia: " << linia << endl;

				//Sprawdzenie poprawnosci skladni
				string input;
				file >> input;
				if(input != ".")
					throw(string("Blad skladni"));

				//Odczytywanie trasy
				string from, to;
				int triptime, price;
				bool koniec_miast = false;
				file >> to;
				while(!koniec_miast)
				{
					from = to;
					file >> triptime >> price >> to;
				}

			}
		}
		else
			throw(string("Niepowodzenie otwierania pliku"));
	}
	catch (string error)
	{
		cout << error << endl;
		cout << "Wystapil blad podczas wykonania programu" << endl;
	}
    return 0;
}
