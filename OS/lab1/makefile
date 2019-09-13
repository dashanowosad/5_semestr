all: prog clear
prog: lab.o
	gcc lab.o -o prog
lab.o: lab.c 
	 gcc -c -Wall lab.c

clear:
	rm -rf *.o
