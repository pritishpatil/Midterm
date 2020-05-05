#pragma once
#include "BankCustom.h"
class SithCustom :
	public BankCustom
{
public: 

	void setApprentice(string);
	void printAccount() override;
	string getApprentice();


private: 
	string apprentice;


};

