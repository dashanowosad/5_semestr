#include <windows.h>
#include <process.h>

int WINAPI WinMain(HINSTANCE hlnstance,HINSTANCE nPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	char *argv[] = {"notepad",NULL};
	
	_spawnvp(_P_NOWAIT,argv[0],argv);
	MessageBox(NULL,"Parent process is yet running.","Message", MB_OK);
	return 0;
}
