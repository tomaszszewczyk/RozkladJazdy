#include "cLoader.h"

cSchedule cLoader::loadFromFile(string filename)
{
  cSchedule rozklad;

  ifstream file;
  file.open(filename.c_str());
  //Wczytywanie z pliku
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

      //Warunek koncza
      if(linia == "end")
      {
        koniec_linii = true;
        continue;
      }

      //Sprawdzenie poprawnosci skladni
      string input;
      file >> input;
      if(input != ".")
        throw(string("Blad skladni"));

      //Odczytywanie miast
      vector<string> miasta;
      string data;
      while(data != ".")
      {
          file >> data;
          if(data != ".")
            miasta.push_back(data);
      }

      //Odczytywanie czasu przejazdu
      vector<int> czasy;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          int tmp;
          sscanf(data.c_str(), "%d", &tmp);
          czasy.push_back(tmp);
          cout << "czas: " << tmp << endl;
        }
      }

      //Odczytywanie ceny przejazdu
      vector<int> ceny;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          int tmp;
          sscanf(data.c_str(), "%d", &tmp);
          ceny.push_back(tmp);
          cout << "ceny: " << tmp << endl;
        }
      }

      //Odczytywanie godzin startu
      vector<cTime> starty;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          cTime tmp(data);
          starty.push_back(tmp);
          cout << "starty: " << tmp << endl;
        }
      }

      //Dane wczytane mozna zaladowac do rozkladu
      //Do kazdego miasta dodajemy znalezione polacznia
      for(int i = 0; i < miasta.size() -1; i++) //Dla kazdej pary miast
      {
        for(int x = 0; x < starty.size(); x++)  //Dla kazdej godziny odjazdu
        {
          rozklad.addConnection(cConnection(linia, miasta[i], miasta[i+1], ceny[i], czasy[i], starty[x]));
          starty[x].delay(czasy[i]);
        }
      }
    }

    //Po wczytaniu
    cout << endl << "Wczytywanie rozkladu zakonczone powodzeniem!" << endl;
    cout << endl << "Wyszukaj polaczenie." << endl << "Z: ";

    string skad, dokad;

    cin >> skad;
    cout << "Do: ";
    cin >> dokad;

    for(int i = 0; i < rozklad[skad][dokad].size(); i++)
      cout << rozklad[skad][dokad][i] << endl;
  }
  //Jesli nie udalo sie otworzyc pliku
  else
    throw(string("Niepowodzenie otwierania pliku"));

  return rozklad;
}
