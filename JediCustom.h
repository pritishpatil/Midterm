#pragma once
#include "BankCustom.h"
class JediCustom :
	public BankCustom
{
public: 

	void setSaber(string);
	string toString() override;
	string getSaber();


private: 
	string saber;
};

