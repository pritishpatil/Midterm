#include "JediCustom.h"
#include <sstream>
#include <iomanip>

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
	stringstream balanceStream;
	string fullName = firstname + " " + lastname;
	balanceStream << "$" << setprecision(2) << fixed << accountBalance;
	string balanceStr = balanceStream.str();
	resultStream << left << setw(16) << fullName << left << setw(8) << gender << left << setw(8) << id << left << setw(16) 
		<< balanceStr << left << setw(15) << saber << endl;
	return resultStream.str();
}