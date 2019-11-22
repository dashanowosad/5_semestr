#include <windows.h>
#include <stdio.h>

int main() {
	int i,j;
	char lpszAppName[] = "Z:\\Универ\\5_semestr\\OS\\lab11\\Not synchronized\\1.exe";
	STARTUPINFO si;
	char *z;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi)) {
		printf("The new process is not created.\n");
		printf("Press any key to exit.\n");
		gets(z);
		return GetLastError();
	}
	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++) {
			printf("Uga ");
			fflush(stdout);
			Sleep(5);
		}
		printf("\n");
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	system("PAUSE");
	return 0;
}
