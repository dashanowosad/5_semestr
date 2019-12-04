#include <stdio.h>
#include <windows.h>

int main(){
	HANDLE hPipe;
	LPTSTR lpPipeName = TEXT("\\\\.\\pipe\\MyPipe");
	DWORD iBytesToWrite;
	char buff[] = "A message from the client";
	
	hPipe = CreateFile(
				lpPipeName,
				GENERIC_READ|
				GENERIC_WRITE,
				0,
				NULL,
				OPEN_EXISTING,
				0,
				NULL);
	WriteFile(hPipe,buff,strlen(buff), &iBytesToWrite, NULL);
	CloseHandle(hPipe);
	system("PAUSE");
}
