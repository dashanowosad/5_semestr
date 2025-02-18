#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(){
	int status;
	char sys[40];
	pid_t parent_pid, child1_pid, child2_pid, child3_pid;
	parent_pid= (int)getpid();
	//int t =(int)getpid();
	sprintf(sys,"dir /proc/%d/task",(int)parent_pid);
	//printf("Parent /proc/task/:");
	system(sys);
	
	if ((child1_pid = fork()) == 0) {
		child1_pid = (int)getpid();
		sprintf(sys,"dir /proc/%d/task",(int)child1_pid);
		//intf("Child1 /proc/task/:");
		system(sys);
		if ((child2_pid = fork()) == 0){
			child2_pid = (int)getpid();
			sprintf(sys,"dir /proc/%d/task",(int)child2_pid);
			//intf("Child2proc/task/:");
			system(sys);
			if ((child3_pid = fork()) == 0){
				child3_pid = (int)getpid();		
				sprintf(sys,"dir /proc/%d/task",(int)child3_pid);
				//intf("Child3/proc/task/:");
				system(sys);
				
				printf("\nTree:\n");
				system("pstree -U | grep -m 1 -A 1 'a.out'"); 
				//printf("\n\nInformation:\n");
			//	printf("%i/n %i/n %i/n",child1_pid,child2_pid,child3_pid);
				
			}
			else
				waitpid(child3_pid,&status,0);
		}
		else
			waitpid(child2_pid,&status,0);
	}
	else
		waitpid(child1_pid,&status,0);
	/*else{
		waitpid(child1_pid,&status,0);
		waitpid(child2_pid,&status,0);
		waitpid(child3_pid,&status,0);
	}*/
	
	return 0;
}


