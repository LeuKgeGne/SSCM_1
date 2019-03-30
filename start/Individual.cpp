
#define _CRT_SECURE_NO_WARNINGS
#ifdef _WIN32
#include <Windows.h>
#include <time.h>

#elif(defined(__linux__) || defined(__unix__))
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#include "Individual.h"


unsigned int Individual::inputMoney()
{
	int someMoney = 0;
	cout << "Put your money in:" << endl;
	cin >> someMoney;
	return someMoney;
}

void Individual::runChild(std::string & par) const
{
#ifdef _WIN32
	STARTUPINFO startupInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);
	ZeroMemory(&processInfo, sizeof(processInfo));

	if (!CreateProcess(NULL,
		(LPSTR)(std::string("Z:\\SSCM\\Start\\Debug\\sleep.exe ") + par).c_str(),
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&startupInfo,
		&processInfo)) {
		cout << "We're not able to create any process :(" << endl;
		return;
	}

	//while (!processInfo.hProcess) {
	//	char buffer[80];
	//	time_t seconds = time(NULL);
	//	tm* timeinfo = localtime(&seconds);
	//	const char* format = "%A, %B %d, %Y %H:%M %S";
	//	strftime(buffer, 80, format, timeinfo);
	//	cout << buffer << endl;
	//	system("cls");
	//}

	WaitForSingleObject(processInfo.hProcess, INFINITE);

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

#elif ((__linux__) || (__unix)__)
	//std::string someParametrs = /home/eugene/Документы/BSUIR/SSCM/SSCM_1/sleep

	pid_t pid = fork();

	if (pid < 0)
	{
		cout << "No chances to turn on this machine" << endl;
		return;
	}
	else if (pid > 0) {
		if (waitpid(pid, nullptr, 0) != pid)
		{
			cout << "Completed a process" << endl;
		}
		DualFree(someParametrs);
	}
	else {
		//execve("sleep.exe", someParametrs, nullptr);
	}
#else 
	cout << "Recompile it in Unix" << endl;
#endif
}
