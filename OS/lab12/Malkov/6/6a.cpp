#include <windows.h>

int main(){
	HANDLE hFileMap;
	LPVOID lpMapView;
	char *buff = "Hellow, students!";
	
	hFileMap = CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,0,256,"MyCommonRegion");
	lpMapView = MapViewOfFile(hFileMap,FILE_MAP_WRITE,0,0,256);
	CopyMemory(lpMapView,buff,sizeof("Hellow, students!"));
	system("PAUSE");
	UnmapViewOfFile(lpMapView);
	CloseHandle(hFileMap);
	return 0;
}
