#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrvInstance, LPSTR lpCmdLine, int nCmdShow){
	HWND hWnd;
	MSG msg;
	WNDCLASS wc;
	LPCSTR lpszAppName = "CTemplate1";
	BOOL ret;

	//������������ ������ ����
	wc.lpszClassName = lpszAppName;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC)MyWndProc;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = 0;
	//LoadIcon(hInstance, (LPCTSTR)IDI_CTEMPLATE);
	wc.lpszMenuName = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	if(!RegisterClass(&wc))
		return 0;

	hWnd = CreateWindow(lpszAppName, lpszAppName, WS_OVERLAPPEDWINDOW, 100,100,400,200,NULL,NULL,hInstance,NULL);
	ret = RegisterHotKey(hWnd,0xB001,MOD_CONTROL | MOD_ALT, 'W');
	ShowWindow(hWnd,SW_HIDE);
	UpdateWindow(hWnd);
	while (GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//��������� ����
LRESULT CALLBACK MyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	switch(message){
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		}

		case WM_HOTKEY:{
			ShowWindow(hWnd,SW_SHOWNORMAL);
			break;
		}
		case WM_PAINT:{
			hdc = BeginPaint(hWnd,&ps);
			GetClientRect(hWnd,&rt);
			DrawText(hdc,"From Paint",strlen("From Paint"), &rt, DT_CENTER);
			EndPaint(hWnd,&ps);
			break;
		}
		case WM_COPYDATA:{
			GetClientRect(hWnd, &rt);
			hdc = GetDC(hWnd);

			DrawText(hdc, (char*)(((COPYDATASTRUCT*)lParam)->lpData), ((COPYDATASTRUCT*)lParam)->cbData, &rt, DT_LEFT);
			ReleaseDC(hWnd,hdc);

			break;
		}

		default:
			return DefWindowProc(hWnd,message, wParam, lParam);
	}
}


/*typedef struct{
	HWND hwnd;
	UINT message;
	WPARAM wParam;
	LPARAM LParam;
	DWORD time;
	POINT pt;
} MSG;

typedef struct {
	ULONG_PTR dwData;
	DWORD cbData;
	PVOID lpData;
} COPYDATASTRUCT;*/
