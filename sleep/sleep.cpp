#define _CRT_SECURE_NO_WARNINGS
#ifdef _WIN32
#include <Windows.h>
#include <time.h>

#elif(defined(__linux__) || defined(__unix__))
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#endif
#include "PayPhone.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
	//printf("Enter smth to go on!\n");
	//system("pause");

	if (std::string("-m") == argv[1]) {
		PayPhone payPh(argc - 2, argv + 2);
	}
	else {
		std::cout << "smth wrong(sleep)!" << std::endl;
		//system("pause");
		getch();
	}
	
	return 0;
}