#include "cConnection.h"


cConnection::cConnection()
{
}


cConnection::~cConnection()
{
}

ostream& operator<<(ostream& out, cConnection dana)
{
  cout << dana.from << " - " << dana.to << " - " << dana.time;
  return out;
}
