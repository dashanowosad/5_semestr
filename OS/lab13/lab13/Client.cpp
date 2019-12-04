#include <windows.h>
#include <stdio.h>

int main(){
	char c; // для выхода
	HANDLE hPipe;
	char MessageIn[256], MessageOut[256], machineName[80], pipeName[80];
	DWORD BytesWrite, BytesRead;
	//LPTSTR lpPipeName = TEXT("\\\\.\\pipe\\MyPipe");
	printf("Name of your mashin: ");
	scanf("%s",&machineName);
	wsprintf(pipeName,"\\\\%s\\pipe\\MyPipe",machineName);
	hPipe = CreateFile(
				pipeName,
				GENERIC_READ|GENERIC_WRITE,
				FILE_SHARE_READ|FILE_SHARE_WRITE,
				NULL,
				OPEN_EXISTING, //подключение к существующему каналу
				0,
				NULL);
				
   if (hPipe == INVALID_HANDLE_VALUE){
		printf("CreatePipe failed: error code %d\n", (int)GetLastError());
		return 0;
	}
	while(1){
  		//читаем сообщение
		if (!ReadFile(
			hPipe,
			MessageIn,
			sizeof(MessageIn), // число читаемых данных
			&BytesRead, //число прочитанный байт
			NULL)){ //передача данных синхронная
				printf("\nServer was close\nPress any key to out");
				break;
		}
		else printf("Client message:  %s\n",MessageIn);
		
		//отправка сообщения
		printf("Your message:  ");
		scanf("%s",MessageOut);
		WriteFile(
			hPipe,
			MessageOut,
			sizeof(MessageOut),
			&BytesWrite,
			NULL);
	}
	
	scanf("%c",&c);
	CloseHandle(hPipe);
}
