#pragma once
#include "BankCustom.h"
class JediCustom :
	public BankCustom
{
public: 

	void setSaber(string);
	void printAccount() override;
	string getSaber();


private: 
	string saber;
};

