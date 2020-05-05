#include "CommonCustom.h"
#include <sstream>

void CommonCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

void CommonCustom::setSaber(string newSaber)
{
	saber = newSaber;
}

string CommonCustom::toString()
{
	stringstream resultStream;
	resultStream << firstname << "\t" << lastname << "\t" << gender << "\t" << id << "\t" << accountBalance << "\t" << saber << "\t" << apprentice << endl;
	return resultStream.str();
}

string CommonCustom::getSaber()
{
	return saber;
}

string CommonCustom::getApprentice()
{
	return apprentice;
}