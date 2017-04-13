#include "cSearcher.h"

//rekurencyjna wyszukiwarka polaczen
cTrip cSearcher::searcher(cSchedule schedule, cTime now, string from, string to, conClass type, vector<string> visited)
{
  //Dopisz obecne miasto do odwiedzonych
  visited.push_back(from);
  debugger("Miejsce: ", 1);

  //Znalezione opcje
  vector<cTrip> results;
  debugger("Miejsce: ", 2);

  //przeszukiwanie wszystkich bezposrednich polaczen
  for(cSchedule::mapped_type::iterator it = schedule[from].begin(); it != schedule[from].end(); ++it)
  {
    debugger("Miejsce: ", 3);
    //Dla kazdego dostepnego miasta docelowego
    vector<cConnection> directConnections = it->second;
    debugger("Miejsce: ", 4);
    for(int i = 0; i < directConnections.size(); i++)
    {
      //Jesli polaczenie jest bezposrednie
      debugger("Miejsce: ", 5);
      if(directConnections[i].getTo() == to)
      {
        cTrip tmp;
        tmp.add(directConnections[i]);
        results.push_back(tmp);
        debugger("Miejsce: ", 6);
      }
      //Jesli polaczenie nie jest bezposrednie
      else
      {
        //jesli nie odwiedzono jeszcze docelowego miasta
        debugger("Miejsce: ", 7);
        if(find(visited.begin(), visited.end(), directConnections[i].getTo()) == visited.end())
        {
          debugger("Miejsce: ", 8);
          cTrip tmp;
          tmp.add(directConnections[i]);
          tmp.add(searcher(schedule, now+directConnections[i].getTripTime(), directConnections[i].getTo(), to, type, visited));
          results.push_back(tmp);
          debugger("Miejsce: ", 9);
        }
        debugger("Miejsce: ", 10);
      }
      debugger("Miejsce: ", 11);
    }
    debugger("Miejsce: ", 12);
  }
  debugger("Miejsce: ", 13);
  //Szukanie najtanszego
  if(type == fast)
    sort(results.begin(), results.end(), cTrip::cheaper);
  else if(type == cheap)
    sort(results.begin(), results.end(), cTrip::quicker);
    debugger("Miejsce: ", 14);
  return results[0];
}
