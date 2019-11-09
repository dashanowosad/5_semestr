#include <windows.h>
#include <imagehlp.h>
#include <stdio.h>

//kernel32.dll и c:\\Windows\\system32\\notepad.exe     D:\\OS\\lab7\\lab7a\\Prog1 with DLL\\MyDll\\Release\\MyDll.dll

int main(void){
	PCSTR ImageName;
	LOADED_IMAGE LoadedImage;
	PUCHAR BaseAddress;
	DWORD RVAExpDir, VAExpAddress;
	IMAGE_IMPORT_DESCRIPTOR* ImportTable;
	IMAGE_IMPORT_BY_NAME* Names;
	PIMAGE_THUNK_DATA thunk;
	PIMAGE_SECTION_HEADER pSection;
	char *sName;
	DWORD nNames;
	char *pName;
	char **pNames;
	DWORD i;
	LPVOID DLLName;
	if (!MapAndLoad("c:\\Windows\\system32\\notepad.exe ",NULL,&LoadedImage,FALSE,TRUE)){
		printf("Somthing`s wrong!\n");
		exit(1);
	}
	BaseAddress = LoadedImage.MappedAddress;
	printf("0x%d = Base Adress\n",BaseAddress);


	RVAExpDir = LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress; //виртуальный адрес
	printf("0x%lx - RVA\n",RVAExpDir);


	VAExpAddress = (DWORD)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,RVAExpDir,NULL);//адрес виртуального массива строк
	printf("0x%lx - VA\n",VAExpAddress);
	ImportTable=(IMAGE_IMPORT_DESCRIPTOR*)VAExpAddress;

	printf("Imported data: \n");

	while(ImportTable->Name != NULL){
		pNames=(char**)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,ImportTable->FirstThunk,NULL);
		sName=(char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,ImportTable->Name,NULL); //названия библиотек dll
		printf("Name of PEF:  %s\n",sName);
		while(pName != 0){
			pName = (char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,(DWORD)*pNames+2,NULL);
			if(pName != 0) 
				printf("     %s\n",pName);
			*pNames++;
		}
		*pName++;
		ImportTable++;
	}
	UnMapAndLoad(&LoadedImage);
	return 0;
}
