#pragma once
#include "BankCustom.h"
class SithCustom :
	public BankCustom
{
public: 

	void setApprentice(string);
	string toString() override;
	string getApprentice();


private: 
	string apprentice;


};

