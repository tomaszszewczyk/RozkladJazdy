#include "cLoader.h"

//Ladowanie danych z pliku
cSchedule cLoader::loadFromFile(string filename)
{
  //Zmienna na wynik
  cSchedule schedule;

  //Wczytywanie z pliku
  ifstream file;
  file.open(filename.c_str());
  if(file.is_open())
  {
    //Licznik ilosc polaczen
    int connectionQty = 0;
    //Iterowanie po liniach
    bool linesEnd = false;
    while(!linesEnd)
    {
      //Wczytanie nazwy linii
      string line;
      file >> line;

      //Warunek konca
      if(line == "end")
      {
        linesEnd = true;
        continue;
      }

      //Sprawdzenie poprawnosci skladni
      string input;
      file >> input;
      if(input != ".")
        throw(string("Blad skladni"));

      //Odczytywanie miast
      vector<string> cities;
      string data;
      while(data != ".")
      {
          file >> data;
          if(data != ".")
            cities.push_back(data);
      }

      //Odczytywanie czasu przejazdu
      vector<int> tripTimes;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          int tmp;
          sscanf(data.c_str(), "%d", &tmp);
          tripTimes.push_back(tmp);
        }
      }

      //Odczytywanie ceny przejazdu
      vector<int> prices;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          int tmp;
          sscanf(data.c_str(), "%d", &tmp);
          prices.push_back(tmp);
        }
      }

      //Odczytywanie godzin startu
      vector<cTime> departureTimes;
      data = "";
      while(data != ".")
      {
        file >> data;
        if(data != ".")
        {
          cTime tmp(data);
          departureTimes.push_back(tmp);
        }
      }

      //Dane wczytane mozna zaladowac do scheduleu
      //Do kazdego miasta dodajemy znalezione polacznia
      for(int i = 0; i < cities.size() -1; i++) //Dla kazdej pary miast
      {
        for(int x = 0; x < departureTimes.size(); x++)  //Dla kazdej godziny odjazdu
        {
          connectionQty++; //Zliczamy polaczenia
          schedule.addConnection(cConnection(line, cities[i], cities[i+1], prices[i], tripTimes[i], departureTimes[x]));
          departureTimes[x].delay(tripTimes[i]);
        }
      }
    }

    //Po wczytaniu
    cout << "Wczytano: " << connectionQty << " polaczen." << endl;
    cout << "Zakonczona prace loadera." << endl;
  }
  //Jesli nie udalo sie otworzyc pliku
  else
    throw(string("Niepowodzenie otwierania pliku"));

  return schedule;
}
