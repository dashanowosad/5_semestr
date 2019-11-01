#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define ID_LINE1 100
#define ID_LINE2 101
#define ID_LINE3 102
#define ID_LINE4 103
#define ID_LINE5 104
#define ID_LINE6 105
#define ID_LINE7 106
#define ID_EDIT1 107
#define ID_EDIT2 108
#define ID_EDIT3 109
#define ID_EDIT4 110
#define ID_EDIT5 111
#define ID_EDIT6 112
#define ID_BUTTON 113
#define ID_BUTTON_DEL 114

#define MYDISPLAY 1


TCHAR buf[256];
HINSTANCE hInst;
HMODULE hLib;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	HWND hWnd;
	static TCHAR szWindowsClass[] = _T("Form");
	
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
						500,
						350,
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

	static HWND hLine[7], hEdit[6], hButton, hButtonDel;
	int x,y,c;
	switch(message){
		case WM_CREATE:
			hLine[0] = CreateWindow(("static"), ("X:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 70, 50, 30, 25, hWnd, (HMENU)ID_LINE1, hInst, 0);
			hLine[1] = CreateWindow(("static"), ("Y:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 240, 50, 30, 25, hWnd, (HMENU)ID_LINE2, hInst, 0);
			hLine[2] = CreateWindow(("static"), ("X+Y:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 70, 180, 40, 25, hWnd, (HMENU)ID_LINE3, hInst, 0);
			hLine[3] = CreateWindow(("static"), ("X-Y:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 240, 180, 40, 25, hWnd, (HMENU)ID_LINE4, hInst, 0);
			hLine[4] = CreateWindow(("static"), ("X*Y:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 70, 220, 40, 25, hWnd, (HMENU)ID_LINE5, hInst, 0);
			hLine[5] = CreateWindow(("static"), ("X/Y:"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 240, 220, 40, 25, hWnd, (HMENU)ID_LINE6, hInst, 0);
			hLine[6] = CreateWindow(("static"), ("Данные"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER, 0, 90, 500, 25, hWnd, (HMENU)ID_LINE7, hInst, 0);
			
			hEdit[0] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 115, 50, 100, 25, hWnd, (HMENU)ID_EDIT1, hInst, 0);
			hEdit[1] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 285, 50, 100, 25, hWnd, (HMENU)ID_EDIT2, hInst, 0);
			hEdit[2] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 115, 180, 100, 25, hWnd, (HMENU)ID_EDIT3, hInst, 0);
			hEdit[3] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 285, 180, 100, 25, hWnd, (HMENU)ID_EDIT4, hInst, 0);
			hEdit[4] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 115, 220, 100, 25, hWnd, (HMENU)ID_EDIT5, hInst, 0);
			hEdit[5] = CreateWindow(("edit"), (""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 285, 220, 100, 25, hWnd, (HMENU)ID_EDIT6, hInst, 0);

			hButton = CreateWindow(("button"), ("Рассчитать"), WS_CHILD | WS_VISIBLE  | ES_CENTER, 200, 130, 100, 25, hWnd, (HMENU)ID_BUTTON, hInst, 0);
			hButtonDel = CreateWindow(("button"), ("Выгрузить DLL"), WS_CHILD | WS_VISIBLE  | ES_CENTER, 195, 250, 110, 25, hWnd, (HMENU)ID_BUTTON_DEL, hInst, 0);
			break;
		
		case WM_DESTROY:
      		PostQuitMessage(0);
      		break;
	   case WM_COMMAND:
	   	if((LOWORD(wParam)==ID_BUTTON)&&(HIWORD(wParam)==BN_CLICKED))
            {
                GetWindowText(hEdit[0], buf, sizeof(buf));
                x = atoi(buf);
                buf[0] = 0;
                GetWindowText(hEdit[1], buf, sizeof(buf));
                y = atoi(buf);
				buf[0] = 0;
    	    
			    typedef UINT(*MYFUNC)(UINT,UINT);
				hLib = LoadLibrary("MyDLL\\Release\\MyDll.dll");
			
				if (hLib == NULL){
					MessageBox(hWnd,"Не могу загрузить DLL!", "Error", NULL);
					break;
				}
			//Сумма
				MYFUNC summa = (MYFUNC)GetProcAddress(hLib,"Sum");
				c = summa(x,y);
				SetDlgItemInt(hWnd,ID_EDIT3,c,FALSE);
			//Разность
				MYFUNC sub = (MYFUNC)GetProcAddress(hLib,"Res");
				c = sub(x,y);
				itoa(c,buf,10);
				SetWindowText(hEdit[3], buf);
				buf[0] = 0;
			//Произведение
				MYFUNC mul = (MYFUNC)GetProcAddress(hLib,"Mul");
				c = mul(x,y);
				SetDlgItemInt(hWnd,ID_EDIT5,c,FALSE);
			//Деление (на цело)
				MYFUNC del = (MYFUNC)GetProcAddress(hLib,"Del");
				c = del(x,y);
  			
				SetDlgItemInt(hWnd,ID_EDIT6,c,FALSE);
			
			//FreeLibrary(hLib);
        }
		if((LOWORD(wParam)==ID_BUTTON_DEL)&&(HIWORD(wParam)==BN_CLICKED)) {
    		FreeLibrary(hLib);
		}
        
			break;
		
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
			break;
	}
	return 0;
}
