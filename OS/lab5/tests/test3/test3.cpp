#include <windows.h>
#include "resource.h"

LRESULT CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	DialogBox(hInstance, (LPCTSTR)IDD_DLGTEST,NULL, (DLGPROC)DlgProc);
	
	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
	char strText[100];
	switch(message){
		case WM_INITDIALOG:
			return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDOK:
					PostQuitMessage(0);
					return TRUE;
				case IDCANCEL:
					PostQuitMessage(0);
					return TRUE;
				case IDC_BTN1:
					GetDlgItemText(hDlg, IDC_EDIT1,strText,100);
					SetDlgItemText(hDlg,IDC_EDIT2, strText);
					SetDlgItemText(hDlg,IDC_EDIT1, "");
					break;
			}
			break;
			default:
				return FALSE;
	}
}
