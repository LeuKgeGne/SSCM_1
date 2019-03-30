#define _CRT_SECURE_NO_WARNINGS
#ifdef _WIN32
#include <Windows.h>
#include <time.h>

#elif(defined(__linux__) || defined(__unix__))
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include "menu.h"
#include "Individual.h"

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Individual indiv;

	int amount = 0;
	int changer = -1;
	bool flag = true;
	bool checkSuccess = true;

	while (flag) {
		string parametrs = "-m";

		switch (menu(changer)) {
		case 1: {
			parametrs += " s";
		} break;
		case 2: {
			parametrs += " c";
			switch (subMenu(changer)) {
			case 1: {
				parametrs += "ld " + std::to_string(amountOfSecondsToTalk(amount));
			} break; //long distance call
			case 2: {
				parametrs += "l " + std::to_string(amountOfSecondsToTalk(amount));
			} break; //local call
			case 0: {
				//return;
			} break;
			default: {
				cout << "What's the hell, dude? Return you back -_-" << endl;
			} break;
			}
		} break;
		case 3: {
			parametrs += " a " + std::to_string(indiv.inputMoney());
		} break;
		case 0: {
			flag = false;
			checkSuccess = false;
		} break;
		default: {
			cout << "Help yourself!" << endl;
			checkSuccess = false;
		}
		}

		//start daughters' process
		if (checkSuccess) {
			indiv.runChild(parametrs);
		}
		system("cls");
	}
	return 0;
}