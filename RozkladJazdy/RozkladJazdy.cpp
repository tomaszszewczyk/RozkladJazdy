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
			bool conti = true;
			while(conti)
			{
				string input;
				file >> input;
				cout << "Linia: " << input << endl;

				file >> input;
				if(input != ".")
					throw(string("Blad skladni"));

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
