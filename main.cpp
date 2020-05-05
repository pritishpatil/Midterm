
/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "BankCustom.h"
#include "JediCustom.h"
#include "SithCustom.h"
#include "CommonCustom.h"

using namespace std;

const int ARRAYSIZE = 1000; // should suffice for reasonable user base (same format in txt file) as requested in spec

int main()
{
	BankCustom* mergedMembers[ARRAYSIZE];	// base class array can hold derived objects for polymorphism
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

	cout << "Reading BankOfJedi.txt..." << endl;
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
			// get token
			istringstream instr(line);
			instr >> fname >> lname >> gender >> ID >> balance >> saber;
			
			for_each(ID.begin(), ID.end(), [](char& c) // makes ID lowercase
			{
				c = ::tolower(c);
			});

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
	int jediCount = count;
	cout << "Done" << endl;
	cout << endl;


	// Read in sith bank
	ifstream sithBank;
	sithBank.open("BankOfSith.txt", ios::in);
	if (sithBank.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	cout << "Reading BankOfSith.txt..." << endl;
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
			
			for_each(ID.begin(), ID.end(), [](char& c)	// makes id lowercase
			{
				c = ::tolower(c);
			});
			

			// Checks for duplicates
			bool isDuplicate = false;
			int dupIndex = -1;
			for (int i = 0; i < jediCount; i++)
			{
				BankCustom* customerToCheck = mergedMembers[i];
				string jedi = customerToCheck->getid();
				if (_stricmp(jedi.c_str(), ID.c_str()) == 0)
				{
					isDuplicate = true;
					dupIndex = i;
				}
			}

			// convert balance to double 
			balance = balance.substr(1, balance.length() - 1);
			double numericBalance;

			stringstream converter;
			converter << balance;
			converter >> numericBalance;

			//create bank account
			BankCustom* customer = NULL;
			double duplicateBalance = 0;
			if (isDuplicate == true)
			{
				// Merge duplicate info of all fields, combines balance, save off at dupindex
				CommonCustom* cc = new CommonCustom();
				JediCustom* jd = (JediCustom*)mergedMembers[dupIndex];
				duplicateBalance = mergedMembers[dupIndex]->getBalance();
				cc->setFname(fname);
				cc->setLname(lname);
				cc->setGender(gender);
				cc->setID(ID);
				cc->setBalance(numericBalance + duplicateBalance);
				cc->setApprentice(apprentice);
				cc->setSaber(jd->getSaber());
				customer = cc;
				mergedMembers[dupIndex] = customer; 
			}
			else
			{
				// non duplicate sith custom member
				SithCustom* sc = new SithCustom();
				sc = new SithCustom();
				sc->setFname(fname);
				sc->setLname(lname);
				sc->setGender(gender);
				sc->setID(ID);
				sc->setBalance(numericBalance);
				sc->setApprentice(apprentice);
				customer = sc;
				mergedMembers[count++] = customer;
			}
		}
	}
	sithBank.close();
	cout << "Done" << endl;
	cout << endl;

	// output final merged results to MergedData.txt
	cout << "Writing MergedData.txt..." << endl;
	ofstream outputFile;
	outputFile.open("MergedData.txt");
	outputFile << left << setw(16) << "Custom_Name" << left << setw(8) << "Gender" << left << setw(8) << "ID#" << left << setw(16) << "Account_Balance" << left << setw(15) << "Lightsaber" << left << setw(10) << "Apprentice" << endl;
	for (int i = 0; i < count; i++)
	{
		outputFile << mergedMembers[i]->toString();	// derived object toString used via polymorphism
	}
	outputFile.close();
	cout << "Done" << endl;

	return 0;
}