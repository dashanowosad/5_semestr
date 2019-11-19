#include <windows.h>
#include <process.h>
#include <stdio.h>

HANDLE hMutex1, hMutex2;
double sh1 = 0.0;
int sh2 = 0;
void Thread(void* pParams);

int main(void){
  hMutex1 = CreateMutex(NULL, FALSE, NULL);
  hMutex2 = CreateMutex(NULL, FALSE, NULL);

  _beginthread(Thread, 0, NULL);

  while(1){
    WaitForSingleObject(hMutex1, INFINITE); //capture
      printf("%g\n", sh1);
    WaitForSingleObject(hMutex2, INFINITE); //capture
      printf("%d\n", sh2);
    ReleaseMutex(hMutex1); //release
    ReleaseMutex(hMutex2); //release
  }
  return 0;
}


void Thread(void* pParams){
  while (1) {
    WaitForSingleObject(hMutex1, INFINITE); //mutex capture
      sh1 += 0.1;
    WaitForSingleObject(hMutex2, INFINITE); //mutex capture
      sh2 += 1;
    ReleaseMutex(hMutex1); //mutex release
    ReleaseMutex(hMutex2); //mutex release
  }
}
