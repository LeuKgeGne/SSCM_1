#ifndef INDIVIDUAL_CLASS
#define INDIVIDUAL_CLASS
#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

class Individual
{
public:
	Individual() {}
	~Individual() {}
	unsigned int inputMoney();
	void runChild(std::string& par) const;
};

#endif