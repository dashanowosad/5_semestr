#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define ID_EDIT 100
#define ID_BUTTON 101
#define MYDISPLAY 1


TCHAR buf[256];
HINSTANCE hInst;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//void WINAPI MyDisplay( LPSTR, LPSTR, DWORD );

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	HWND hWnd;
	static TCHAR szWindowsClass[] = _T("Client");
	
 	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szWindowsClass;
	
	
	if(!RegisterClass(&wc))
		return 0;

 hWnd = CreateWindow(szWindowsClass,
						szWindowsClass,
						WS_OVERLAPPEDWINDOW,
						100,
						100,
						400,
						300,
						NULL,
						NULL,
						hInstance,
						NULL);
						
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);	
	
	////////////////////
	
	MSG message;
	
	while(GetMessage(&message,NULL,0,0)){
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
		
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	static HWND hEdit, hButton;
	LPSTR k;
	PCOPYDATASTRUCT data;
	
	switch(message){
		case WM_CREATE:
			hEdit = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 30, 80, 300, 35, hWnd, (HMENU)ID_EDIT, hInst, 0);
			hButton = CreateWindow(("Button"), ("Clear"), WS_CHILD | WS_VISIBLE  | BS_PUSHBUTTON, 150, 150, 50, 35, hWnd, (HMENU)ID_BUTTON, hInst, 0);
			break;
		case WM_COPYDATA:
			buf[0] = 0;
			SetWindowText(hEdit, buf);
			data = (PCOPYDATASTRUCT) lParam;
			k = (LPSTR) (data->lpData);
            strcat(buf, TEXT(k));
            SetWindowText(hEdit, buf);
  			break;
		case WM_DESTROY:
      		PostQuitMessage(0);
      		break;
	   case WM_COMMAND:
			if((LOWORD(wParam)==ID_BUTTON)&&(HIWORD(wParam)==BN_CLICKED))
            {
			    buf[0] = 0;
				SetWindowText(hEdit, buf);
            }
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
			break;
	}
	return 0;
}
