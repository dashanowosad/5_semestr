#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	int status;
	pid_t child_pid, parent_pid;
	printf("Parent pid = %i\n", parent_pid = (int)getpid());
	if ((child_pid = fork()) == 0)  {
	        printf("Child pid = %i\n", child_pid = (int)getpid());	
		printf("\nInformation with ps and grep:\n");
		system("ps | grep 'a.out' ");
		
		kill(parent_pid,SIGKILL);
		system("echo");
		printf("\nInformation after kill parent:\n");                    
		system("ps | grep 'a.out' ");
		//exit(child_pid);
	}
	else{
		waitpid(child_pid, &status,0);
	}
	//kill(child_pid,SIGINT);
	return 0;
}
