/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/

#include "SithCustom.h"
#include <sstream>
#include <iomanip>

void SithCustom::setApprentice(string newApprentice)
{
	apprentice = newApprentice;
}

// returns final string ouput for SithCustom derived class
string SithCustom::toString() 
{
	stringstream resultStream;
	stringstream balanceStream;
	string fullName = firstname + " " + lastname;
	balanceStream << "$" << setprecision(2) << fixed << accountBalance;
	string balanceStr = balanceStream.str();
	resultStream << left << setw(16) << fullName << left << setw(8) << gender << left << setw(8) << id << left << setw(16) 
		<< balanceStr << left << setw(15) << "" << left << setw(10) << apprentice << endl;
	return resultStream.str();
}

string SithCustom::getApprentice()
{
	return apprentice;
}

