#include <stdio.h>
#include <process.h>

int main(){
	char* argv[]={"cmd","/C","dir",NULL};
	_execvp(argv[0],argv);
	
	printf("\nProcess was not created.");
	//system("PAUSE");
	exit(0);
}

