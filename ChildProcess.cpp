// ChildProcess.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <process.h>


unsigned __stdcall ThreadStaticEntryPoint(void * pThis)
{

	while (true)
	{

		Sleep(2000);
		printf("ThreadStaticEntryPoint while loop\n");
	}


	_endthreadex(0);
	return 0;
}

int main(int argc, char *argv[])
{
	
	printf("ChildProcess Start\n");
	HANDLE hEndEvent = NULL;
	_stscanf_s(GetCommandLine(), _T("%x"), &hEndEvent);


	HANDLE hThread;
	unsigned threadID;

	hThread = (HANDLE)_beginthreadex(NULL, 0, &ThreadStaticEntryPoint, NULL, 0, &threadID);






	printf("WaitForSingleObject hEndEvent\n");
	WaitForSingleObject(hEndEvent, INFINITE);






	printf("ChildProcess End\n");

    return 0;
}

