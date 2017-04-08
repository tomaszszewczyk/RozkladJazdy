#include "cTime.h"

cTime::cTime(unsigned inhour, unsigned inminute)
{
	if (inhour < 24 && inminute < 60)
	{
		hour = inhour;
		minute = inminute;
	}
	else
	{
		string error;
		error += "cTime input data error. File: ";
		error += __FILE__;
		error += " Line:";
		error += __LINE__;
		throw(error);
	}
}
