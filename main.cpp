

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
	int jediCount = count;
	cout << "Done" << endl;


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

	// output final merged results to MergedData.txt
	cout << "Writing MergedData.txt..." << endl;
	ofstream outputFile;
	outputFile.open("MergedData.txt");
	outputFile << "Custom_Name	Gender	ID#	Account_Balance Saber Apprentice" << endl;
	for (int i = 0; i < count; i++)
	{
		outputFile << mergedMembers[i]->toString();
	}
	outputFile.close();
	cout << "Done" << endl;

	return 0;
}