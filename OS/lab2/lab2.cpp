#include <windows.h>
#include <stdio.h>

int main(void){
	char WindowsPath[100], TempPath[100];
	SYSTEM_INFO info;
	MEMORYSTATUSEX statex;
	GetWindowsDirectory(WindowsPath, 100);
	GetTempPath(100, TempPath);
	system("cls");
	printf("Directory: %s\n",WindowsPath);
	printf("Temp path: %s\n",TempPath);
	
	GetSystemInfo(&info);
	printf("Number of Processors %u \n",info.dwNumberOfProcessors);
	printf("Processor type %u \n",info.dwProcessorType);
	printf("Minimum application adress %lx \n",info.lpMinimumApplicationAddress);
	printf("Maximum application adress %lx\n",info.lpMaximumApplicationAddress);
	statex.dwLength = sizeof (statex);
	GlobalMemoryStatusEx(&statex);
	printf("There is %ld percent of memory in use: \n", statex.dwMemoryLoad);
	printf("There are %I64d total KB of phisical memory: \n", statex.ullTotalPhys);
	printf("There are %I64d free KB of phisical memory: \n", statex.ullAvailPhys);
	printf("There are %I64d total KB of virtual memory: \n", statex.ullTotalVirtual);
	printf("There are %I64d free KB of virtual memory: \n", statex.ullAvailVirtual);
	system("pause");
	return 0;
}
