/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/

#pragma once
#include "BankCustom.h"
class SithCustom :
	public BankCustom
{
public: 

	void setApprentice(string);
	string toString() override; // overrides base class virtual function
	string getApprentice();


private: 
	string apprentice;


};

