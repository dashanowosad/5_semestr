#include <windows.h>

#define THREADS_NUMBER 10
#define ITERATIONS_NUMBER 100
#define PAUSE 10 /* ms */

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
  HANDLE hThreads[THREADS_NUMBER];
  CONST HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

  for(i = 0; i < THREADS_NUMBER; i++) 
    hThreads[i] = CreateThread(NULL, 0, &ThreadProc, hMutex, 0, NULL);
  WaitForMultipleObjects(THREADS_NUMBER, hThreads, TRUE, INFINITE);
  wsprintf(szMessage, TEXT("Expected value = %d\r\n"), 20000);
  WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);
  wsprintf(szMessage, TEXT("Value = %d\r\n"), dwCounter);
  WriteConsole(hStdOut, szMessage, lstrlen(szMessage), &dwTemp, NULL);

  for(i = 0; i < THREADS_NUMBER; i++) {
    CloseHandle(hThreads[i]);
  }
  CloseHandle(hMutex);
  ExitProcess(0);
}
