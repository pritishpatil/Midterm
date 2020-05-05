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
	cout << firstname << lastname << id << gender << saber << endl;
}