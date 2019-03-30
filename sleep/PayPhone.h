#ifndef PayPhone_CLASS
#define PayPhone_CLASS
#pragma once
#include <iostream>

class PayPhone
{
public:
	PayPhone(int argc, char* argv[]);
	~PayPhone() {}

	void setMoney(int _money);
	void showMoney();
	short myTinyCounter(int _amount, int price);
	void initField();

	//work with file
	void writeToFile();
private:
	int money;
};

#endif