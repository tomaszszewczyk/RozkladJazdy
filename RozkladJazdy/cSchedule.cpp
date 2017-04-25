#include "cSchedule.h"

vector<cConnection> cSchedule::getConnectionsFrom(string from)
{
  vector<cConnection> directConnections;
  for(map<string, vector<cConnection> >::iterator it = (*this)[from].begin(); it != (*this)[from].end(); ++it)
  {
    vector<cConnection> thisDestinationConnections = it->second;
    for(int i = 0; i < thisDestinationConnections.size(); i++)
    {
      directConnections.push_back(thisDestinationConnections[i]);
    }
  }
  return directConnections;
}
