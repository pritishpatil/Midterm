/*
	PIC 10B 2B, Midterm Exam
	Author: Pritish Patil
	Date: 05/05/2020
*/

#pragma once
#include "BankCustom.h"
class JediCustom :
	public BankCustom
{
public: 

	void setSaber(string);
	string toString() override; // overrides base class virtual functionr 
	string getSaber();


private: 
	string saber;
};

