#include "CommonCustom.h"

void CommonCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

void CommonCustom::setSaber(string newSaber)
{
	saber = newSaber;
}

void CommonCustom::printAccount()
{
	cout << firstname << lastname << id << gender << saber << apprentice << endl;
}

string CommonCustom::getSaber()
{
	return saber;
}

string CommonCustom::getApprentice()
{
	return apprentice;
}