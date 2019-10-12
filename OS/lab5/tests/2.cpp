#include <windows.h>
#include <iostream>
int main(){
	HWND hWnd;
	COPYDATASTRUCT data;
	char str[80];
	hWnd = FindWindow(TEXT("Notepad"), NULL);
	do{
		gets(str);
		data.cbData = strlen(str);
		data.lpData=str;
		SendMessage(hWnd, WM_COPYDATA, (WPARAM)GetFocus(), (LPARAM)&data);
	} while(strcmp(str,"quit"));
	if (hWnd)
		CloseWindow(hWnd);
		else
			printf("fhuerf");
	return 0;
}
