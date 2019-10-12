#include <stdio.h>
#include <process.h>
#include <string.h>
#include <windows.h>
/*
void ls (char *s, char *str, char *istr){
	istr = strtok(NULL, " -");
	while(istr != NULL){
		printf("%s", istr);
		if (strncmp(istr, "a", 1) == 0) //скрытые файлы
			strcat(str, " /ah");
		else if (strncmp(istr, "c", 1) == 0) //sort from old to new
			strcat(str, " /od");
		else if (strncmp(istr, "t", 1) == 0) //сортировка по последней модификации;
			strcat(str, " /tw");
		else if (strncmp(istr, "l", 1) == 0) //вывод сведений об авторе
			strcat(str, " /q");
		else //подправить, не работает, если после команды пробелы
			strcpy(str,"");



	istr = strtok(NULL, " -");
	}
}
*/

int main(int argc, char** argv){
	while(1){
		char s[20] = "", str[20] = "";
		char *istr;
		int i;
		//fgets(s, sizeof(s), stdin);
		scanf("%s",s);
		//istr = strtok(s," ");
		
		/*while(istr != NULL){
			if (strncmp(istr, "ls", strlen(istr)) == 0) { //ls in Linux == dir in Windows with keys:
				strcpy(str, "dir");
				ls(s,str,istr);
			}
	
				
			istr = strtok(NULL, " -");
		}*/
		//printf("%s",s);
		if (strcmp(s,"ls") == 0)
			strcat(str, "dir");
		else if (strcmp(s,"clear") == 0)
			strcpy(str, "cls");
		else if (strcmp(s,"ps") == 0)
			strcpy(str, "tasklist");
		else if (strcmp(s,"ip") == 0)
			strcpy(str, "ipconfig");
		
		
	
		
		if (strlen(str) != 0){
   			system("cls");
			char* argv[]={"cmd", "/C", str, NULL };
			_spawnvp(_P_NOWAIT,argv[0], argv);
		} 
		
		else{
			//MessageBox(NULL,"Wrong command!","Message", MB_OK);
			printf("Wrong command!\n");
		}
			

		
		//printf("%s",s);
		
	}
}
