#include "CommonCustom.h"
#include <sstream>
#include <iomanip>

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
	stringstream balanceStream;
	string fullName = firstname + " " + lastname;
	balanceStream << "$" << setprecision(2) << fixed << accountBalance;
	string balanceStr = balanceStream.str();
	resultStream << left << setw(16) << fullName << left << setw(8) << gender << left << setw(8) << id << left << setw(16) 
		<< balanceStr << left << setw(15) << saber << left << setw(10) << apprentice << endl;
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