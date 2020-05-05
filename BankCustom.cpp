/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/

#include "BankCustom.h"

void BankCustom::setID(string newID)
{
	id = newID;
}

void BankCustom::setLname(string newLastname)
{
	lastname = newLastname;
}

void BankCustom::setFname(string newFirstname)
{
	firstname = newFirstname;
}

void BankCustom::setGender(string newGender)
{
	gender = newGender;
}

void BankCustom::setBalance(double newBalance)
{
	accountBalance = newBalance;
}

string BankCustom::getid()
{
	return id;
}

string BankCustom::getFname()
{
	return firstname;
}

string BankCustom::getLname()
{
	return lastname;
}

string BankCustom::getGender()
{
	return gender;
}

double BankCustom::getBalance()
{
	return accountBalance;
}

