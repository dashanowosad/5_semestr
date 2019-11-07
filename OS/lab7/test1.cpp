
#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

PIMAGE_SECTION_HEADER GetEnclosingSectionHeader(DWORD rva, PIMAGE_NT_HEADERS
 pNTHeader)
{
PIMAGE_SECTION_HEADER section = IMAGE_FIRST_SECTION(pNTHeader);
for (unsigned i=0; i<pNTHeader->FileHeader.NumberOfSections; i++, section++)
        {
             if ((rva >= section->VirtualAddress) &&
             (rva < (section->VirtualAddress + section->Misc.VirtualSize)))
             return section;
        }
        return 0;
}

void DumpFile(LPSTR filename)
{
    HANDLE hFile;
    HANDLE hFileMapping;
    LPVOID lpFileBase;
    ULONG ulSize;
    PIMAGE_THUNK_DATA thunk;
    PIMAGE_IMPORT_BY_NAME pOrdinalName;
    PIMAGE_DOS_HEADER pDOSHeader;
    PIMAGE_NT_HEADERS pNTHeader;
    PIMAGE_IMPORT_DESCRIPTOR importDesc;
    PIMAGE_SECTION_HEADER pSection;
    //????????? ????
    hFile = CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL,
    		            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE) return;
    //?????????? ???? ? ??????
    hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
        if (!hFileMapping)
        {
                CloseHandle(hFile);
                return;
        }
	   // ????????????? ? ?????????
        lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0);
        if (!lpFileBase)
        {
                CloseHandle(hFileMapping);
                CloseHandle(hFile);
                return;
 }
   printf("Dump of file %s:\n", filename);
   //????????? ?? DOS-?????????
   pDOSHeader = (PIMAGE_DOS_HEADER)lpFileBase;
   if (pDOSHeader->e_magic != IMAGE_DOS_SIGNATURE) return;
   //??????? ????? NT ?????????
   pNTHeader = (PIMAGE_NT_HEADERS)((DWORD)pDOSHeader + pDOSHeader->e_lfanew);
   if (pNTHeader->Signature != IMAGE_NT_SIGNATURE) return;
   //RVA-????? ??????? ???????
   int importsStartRVA = pNTHeader-> OptionalHeader.DataDirectory
[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
   if (!importsStartRVA) return;
   //?????????? ????? ??????
   pSection = GetEnclosingSectionHeader(importsStartRVA, pNTHeader);
   if (!pSection) return;
   int delta = pSection->VirtualAddress - pSection->PointerToRawData;
  
   importDesc = (PIMAGE_IMPORT_DESCRIPTOR) (importsStartRVA - delta +
                (DWORD)lpFileBase);
   //?????????? ?????? dll
   while (importDesc->TimeDateStamp || importDesc->Name)
        {
	 //???????? dll
	 system("Pause");
       printf("%s\n", (PBYTE)(importDesc->Name) - delta + (DWORD)lpFileBase);
	 //RVA-???????? ?? ?????? ?????????? ?? ???????
       thunk = (PIMAGE_THUNK_DATA)importDesc->Characteristics;
       if (!thunk) thunk = (PIMAGE_THUNK_DATA)importDesc->FirstThunk;
      thunk = (PIMAGE_THUNK_DATA)( (PBYTE)thunk - delta + (DWORD)lpFileBase);
	//?????????? ???????
       while (thunk->u1.AddressOfData)
            {
              if (!(thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG))
              {
               pOrdinalName = (PIMAGE_IMPORT_BY_NAME)thunk->u1.AddressOfData;
               pOrdinalName = (PIMAGE_IMPORT_BY_NAME)((PBYTE)pOrdinalName -
delta + (DWORD)lpFileBase);
				//??????? ??? ???????
                        printf("    %s\n", pOrdinalName->Name);
               }
               thunk++;
            }
         importDesc++;
        }
        UnmapViewOfFile(lpFileBase);
        CloseHandle(hFileMapping);
        CloseHandle(hFile);
}

main(int argc, char *argv[])
{
	LPSTR filename = "c:\\Windows\\system32\\notepad.exe ";
      DumpFile( filename );
}

