#include "cTime.h"

cTime::cTime(unsigned inhour, unsigned inminute)
{
	setTo(inhour, inminute);
}

cTime::cTime(string input)
{
	string hh = input.substr(0,2);
	string mm = input.substr(2,2);

	hh += '\0';
	mm += '\0';

	int inhour, inminute;
	sscanf(hh.c_str(), "%d", &inhour);
	sscanf(mm.c_str(), "%d", &inminute);

	setTo(inhour, inminute);
}


void cTime::setTo(unsigned inhour, unsigned inminute)
{
		if (inhour < 24 && inminute < 60)
		{
			hour = inhour;
			minute = inminute;
		}
		else
		{
			string error;
			error += "cTime input data error. Hour: ";
			error += hour;
			error += " Minute:";
			error += minute;
			throw(error);
		}
}

string cTime::toString()
{
	char wynik[6];
	sprintf(wynik, "%02d:%02d", hour, minute);
	return string(wynik);
}

ostream& operator<<(ostream& out, cTime dana)
{
	out<<dana.toString();
	return out;
}

void cTime::delay(int minuty)
{
	minute += minuty%60;
	if(minute >= 60)
	{
		minute = 0;
		hour++;
	}
	hour += minuty/60;
	if(hour >= 24)
		hour = 0;
}
