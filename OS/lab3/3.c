#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	int status;
	pid_t parent_pid, child1_pid, child2_pid, child3_pid;

	if (((child1_pid = fork()) == 0) && ((child2_pid = fork()) == 0) && ((child3_pid = fork()) == 0)){
		printf("\nTree:\n");
		system("pstree -U | grep -m 1 -A 1 'a.out'"); 
		printf("\n\nInformation:\n");
		//system("dir /proc | grep ");
		

	}
	else{
		waitpid(child1_pid,&status,0);
		waitpid(child2_pid,&status,0);
		waitpid(child3_pid,&status,0);
	}
	
	return 0;
}
