#include <stdio.h>
#include <process.h>
#include <string.h>
#include <windows.h>

void ls (char *s, char *str, char *istr){
	istr = strtok(NULL, " -");
	while(istr != NULL){
		if (istr[0] == 'a') //скрытые файлы
			strcat(str, " /ah");

		//добавить ифов 
		else //подправить, не работает, если после команды пробелы
			strcpy(str,"");



	istr = strtok(NULL, " -");
	}
}


int main(){
	while(1){
		char s[20] = "", str[20] = "";
		char *istr;
		int i;
		fgets(s, sizeof(s), stdin);
		istr = strtok(s," -");
		
		while(istr != NULL){
			if (istr[0] == 'l' && istr[1] == 's') { //ls in Linux == dir in Windows with keys:
				strcpy(str, "dir");
				ls(s,str,istr);
			}
			
	
				
			istr = strtok(NULL, " -");
		}
		//printf("%d\n",strlen(str));
		//printf("fueghf");
		
		
		if (strlen(str) != 0){
   			system("cls");
			char* argv[]={"cmd", "/C", str, NULL };
			_spawnvp(_P_NOWAIT,argv[0], argv);
		} 
		
		else{
			//MessageBox(NULL,"Wrong command!","Message", MB_OK);
			printf("Wrong command!");
		}
			

		
		//printf("%s",s);
		
	}
}
