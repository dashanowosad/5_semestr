#include <windows.h>
#include <process.h>
#include <stdio.h>

HANDLE 	hSemaphore;
char sh[6];
void Tread (void *p);

int main(void){
	hSemaphore = CreateSemaphore(NULL,1 ,1,NULL);
	system("PAUSE");
	_beginthread(Tread,0,NULL);
	while(1){
		WaitForSingleObject(hSemaphore,INFINITE);
		printf("%s\n",sh);
		ReleaseSemaphore(hSemaphore,1, NULL);
	}
	CloseHandle(hSemaphore);
	return 0;
}

void Tread(void * pParams){
	int counter = 0;
	while(counter < 100000){
	
		WaitForSingleObject(hSemaphore, INFINITE);
		if(counter%2){ 
			sh[0]='H';
			sh[1]='e';
			sh[2]='l';
			sh[3]='l';
			sh[4]='o';
			sh[5]='\0';
		}
		else{
			sh[0]='B';
			sh[1]='y';
			sh[2]='e';
			sh[3]='_';
			sh[4]='u';
			sh[5]='\0';
		}
		
		ReleaseSemaphore(hSemaphore,1,NULL);
		counter++;
	}
}
