#include "cTime.h"

//Zamiana stringa na cTime
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

//Ustawianie cTime
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
			throw(error);	//Wyjatek jesli poza zakresem
		}
}

//Wypisanie cTime
string cTime::toString()
{
	char wynik[6];
	sprintf(wynik, "%02d:%02d", hour, minute);
	return string(wynik);
}

//Operator wypisania cTime
ostream& operator<<(ostream& out, cTime dana)
{
	out<<dana.toString();
	return out;
}

//Dodanie czasu
void cTime::delay(int min)
{
	minute += min%60;
	if(minute >= 60)
	{
		minute = 0;
		hour++;
	}
	hour += min/60;
	if(hour >= 24)
		hour = 0;
}

//Operator dodawnia
cTime cTime::operator+(int min)
{
	cTime tmp = (*this);
	tmp.delay(min);
	return tmp;
}

//Operator porownania potrzebny do sortowania
bool cTime::operator<(cTime dana)
{
	if(dana.hour <= hour)
		return false;
	if(dana.hour == hour && dana.minute <= minute)
		return false;
	return true;
}
