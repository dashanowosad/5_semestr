#include <windows.h>
#include <stdio.h>
#include <conio.h>
int main(){
	char c; // ��� ������
	HANDLE hPipe;
	char MessageIn[256]="", MessageOut[256]="", machineName[80], pipeName[80],MessageIn1[256]="";
	DWORD BytesWrite, BytesRead;

	printf("Name of your mashin: ");
	scanf("%s",&machineName);
	wsprintf(pipeName,"\\\\%s\\pipe\\MyPipe",machineName);
	hPipe = CreateFile(
				pipeName,
				GENERIC_READ|GENERIC_WRITE,
				FILE_SHARE_READ|FILE_SHARE_WRITE,
				NULL,
				OPEN_EXISTING, //����������� � ������������� ������
				0,
				NULL);
				
   if (hPipe == INVALID_HANDLE_VALUE){
		printf("CreatePipe failed: error code %d\n", (int)GetLastError());
		return 0;
	}
	while(1){
  		//������ ���������
		if (!ReadFile(
			hPipe,
			MessageIn,
			sizeof(MessageIn), // ����� �������� ������
			&BytesRead, //����� ����������� ����
			NULL)){ //�������� ������ ����������
				printf("\nServer was close\nPress any key to out");
				break;
		}
		else {
			if (strcmp(MessageIn1, MessageIn) != 0){
				printf("Someone's' message:  %s\n",MessageIn);
				memset(MessageIn1,0,256);
				strcpy(MessageIn1,MessageIn);
			}
			
			
		}


		//�������� ���������
		if (kbhit()){
			printf("Your message:  ");
			scanf("%s",MessageOut);
		}
		

		WriteFile(
			hPipe,
			MessageOut,
			sizeof(MessageOut),
			&BytesWrite,
			NULL);

	}
	
	scanf("%c",&c);
	CloseHandle(hPipe);
	system("PAUSE");
	return 0;
}
