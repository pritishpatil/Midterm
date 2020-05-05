

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

	//populate jedi members 
	jediBank.open("BankOfJedi.txt", ios::in);
	if (jediBank.fail()) 
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	
	count = 0;
	string ID; string fname; string lname; string saber; string gender; string apprentice; string balance;

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
			customer->printAccount();

		}
	}
	return 0;
}