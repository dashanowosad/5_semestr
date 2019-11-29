#include <windows.h>
#include <stdio.h>
#include <imagehlp.h>
#include <process.h>
/*
IMAGE_SECTION_HEADER * GetExportSection(IMAGE_SECTION_HEADER *pFirstSectionHeader, IMAGE_NT_HEADERS *pNtHdr){
	
	for (int i = 0; i < pNtHdr->FileHeader.NumberOfSections;i++){
		
		//printf("%s\n",&pFirstSectionHeader[i].Name);
		if(pFirstSectionHeader[i].VirtualAddress <= pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress
			&& pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress < (pFirstSectionHeader[i].VirtualAddress + pFirstSectionHeader[i].Misc.VirtualSize))
		//if(&pFirstSectionHeader[i].Name == '.edata')
				return &pFirstSectionHeader[i];
	}

}

*/
HANDLE hFileMapOut;
LPVOID MapViewOut;

void Export(IMAGE_NT_HEADERS *pNtHdr, LPVOID pSrcFile){
	char buff[CHAR_MAX] = {'\0'};
	IMAGE_EXPORT_DIRECTORY* ExpTable;
	char *pName, *sName, **pNames;
	DWORD nNames;
	DWORD RVAExpDir, VAExpAddress;
	int i;

	RVAExpDir = pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	VAExpAddress = (DWORD)ImageRvaToVa(pNtHdr,pSrcFile,RVAExpDir,NULL);
	ExpTable=(IMAGE_EXPORT_DIRECTORY*)VAExpAddress;

	sName=(char*)ImageRvaToVa(pNtHdr,pSrcFile,ExpTable->Name,NULL);
	strcat(buff,"Name of PEF:  ");
	strcat(buff,sName);
	printf("Name of PEF:  %s\n",sName);
	CopyMemory(MapViewOut,buff,CHAR_MAX);
	Sleep(20);
	
	pNames=(char**)ImageRvaToVa(pNtHdr,pSrcFile,ExpTable->AddressOfNames,NULL);
	nNames=ExpTable->NumberOfNames;
	printf("Exported data: \n");
	CopyMemory(MapViewOut,"Exported data: ",CHAR_MAX);
	Sleep(20);
	for(i = 0; i < nNames; i++){
		pName = (char*)ImageRvaToVa(pNtHdr,pSrcFile,(DWORD)*pNames,NULL);
		printf("%s\n",pName);
		CopyMemory(MapViewOut,pName,CHAR_MAX);
		Sleep(20);
		//system("PAUSE");
		*pNames++;
	}
}
void Import(IMAGE_NT_HEADERS *pNtHdr, LPVOID pSrcFile){
	char *pName, *sName, **pNames;
	DWORD nNames;
	DWORD RVAExpDir, VAExpAddress;
	IMAGE_IMPORT_DESCRIPTOR* ImportTable;
	
	RVAExpDir = pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress; //виртуальный адрес
	VAExpAddress = (DWORD)ImageRvaToVa(pNtHdr,pSrcFile,RVAExpDir,NULL);//адрес виртуального массива строк
	ImportTable=(IMAGE_IMPORT_DESCRIPTOR*)VAExpAddress;

	printf("Imported data: \n");
	CopyMemory(MapViewOut,"Imported data: ",CHAR_MAX);
	Sleep(20);
	
	while(ImportTable->Name != NULL){
		pNames=(char**)ImageRvaToVa(pNtHdr,pSrcFile,ImportTable->FirstThunk,NULL);
		sName=(char*)ImageRvaToVa(pNtHdr,pSrcFile,ImportTable->Name,NULL); //названия библиотек dll
		SecureZeroMemory(MapViewOut,CHAR_MAX);
		char buff[CHAR_MAX] = {'\0'};
		printf("Name of PEF:  %s\n",sName);
		strcpy(buff,"Name of PEF:   ");
		strcat(buff,sName);
		CopyMemory(MapViewOut,buff,CHAR_MAX);
		Sleep(20);
		
		//system("Pause");

		while(pName != 0){
			pName = (char*)ImageRvaToVa(pNtHdr,pSrcFile,(DWORD)*pNames+2,NULL);
			if(pName != 0){
				char buff2[CHAR_MAX] = {'\0'};
				strcpy(buff2,"	");
				strcat(buff2,pName);
				printf("     %s\n",pName);
				CopyMemory(MapViewOut,buff2,CHAR_MAX);
				Sleep(20);
  		 	}
			*pNames++;

		}
		*pName++;
		ImportTable++;
	}
}
int main(){
	char buff[10];
	HANDLE hFileMap, hFile;
	LPVOID pSrcFile;
	IMAGE_DOS_HEADER *pDosHeader;
	IMAGE_NT_HEADERS *pNtHdr;
	IMAGE_SECTION_HEADER *pFirstSectionHeader, *pSectionHeader;
	
	hFileMapOut = CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,0,CHAR_MAX,"Lab12");
	MapViewOut = MapViewOfFile(hFileMapOut,FILE_MAP_WRITE,0,0,CHAR_MAX);

	hFile = CreateFile ("c:\\Windows\\System32\\kernel32.dll", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL); //открыли файл
	if (hFile == INVALID_HANDLE_VALUE)
		printf("Could not open file.");
		
	hFileMap = CreateFileMapping (hFile, NULL, PAGE_READONLY, 0, 0, NULL); //создали отображение
	if(hFileMap == NULL)
		printf("Could not create mapping file.");
		
	pSrcFile = (PBYTE) MapViewOfFile(hFileMap,FILE_MAP_READ,0,0,0); //получаем указатель на участок памяти (базовый)
	if(pSrcFile == NULL)
		printf("Could not map file.");


 	pDosHeader = (IMAGE_DOS_HEADER *)pSrcFile; // получили указатель на DOS-заголовок
	pNtHdr = (IMAGE_NT_HEADERS *)((DWORD)pDosHeader + pDosHeader->e_lfanew); // указатель на NT-заголовки

    //pFirstSectionHeader = (IMAGE_SECTION_HEADER *) ((PBYTE)&pNtHdr->OptionalHeader + sizeof(IMAGE_OPTIONAL_HEADER)); // адрес первой секции
	//pSectionHeader = GetExportSection(pFirstSectionHeader,pNtHdr); //нашли секцию экспорта
	
	system("Start  D:\\GitHub\\5_semestr\\OS\\lab12\\Malkov\\lab12\\lab12b.exe");
	Sleep(20);
	Export(pNtHdr,pSrcFile);
	//system("PAUSE");
	Import(pNtHdr,pSrcFile);
	CopyMemory(MapViewOut,"OUT",CHAR_MAX);
	system("PAUSE");

	UnmapViewOfFile(MapViewOut);
	UnmapViewOfFile(hFileMap);
 	CloseHandle(hFileMapOut);
	CloseHandle(hFileMap);
	return 0;
}
