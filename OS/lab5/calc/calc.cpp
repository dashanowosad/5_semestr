#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS

//#pragma(lib, "gdi32)

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include "RPN.h"

#define ID_EDIT 100
#define ID_BUTTON_0 101
#define ID_BUTTON_1 103
#define ID_BUTTON_2 104
#define ID_BUTTON_3 105
#define ID_BUTTON_4 106
#define ID_BUTTON_5 107
#define ID_BUTTON_6 108
#define ID_BUTTON_7 109
#define ID_BUTTON_8 110
#define ID_BUTTON_9 111
#define ID_BUTTON_C 112
#define ID_BUTTON_MUL 113
#define ID_BUTTON_SUB 114
#define ID_BUTTON_DIV 115
#define ID_BUTTON_ADD 116
#define ID_BUTTON_RES 117

HINSTANCE hInst;
TCHAR buf[256];

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int CALLBACK WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow){
	static TCHAR szWindowsClass[] = _T("DesktopApp");
	static TCHAR szTitle[] = _T("Калькулятор");
	
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_WINLOGO);
	wcex.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName  = szWindowsClass;
	wcex.hIconSm = LoadIcon(hInstance, IDI_WINLOGO);
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,
		_T("Call to RegisterClassEx failed!"),
		_T("Windows Desktop Guided Tour"),
		0);
		return 1;
	}
	hInst = hInstance;
	HWND hWnd = CreateWindow(
    szWindowsClass,
    szTitle,
    WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT,
    500, 500,
    NULL,
    NULL,
    hInstance,
    NULL
	);

   if (!hWnd){
      MessageBox(NULL,
         _T("Call to CreateWindow failed!"),
         _T("Windows Desktop Guided Tour"),
         0);

      return 1;
   }
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   // Main message loop:
   MSG msg;
   while (GetMessage(&msg, NULL, 0, 0)){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return (int) msg.wParam;
}
	


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   static HWND hButtons[16], hEdit, hListBox;
   PAINTSTRUCT ps;
   HDC hdc;

   switch (message)
   {
   	case WM_CREATE:
   			hEdit = CreateWindow(_T("edit"), _T("0"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 80, 80, 400, 35, hWnd, (HMENU)ID_EDIT, hInst, 0);
            hButtons[0] = CreateWindow (_T("Button"), _T("0"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  10, 400, 300, 50, hWnd, (HMENU)ID_BUTTON_0, hInst, 0);
            hButtons[1] = CreateWindow (_T("Button"), _T("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  10, 320, 90, 70, hWnd, (HMENU)ID_BUTTON_1, hInst, 0);
            hButtons[2] = CreateWindow (_T("Button"), _T("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  115, 320, 90, 70, hWnd, (HMENU)ID_BUTTON_2, hInst, 0);
            hButtons[3] = CreateWindow (_T("Button"), _T("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  215, 320, 90, 70, hWnd, (HMENU)ID_BUTTON_3, hInst, 0);
            hButtons[4] = CreateWindow (_T("Button"), _T("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  10, 240, 90, 70, hWnd, (HMENU)ID_BUTTON_4, hInst, 0);
            hButtons[5] = CreateWindow (_T("Button"), _T("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  115, 240, 90, 70, hWnd, (HMENU)ID_BUTTON_5, hInst, 0);
            hButtons[6] = CreateWindow (_T("Button"), _T("6"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  215, 240, 90, 70, hWnd, (HMENU)ID_BUTTON_6, hInst, 0);
            hButtons[7] = CreateWindow (_T("Button"), _T("7"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  10, 160, 90, 70, hWnd, (HMENU)ID_BUTTON_7, hInst, 0);
            hButtons[8] = CreateWindow (_T("Button"), _T("8"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  115, 160, 90, 70, hWnd, (HMENU)ID_BUTTON_8, hInst, 0);
            hButtons[9] = CreateWindow (_T("Button"), _T("9"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  215, 160, 90, 70, hWnd, (HMENU)ID_BUTTON_9, hInst, 0);
            hButtons[10] = CreateWindow (_T("Button"), _T("+"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  320, 240, 65, 70, hWnd, (HMENU)ID_BUTTON_ADD, hInst, 0);
            hButtons[11] = CreateWindow (_T("Button"), _T("-"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  400, 240, 65, 70, hWnd, (HMENU)ID_BUTTON_SUB, hInst, 0);
            hButtons[12] = CreateWindow (_T("Button"), _T("*"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  320, 320, 65, 70, hWnd, (HMENU)ID_BUTTON_MUL, hInst, 0);
            hButtons[13] = CreateWindow (_T("Button"), _T("/"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  400, 320, 65, 70, hWnd, (HMENU)ID_BUTTON_DIV, hInst, 0);
            hButtons[14] = CreateWindow (_T("Button"), _T("="), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  320, 400, 150, 50, hWnd, (HMENU)ID_BUTTON_RES, hInst, 0);
            hButtons[15] = CreateWindow (_T("Button"), _T("C"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  320, 180, 150, 50, hWnd, (HMENU)ID_BUTTON_C, hInst, 0);
            break;
   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   
   case WM_COMMAND:
      if((LOWORD(wParam)==ID_BUTTON_0)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("0"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_1)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("1"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_2)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("2"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_3)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("3"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_4)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("4"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_5)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("5"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_6)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("6"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_7)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("7"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_8)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("8"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_9)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("9"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_DIV)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("/"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_MUL)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("*"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_ADD)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("+"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_SUB)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                if(*buf == TEXT('0') && 0 == buf[1]) *buf = 0;
                strcat(buf, TEXT("-"));
                SetWindowText(hEdit, buf);
            }
      if((LOWORD(wParam)==ID_BUTTON_C)&&(HIWORD(wParam)==BN_CLICKED))
            {
                buf[0] = 0;
				SetWindowText(hEdit, buf);
                
            }
      if((LOWORD(wParam)==ID_BUTTON_RES)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit, buf, sizeof(buf));
                SetWindowText(hEdit, Calculate(buf));
            }
    
   
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
      break;
   }

   return 0;
}
