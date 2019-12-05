#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

#define PORT 1952
//#define SERVERADDR "25.26.73.160"

int main(int argc, char* argv[]){
	char SERVERADDR[16] = "";
	char buff[1024] = "";
	struct sockaddr_in dest_addr;
	SOCKET my_sock;
	struct hostent *hst;
	int nsize;
	
	printf("Input IP adress: ");
	scanf("%s",&SERVERADDR);
	fflush(stdin);
	fflush(stdout);
	//инициализация библиотеки Winsock
	if (WSAStartup(0x202,(WSADATA*)&buff[0])){
		printf("Error WSAStartup %d\n", WSAGetLastError());
		return -1;
	}
	
	//создание сокета
	my_sock = socket(AF_INET,SOCK_STREAM,0);
	if(my_sock < 0){
		printf("Socket() error %d\n", WSAGetLastError());
		return -1;
	}
	//установка соединения
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(PORT);
	
	//преобразование IP адреса из символьного в сетевой формат
	if (inet_addr(SERVERADDR) != INADDR_NONE)
		dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	else
	//получение IP фдреса по доменному имени сервера
	if (hst = gethostbyname(SERVERADDR))
		((unsigned long *)&dest_addr.sin_addr)[0] =
		((unsigned long **)hst->h_addr_list)[0][0];
	else{
		printf("Invalid address %s\n", SERVERADDR);
		closesocket(my_sock);
		WSACleanup();
		return -1;
	}
	
	//установка соединения
	if (connect(my_sock,(struct sockaddr *)& dest_addr, sizeof(dest_addr))){
		printf("Connect error %d\n", WSAGetLastError());
		return -1;
	}
	printf("Connection with %s was established\n\
					Type quit for quit\n\n", SERVERADDR);
	//чтение и передача сообщений
	while((nsize = recv(my_sock,&buff[0],sizeof(buff) - 1,0)) != SOCKET_ERROR){
		buff[nsize] = 0;
		printf("ServerToClient: %s", buff);
		
		printf("ClientToServer:");
		fgets(&buff[0],sizeof(buff)-1,stdin);
		
		if(!strcmp(&buff[0],"quit\n")){
			printf("Exit...");
			closesocket(my_sock);
			WSACleanup();
			return 0;
		}
		send(my_sock,&buff[0],nsize,0);
	}
	
	printf("Recv error %d\n", WSAGetLastError());
	closesocket(my_sock);
	WSACleanup();
	
	return -1;

}



















