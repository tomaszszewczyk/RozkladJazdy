#include "cSearcher.h"

static cConnection cSearcher::searcher(cSchedule rozklad, string from, string to, conClass type)
{
  for(int i = 0; i < rozklad[from][to].size(); i++)
    cout << rozklad[from][to][i] << endl;
  return cConnection();
}
