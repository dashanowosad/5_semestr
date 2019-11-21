#include <windows.h>
#include <stdio.h>

int main(){
	char lpszAppName[] = "Z:\\Универ\\5_semestr\\OS\\lab11\\synchronized\\os.exe";
	int i, j;
	HANDLE hMutex;
	STARTUPINFO si;
	char *z;
	PROCESS_INFORMATION pi;
	hMutex = CreateMutex(NULL, FALSE, "DemoMutex"); 
	
	if (hMutex == NULL)	{
		printf("Open mutex failed.\n"); 
		printf("Press any key to exit.\n");
		gets(z);
		return GetLastError();
    } 
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
 	if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE,
 		NULL, NULL, NULL, &si, &pi)){
		printf("The new process is not created.\n"); 
		printf("Press any key to exit.\n");
		gets(z);
		return GetLastError();
	}
 
	for (j = 0; j < 10; j++) {
		WaitForSingleObject(hMutex, INFINITE); 
		for (i = 0; i < 10; i++){
	 		printf("Uga ");
 			fflush(stdout);
 			Sleep(5);
 		}
 	printf("\n");
 	ReleaseMutex(hMutex);
 	}
 	
 	CloseHandle(hMutex);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	return 0;
} 
