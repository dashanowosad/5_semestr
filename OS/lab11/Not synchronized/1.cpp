#include <windows.h>
#include <stdio.h>

int main(){
	int i,j;
	for (j = 0; j < 10; j++) {
		for (i = 0; i < 10; i++) {
			printf("Chaka ");
			fflush(stdout);
			Sleep(5);
		}
		printf("\n");
	}

	return 0;
}
