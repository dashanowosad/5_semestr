#include <stdio.h>
#include <process.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		return 0;
	}
		
	if (_execvp(argv[1],argv) == -1)
	perror("execvp call: ");
	
	printf("\nProcess was not created.");
	exit(0);
}
