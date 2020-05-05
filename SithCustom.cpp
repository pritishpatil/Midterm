#include "SithCustom.h"
#include <sstream>

void SithCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

string SithCustom::toString() 
{
	stringstream resultStream;
	resultStream << firstname << "\t" << lastname << "\t" << gender << "\t" << id << "\t" << accountBalance << "\t" << apprentice << endl;
	return resultStream.str();
}

string SithCustom::getApprentice()
{
	return apprentice;
}

