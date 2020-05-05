#include "SithCustom.h"

void SithCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

void SithCustom::printAccount() 
{
	cout << firstname << lastname << id << gender << accountBalance << apprentice << endl;
}

string SithCustom::getApprentice()
{
	return apprentice;
}

