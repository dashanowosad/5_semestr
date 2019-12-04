#include <stdio.h>
#include <windows.h>

int main(){
	HANDLE hPipe;
	char MessageIn[256], MessageOut[256];
	DWORD BytesRead, BytesWrite;
	
	///////////////
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;
	
	sa.nLength = sizeof(sa);
	sa.bInheritHandle = FALSE; //���������� ������ �� �����������
	InitializeSecurityDescriptor(&sd,SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd,TRUE,NULL,FALSE); //��������� ������ ���� �������������
	sa.lpSecurityDescriptor = &sd;
	///////////////
	hPipe = CreateNamedPipe(
				"\\\\.\\pipe\\MyPipe",
				PIPE_ACCESS_DUPLEX, //������ �� ������ � ����� � �����
				PIPE_TYPE_MESSAGE| PIPE_WAIT, //���������� �������� ���������
				1, //������������ ���������� ����������� ������
				0, //������ ��������� ������ �� ���������
				0, //������ �������� ������ �� ���������
				INFINITE, //�������� ����� 500 ��
				NULL); //����� �� ��������
				
   if (hPipe == INVALID_HANDLE_VALUE){
		printf("CreatePipe failed: error code %d\n", (int)GetLastError());
		return 0;
	}
	
	if ((ConnectNamedPipe(hPipe,NULL)) == 0){ //�������� �� �����
		printf("Client could not connect\n");
		return 0;
	}
	else
		printf("		SOMEONE IS CONNECT!\n");
	while(1){
		//�������� ���������
		printf("Your message:  ");
		scanf("%s",MessageOut);
		WriteFile(
			hPipe,
			MessageOut,
			sizeof(MessageOut),
			&BytesWrite,
			NULL);


		//������ ���������
		if(ReadFile(
			hPipe,
			MessageIn,
			sizeof(MessageIn), // ����� �������� ������
			&BytesRead, //����� ����������� ����
			NULL)) //�������� ������ ����������
				printf("someone's' message:  %s\n",MessageIn);

		//printf("\n");
	}
	
	CloseHandle(hPipe);
	system("PAUSE");
	return 0;
}
