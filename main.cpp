

#include <iostream>
#include <fstream>
#include <string>
#include "BankCustom.h"
using namespace std;

int main()
{
	BankCustom* mergedMembers[MAX];
	int index;
	string line;
	ifstream jediBank;
	//populate student array 
	jediBank.open("BankOfJedi.txt", ios::in);
	if (jediBank.fail()) 
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}
	getline(jediBank, line);
	index = 0;
	string ID; string fname; string lname; string saber; string gender;
	double balance;
	while (index < MAX && jediBank >> fname >> lname >> gender >> ID >>  balance >> saber)
	{
		mergedMembers[index]->setFname(fname);
		mergedMembers[index]->setLname(lname);
		mergedMembers[index]->setGender(gender);
		mergedMembers[index]->setID(ID);
		mergedMembers[index]->setBalance(balance);
		index++;
	}
	cout << "Number of customers in JediBank: " << index << endl;
	return 0;
}