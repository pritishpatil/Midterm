#include "JediCustom.h"

void JediCustom::setSaber(string newSaber )
{
	saber = newSaber;
}

string JediCustom::getSaber()
{
	return saber;
}

void JediCustom::printAccount()
{
	cout << firstname << " " << lastname << " " << gender << " " << id << " " << accountBalance << " " << saber << endl;
}