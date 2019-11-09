#include <windows.h>
#include <imagehlp.h>
#include <stdio.h>

//kernel32.dll è c:\\Windows\\system32\\notepad.exe     D:\\OS\\lab7\\lab7a\\Prog1 with DLL\\MyDll\\Release\\MyDll.dll

int main(void){
	LOADED_IMAGE LoadedImage;
	PUCHAR BaseAddress;
	DWORD RVAExpDir, VAExpAddress;
	IMAGE_EXPORT_DIRECTORY* ExpTable;
	char *sName;
	DWORD nNames;
	char *pName;
	char **pNames;
	DWORD i;
	if (!MapAndLoad("kernel32.dll",NULL,&LoadedImage,TRUE,TRUE)){
		printf("Somthing`s wrong!\n");
		exit(1);
	}
	BaseAddress = LoadedImage.MappedAddress;
	printf("0x%d = Base Adress\n",BaseAddress);


	RVAExpDir = LoadedImage.FileHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	printf("0x%lx - RVA\n",RVAExpDir);

	VAExpAddress = (DWORD)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,RVAExpDir,NULL);
	printf("0x%lx - VA\n",VAExpAddress);
	ExpTable=(IMAGE_EXPORT_DIRECTORY*)VAExpAddress;

	sName=(char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,ExpTable->Name,NULL);
	printf("Name of PEF:  %s\n",sName);

 	pNames=(char**)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,ExpTable->AddressOfNames,NULL);
	nNames=ExpTable->NumberOfNames;
	printf("Exported data: \n");

	for(i = 0; i < nNames; i++){
		pName = (char*)ImageRvaToVa(LoadedImage.FileHeader,BaseAddress,(DWORD)*pNames,NULL);
		printf("%s\n",pName);
		*pNames++;
	}
	UnMapAndLoad(&LoadedImage);
	return 0;
}
