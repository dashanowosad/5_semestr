#include <windows.h>
#include <time.h>
#include <chrono>
#include <stdio.h>

#define THREADS_NUMBER 2
#define ITERATIONS_NUMBER 500
#define PAUSE 10 /* ms */

bool readyFlags[2];
int turn;

void EnterCriticalRegion(int threadId){
	readyFlags[threadId] = true;
	turn = 1 - threadId;
	while(turn == 1 - threadId && readyFlags[1 - threadId]);
}

void LeaveCriticalRegion(int threadId){
	readyFlags[threadId] = false;
}
int sh =0;
void thread1(){
	int i = 0;
	for (; i < ITERATIONS_NUMBER; i++){
		EnterCriticalRegion(0);
		sh+=20;
		LeaveCriticalRegion(0);
		Sleep(10);
	}
	readyFlags[0]=0;
}

void thread2(){
	int i = 0;
	for(; i < ITERATIONS_NUMBER; i++){
		EnterCriticalRegion(1);
		sh+=20;
		LeaveCriticalRegion(1);
		Sleep(10);
	}
	readyFlags[1] = 0;
}
DWORD dwCounter = 0;

DWORD WINAPI ThreadProc(CONST LPVOID lpParam) {
  CONST HANDLE hMutex = (CONST HANDLE)lpParam;
  DWORD i;
  for(i = 0; i < ITERATIONS_NUMBER; i++) {
    WaitForSingleObject(hMutex, INFINITE);
    dwCounter+=20;
    ReleaseMutex(hMutex);
    Sleep(PAUSE);
  }
  ExitThread(0);
}


INT main() {
  TCHAR szMessage[256];
  DWORD dwTemp, i;
//  clock_t start, stop;
  HANDLE hThreads[THREADS_NUMBER];
  CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

  for(i = 0; i < THREADS_NUMBER; i++) 
    hThreads[i] = CreateThread(NULL, 0, &ThreadProc, hMutex, 0, NULL);
//  wsprintf(szMessage, TEXT("Expected value = %d\r\n"), 20000);
  //WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);

  auto start = std::chrono::system_clock::now();
  WaitForMultipleObjects(THREADS_NUMBER, hThreads, TRUE, INFINITE);
  std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
  
  wsprintf(szMessage, TEXT("Value = %d\r\n"), dwCounter);
  WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);
  printf("Time = %f\n ",dur.count());
  start = std::chrono::system_clock::now();
  thread1();
  thread2();
  dur = std::chrono::system_clock::now() - start;
  printf("Peterson = %d\n ",sh);
  printf("Time = %f\n ",dur.count());
  for(i = 0; i < THREADS_NUMBER; i++) {
    CloseHandle(hThreads[i]);
  }
  CloseHandle(hMutex);
  ExitProcess(0);
}
