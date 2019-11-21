#include <windows.h>
#include <stdio.h>
int main(){
	int i,j;
	HANDLE hMutex;
	char* z;
	hMutex = OpenMutex(SYNCHRONIZE, FALSE, "DemoMutex"); 
	if (hMutex == NULL)	{
		printf("Open mutex failed.\n"); 
		printf("Press any key to exit.\n");
		gets(z);
		return GetLastError();
    } 
 	for (j = 0; j < 10; j++) {	
 		WaitForSingleObject(hMutex, INFINITE); 
		for (i = 0; i < 10; i++){
	 		printf("Chaka ");
 			fflush(stdout);
 			Sleep(5);
 		}
 	printf("\n");
 	ReleaseMutex(hMutex);
 	}
 	CloseHandle(hMutex);
	return 0;
} 
