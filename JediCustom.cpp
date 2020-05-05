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
	cout << firstname << "\t" << lastname << "\t" << gender << "\t" << id << "\t" << accountBalance << "\t" << saber << endl;
}