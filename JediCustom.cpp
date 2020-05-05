#include "JediCustom.h"
#include <sstream>

void JediCustom::setSaber(string newSaber )
{
	saber = newSaber;
}

string JediCustom::getSaber()
{
	return saber;
}

string JediCustom::toString()
{
	stringstream resultStream;
	resultStream << firstname << "\t" << lastname << "\t" << gender << "\t" << id << "\t" << accountBalance << "\t" << saber << endl;
	return resultStream.str();
}