#include "cSearcher.h"

//rekurencyjna wyszukiwarka polaczen
cTrip cSearcher::searcher(cSchedule schedule, cTime now, string from, string to, conClass type, vector<string> visited)
{
  vector<cConnection> directConnections = schedule.getConnectionsFrom(from);

  vector<cTrip> results;
  for(int i = 0; i < directConnections.size(); i++)
  {
    if(find(visited.begin(), visited.end(), directConnections[i].getTo()) == visited.end())
      if(now < directConnections[i].getStart())
      {
        debugger("To: ", directConnections[i].getTo());
        if(directConnections[i].getTo() == to)
          results.push_back(cTrip(directConnections[i]));
        else
        {
          int actualTripTime = directConnections[i].getTripTime();
          string nextCity = directConnections[i].getTo();
          vector<string> newVisited = visited;
          newVisited.push_back(from);
          try
          {
            cTrip further;
            further.add(directConnections[i]);
            further.add(searcher(schedule, now + actualTripTime, nextCity, to, type, newVisited));
            results.push_back(further);
          }
          catch(string exp) { /*Normalne*/ }
        }
      }
  }

  //Szukanie najtanszego
  if(type == fast)
    sort(results.begin(), results.end(), cTrip::cheaper);
  else if(type == cheap)
    sort(results.begin(), results.end(), cTrip::quicker);

  if(results.size() == 0)
    throw(string("Nic nie znaleziono"));
  else
    return results[0];
}
