#include "cConnection.h"


cConnection::cConnection()
{
}


cConnection::~cConnection()
{
}

ostream& operator<<(ostream& out, cConnection dana)
{
  cout << dana.from << " (" << dana.time << ") -> " << dana.to << " (" << dana.time+dana.tripTime << ")";
  return out;
}
