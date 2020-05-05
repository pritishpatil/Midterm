/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/

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
	virtual string toString() = 0; // pure virtual function of base abstract class

protected:
	string firstname; 
	string lastname; 
	string id; 
	string gender; 
	double accountBalance;

};

