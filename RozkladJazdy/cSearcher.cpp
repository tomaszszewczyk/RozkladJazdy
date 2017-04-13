#include "cSearcher.h"

//Wyszukiwarka polaczen
vector<cConnection> cSearcher::searcher(cSchedule rozklad, string from, string to, conClass type)
{
  vector<cConnection> results;
  for(int i = 0; i < rozklad[from][to].size(); i++)
    cout << rozklad[from][to][i] << endl;
  return results;
}
