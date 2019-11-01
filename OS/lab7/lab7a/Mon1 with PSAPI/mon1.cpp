#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include <tchar.h>


int Print(DWORD ProcessID){
	
	HMODULE hMod[1024];
	DWORD cbNeeded, NumberOfReternProcess;
	HANDLE hProcess;

	char modName[MAX_PATH], modName1[MAX_PATH];
	int i, flag = -1;
	
	hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,ProcessID);
	
	if (hProcess != NULL){
		
		if(EnumProcessModules(hProcess,hMod,sizeof(hMod),&cbNeeded)){
			GetModuleBaseName(hProcess,hMod[i],(LPSTR)modName,sizeof(modName));
			if (strcmp(modName,"Prog1.exe") == 0) {
				flag = 0;
				printf("PID: %d\n",ProcessID);	
				NumberOfReternProcess = cbNeeded / sizeof(DWORD);
				for (i = 0; i < NumberOfReternProcess; i++){
					GetModuleBaseName(hProcess,hMod[i],(LPSTR)modName,sizeof(modName));
					GetModuleFileName(hMod[i],(LPSTR)modName1,sizeof(modName1));
					printf("	%s  %s\t\n",modName, modName1);
					if (strcmp(modName, "MyDll.dll") == 0)
						flag = 1;
				}
			}
		}	
		
		if(flag == 0)
			printf("\nMyDLL was NOT found");
		else  if (flag == 1)
			printf("\nMyDLL was foud");
		flag = -1;
	}
	
	
	
	
}

int main(void){	
char k = 0;
while(k != 1){
	DWORD *Process, cb = 1024, cbNeeded, NumberOfReternProcess;
	int i;
	
	Process = (DWORD*)malloc(cb);
	if (!EnumProcesses(Process, cb, &cbNeeded))
		return 1;
	
	NumberOfReternProcess = cbNeeded / sizeof(DWORD);
	
	for ( i = 0; i < NumberOfReternProcess; i++ )
    {
        if( Process[i] != 0 )
        {
            Print( Process[i] );
            //printf("%d\n",Process[i]);
        }
        //printf("\n\n%d",GetCurrentProcessId());
    }
    printf("\nIf you want to exit print '1', else press another key\n");
    scanf("%c",&k);
    system("cls");
}
	return 0;
}
