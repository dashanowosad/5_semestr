#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void DeleteAll();

struct Student{
	int Course;
	char Name[20];
	char SurName[30];
	struct Student* Next;
}; struct Student* Head = NULL, *Tail = NULL;

void Add(){
	struct Student *p;
	p = malloc( sizeof(struct Student) );
	printf("Input name: \n");
	scanf("%s", p->Name);
	printf("Input Surname: \n");
	fflush(stdin);
	scanf("%s", p->SurName);
	printf("Input course: \n");
	scanf( "%d", &(p->Course));
	
	p->Next = NULL;
	if(Tail == NULL)
		Tail = Head = p;
	else{
		Tail->Next = p;
		Tail = p;
	}
}
void Show(){
	int i = 0, k = 0, j = 0;
	if ((Head != NULL) && (Tail != NULL)){
		struct Student* p;
		p = Head;
		system("clear");
		while ((p != NULL) && (k != 3)){
			printf("Number: %d Course: %d Name: %s Surname: %s \n", ++i, p->Course, p->Name, p->SurName);	
			if (i % 5 == 0){
				printf("\n\n");
				printf("1. Down\n");
				printf("2. Up\n");
				printf("3. Stop\n");
				
				scanf("%d",&k);
				switch(k){
					case 1:{
						system("clear");
						break;       
					}
					case 2:{
						//system("clear");
						k = i;
						i-=5;
						struct Student *q = Head;
						if (i >= 0)
							i-=5;

						j = 0;
						printf("%d\n",i);
							
						while(j != i){
							j++;
							q = q->Next;
						}
						p = q;
						system("clear");
						k = 2;
						
						break;   
					}
					case 3:{
						system("clear");
						break;       
					}
					default:{
						j = 0;
						k = i;
						i-=5;
						struct Student *q = Head;
						while(j != i){
							q = q->Next;
							j++;
						}
						p = q;
						system("clear");
						break;
					}
				}
			}	
			if (k < 2) 
				p = p->Next;
			else if (k != 3)
				k = 0;
		}
	}
	else
		printf("Queue now found");
}

struct Student * Find(int tmp, char *n, char *s){ //поиск по курсу
	struct Student* p;
	p = Head;
	
	while(p != NULL){
		if((p->Course == tmp) && (strcmp(p->Name,n) == 0) && (strcmp(s,p->SurName) == 0)){
			//system("clear");
			//printf("Found element!\n");
			printf("Course: %d Name: %s Surname: %s \n", p->Course, p->Name, p->SurName);
			
			break;
		}
		p = p->Next;
	}
	
	if (p == NULL)
		printf("Element not found\n");
	return p;
}


void Delete(int tmp, char *n, char *s){
	struct Student *p = malloc(sizeof(struct Student));
	printf("Delete: ");	
	p = Find(tmp,n,s);

	if (p == Head){
		if (Head == Tail)
			DeleteAll();
		else {
			Head = Head->Next;
			free(p);
		}
	}
	else if ((p != NULL) && ( p != Head)) {
		struct Student *q = malloc(sizeof(struct Student));
		
		q = Head;
		while( q->Next != p)
			q = q->Next;
		if( p != Tail){
	        	q->Next = p->Next;
			free(p);
		}
		else{
			Tail = q;
			free(p);
			Tail->Next = NULL;
		}
	}

}
void DeleteAll(){
	struct Student *p;
	p = Head;
	while(p != NULL){
		Head = p->Next;
		free(p);
		p = Head;
	}
	Head = Tail = NULL;
	
}

void WTF(char* f){
	struct Student* p;
	p = Head;
	FILE* file = fopen(f, "wb");
	if(file)
		while(p != NULL){
			fwrite(p, sizeof(struct Student), 1, file);
		        //fprintf(file,"%d %s %s\n", p->Course, p->Name, p->SurName);
		
			p = p->Next;
		}
	fclose(file);	
}

void RFF(char *f){
	struct Student *p;
	FILE* file = fopen(f,"rb");
	if(file){
		while(1){
			p = malloc( sizeof(struct Student) );	
			fread(p, sizeof(struct Student), 1, file);
			//fscanf(file,"%d %s %s", &p->Course, p->Name, p->SurName);
			if(feof(file)) 
				break; 
			p->Next = NULL;
			if(Tail == NULL)
				Tail = Head = p;
			else{
				Tail->Next = p;
				Tail = p;
			}
		}
		fclose(file);
	}
	else
		printf("ERROR!\n");
}

int Menu(){
	system("clear");	
	while(1){
		int c = -1, n, i;
		printf("1. Add student in queue\n");
		printf("2. Delete student in queue\n");
		printf("3. Show queue\n");
		printf("4. Find student\n");
		printf("5. Read queue from file\n");
		printf("6. Write queue from file\n");
		printf("7. Delete all queue\n");
		printf("0. Exit\n");
		scanf("%d",&c);
		printf("%c",c);
		switch(c){
			case 1 :{
				system("clear");
				printf("Input number of student\n");
				scanf("%d",&n);
				for(i = 0; i < n; i++)
					Add();
				system("clear");
				break;
			}
			case 2: {
				int C;
				char N[20], S[30];
				system("clear");
				printf("Course: ");
				scanf("%d",&C);
				printf("\nName: ");
				scanf("%s",N);
				printf("\nSurname: ");
				scanf("%s",S);
				Delete(C,N,S);
				printf("\n");
				break;
			}
			case 3:{
				system("clear");
				Show();
				printf("\n\n");
				break;
			}
			case 4:{
				int C;
				char N[20], S[30];
				system("clear");
				printf("Course: ");
				scanf("%d",&C);
				printf("\nName: ");
				scanf("%s",N);
				printf("\nSurname: ");
				scanf("%s",S);
				Find(C,N,S);
				printf("\n");
				break;
			}
			case 5:{
				system("clear");
				char A[20];
				printf("Input file name for read: ");
				scanf("%s", A);
			 	RFF(A);
				printf("\n");	
				break;
			}
			case 6: {
				system("clear");
				char A[20];
				printf("Input file name for write: ");
				scanf("%s", A);
				WTF(A);
				printf("\n");
				break;
			}
			case 7:{
				system("clear");
				printf("Delete all!\n\n");
				DeleteAll();
				break;       
			}
			case 0:{
				return 0;       
			}
			default:{
				system("clear");
				break;		
			}
		}	
	}
}
int main(void){
	Menu();
	return 0;
}
