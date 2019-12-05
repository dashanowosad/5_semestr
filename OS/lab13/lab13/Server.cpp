#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main(){
	HANDLE hPipe;
	char MessageIn[256]="", MessageOut[256]="",MessageIn1[256]="";
	DWORD BytesRead, BytesWrite;
	
	///////////////
	SECURITY_ATTRIBUTES sa;
	SECURITY_DESCRIPTOR sd;

	sa.nLength = sizeof(sa);
	sa.bInheritHandle = FALSE; //дескриптор канала не наследуемый
	InitializeSecurityDescriptor(&sd,SECURITY_DESCRIPTOR_REVISION);
	SetSecurityDescriptorDacl(&sd,TRUE,NULL,FALSE); //разрешили доступ всем пользовател€м
	sa.lpSecurityDescriptor = &sd;
	///////////////
	
	hPipe = CreateNamedPipe(
				"\\\\.\\pipe\\MyPipe",
				PIPE_ACCESS_DUPLEX, //читаем из канала и пишем в канал
				PIPE_TYPE_MESSAGE| PIPE_WAIT, //синхронна€ передача сообщений
				1, //максимальное количество экземпл€ров канала
				0, //размер выходного буфера по умолчанию
				0, //размер входного буфера по умолчанию
				INFINITE, //ожидание св€зи 500 мс
				&sa); //защита по умолчани (доступ по имени компа)

   if (hPipe == INVALID_HANDLE_VALUE){
		printf("CreatePipe failed: error code %d\n", (int)GetLastError());
		return 0;
	}
	
	if ((ConnectNamedPipe(hPipe,NULL)) == 0){ //проверка на св€зь
		printf("Client could not connect\n");
		return 0;
	}
	else
		printf("		SOMEONE IS CONNECT!\n");
	while(1){

		//отправка сообщени€
		if(kbhit()){
			printf("Your message:  ");
			scanf("%s",MessageOut);
		}
		
		if (MessageOut != NULL) WriteFile(
			hPipe,
			MessageOut,
			sizeof(MessageOut),
			&BytesWrite,
			NULL);
			


		//чтение сообщени€
		ReadFile(
			hPipe,
			MessageIn,
			sizeof(MessageIn), // число читаемых данных
			&BytesRead, //число прочитанный байт
			NULL); //передача данных синхронна€

		if (strcmp(MessageIn1, MessageIn) != 0){
				printf("Someone's' message:  %s\n",MessageIn);
				memset(MessageIn1,0,256);
				strcpy(MessageIn1,MessageIn);
			}

	}
	
	CloseHandle(hPipe);
	system("PAUSE");
	return 0;
}
