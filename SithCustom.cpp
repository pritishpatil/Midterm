#include "SithCustom.h"

void SithCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

void SithCustom::printAccount() 
{
	cout << firstname << "\t" << lastname << "\t" << gender << "\t" << id << "\t" << accountBalance << "\t" << apprentice << endl;
}

string SithCustom::getApprentice()
{
	return apprentice;
}

