#pragma once

#include <iostream>
#include <string>
using namespace std;



class BankCustom
{
public:
	
	void setID(string);
	void setLname(string);
	void setFname(string);
	void setGender(string);
	void setBalance(double);
	string getid();
	string getLname();
	string getFname();
	string getGender();
	double getBalance();
	virtual void printAccount() = 0;

protected:
	string firstname; 
	string lastname; 
	string id; 
	string gender; 
	double accountBalance;

};

