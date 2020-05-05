#pragma once
#include "BankCustom.h"
class CommonCustom :
	public BankCustom
{
public:

	void setApprentice(string);
	void setSaber(string);
	void printAccount() override;
	string getApprentice();
	string getSaber();

private:
	string apprentice;
	string saber;
};

