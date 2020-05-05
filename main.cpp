

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BankCustom.h"
#include "JediCustom.h"
#include "SithCustom.h"
#include "CommonCustom.h"

using namespace std;

const int MAX = 100;

int main()
{
	BankCustom* mergedMembers[MAX];
	int count;
	string line;
	ifstream jediBank;

	count = 0;
	string ID; string fname; string lname; string saber; string gender; string apprentice; string balance;

	//populate jedi members 
	jediBank.open("BankOfJedi.txt", ios::in);
	if (jediBank.fail()) 
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	getline(jediBank, line);
	while (true)
	{
		getline(jediBank, line);
		if (line == "")
		{
			break;
		}
		else 
		{
			// get tokens
			istringstream instr(line);
			instr >> fname >> lname >> gender >> ID >> balance >> saber;
			
			// convert balance to double 
			balance = balance.substr(1,balance.length() - 1);
			double numericBalance;

			stringstream converter;
			converter << balance;
			converter >> numericBalance;

			//create bank account
			JediCustom* customer = new JediCustom();
			customer->setFname(fname);
			customer->setLname(lname);
			customer->setGender(gender);
			customer->setID(ID);
			customer->setBalance(numericBalance);
			customer->setSaber(saber);
			mergedMembers[count++] = customer;

		}
	}
	jediBank.close();



	// Read in sith bank
	ifstream sithBank;
	sithBank.open("BankOfSith.txt", ios::in);
	if (sithBank.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	getline(sithBank, line);
	while (true)
	{
		getline(sithBank, line);
		if (line == "")
		{
			break;
		}
		else
		{
			// get tokens
			istringstream instr(line);
			instr >> fname >> lname >> gender >> ID >> balance >> apprentice;

			// convert balance to double 
			balance = balance.substr(1, balance.length() - 1);
			double numericBalance;

			stringstream converter;
			converter << balance;
			converter >> numericBalance;

			//create bank account
			SithCustom* customer = new SithCustom();
			customer->setFname(fname);
			customer->setLname(lname);
			customer->setGender(gender);
			customer->setID(ID);
			customer->setBalance(numericBalance);
			customer->setApprentice(apprentice);
			mergedMembers[count++] = customer;

		}
	}
	sithBank.close();

	cout << "Custom_Name	Gender	ID#	Account_Balance	Apprentice" << endl;
	for (int i = 0; i < count; i++)
	{
		mergedMembers[i]->printAccount();
	}
	return 0;
}