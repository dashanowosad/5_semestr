#include <windows.h>
#include <stdio.h>

int main(){
	HANDLE hFileMap;
	LPVOID lpMapView;
	char buff[80];

	hFileMap = OpenFileMapping(FILE_MAP_READ,TRUE,"MyCommonRegion");
	lpMapView = MapViewOfFile(hFileMap,FILE_MAP_READ,0,0,256);
	CopyMemory(buff,lpMapView,80);
	printf("%s\n",buff);
	UnmapViewOfFile(lpMapView);
	CloseHandle(hFileMap);
	return 0;
}
