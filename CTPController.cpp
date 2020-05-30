// CTPController.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>


int main()
{

	printf("main start.\n");

	HANDLE hendEvent = NULL;
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	hendEvent = CreateEvent(&sa, FALSE, FALSE, NULL);

	TCHAR        lpHandle[20];
	memset(lpHandle, 0, sizeof(lpHandle));
	wsprintf(lpHandle, _T("%X"), hendEvent);


	TCHAR szCommondLine[] = _TEXT("NOTEPAD");
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	SECURITY_ATTRIBUTES saProcess, saThread;

	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = TRUE;

	saThread.nLength = sizeof(saThread);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = TRUE;



	BOOL bResult = ::CreateProcess(_T("ChildProcess.exe"), lpHandle, &saProcess, &saThread, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if (!bResult)
	{
		printf("CreateProcess Failed.\n");
	}

	printf("Sleep 5 seconds.\n");

	Sleep(5000);

	printf("SetEvent end \n");
	SetEvent(hendEvent);

	printf("END \n");
    return 0;
}

