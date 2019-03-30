#include "PayPhone.h"
#include <fstream>
#include <string>
#define LDC_PRICE 10
#define LC_PRICE 5
using std::string;
using std::ifstream;
using std::fstream;
using std::cout;
using std::endl;

PayPhone::PayPhone(int argc, char * argv[])
{
	initField();

	if (argc > 2 || argv <= 0) {
		cout << "Everything is bad ;(" << endl;
		system("pause");
		return;
	}
	//add money into payphone
	else if (argv[0] == string("a")) {
		this->setMoney(atoi(argv[1]));
		cout << "\n_____I've got it" << endl;
		system("pause");
	}
	//show money that we've got into payphone
	else if (argv[0] == string("s")) {
		this->showMoney();
		system("pause");
	}
	//make a long distance call
	else if (argv[0] == string("cld")) {
		if (this->myTinyCounter(atoi(argv[1]), LDC_PRICE) == 3) {
			return;
		}
		else {
			cout << "Talk is going___(long distance call)" << endl;
			system("pause");
		}
	}
	//make a local call
	else if (argv[0] == string("cl")) {
		if (this->myTinyCounter(atoi(argv[1]), LC_PRICE) == 3) {
			return;
		}
		else {
			cout << "Talk is going___(local call)" << endl;
			system("pause");
		}
	}
	//if we've got wrong command
	else {
		cout << "\nWrong command!" << endl;
		system("pause");
	}
}

void PayPhone::setMoney(int _money)
{	
		this->money += _money;
		writeToFile();
}

void PayPhone::showMoney()
{
	cout << "You've got " << this->money << " , dear friend!" << endl;
}

short PayPhone::myTinyCounter(int _amount, int price)
{
	int value;
	value = price * _amount;
	if (value > this->money) {
		cout << "Add " << value - this->money << " $ to make the call" << endl;
		system("pause");
		return 3;
	} 
	this->money -= value;
	cout << "left in machine: " << money << endl;
	system("pause");
	writeToFile();
	return 2;
}

void PayPhone::initField()
{
	std::ifstream f_ptr("information.txt");

	if(!f_ptr) {
		cout << "Wrong pointer!" << endl;
		return; //for a while
	}
	else {
		f_ptr >> this->money;
		cout << "read perfectly!" << endl;
	}
}

void PayPhone::writeToFile()
{
	string path = "information.txt";
	fstream f_ptr;

	f_ptr.open(path, fstream::out);

	if (!f_ptr.is_open()) {
		cout << "File doesn't open" << endl;
		system("pause");
		return;
	}
	else {
		f_ptr << this->money;
	}

	f_ptr.close();
}
