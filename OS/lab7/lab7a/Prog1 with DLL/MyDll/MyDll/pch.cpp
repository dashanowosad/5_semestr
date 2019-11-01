// pch.cpp: файл исходного кода, соответствующий предварительно скомпилированному заголовочному файлу

#include "pch.h"
#include <Windows.h>

extern "C" {
	
_declspec(dllexport)
UINT Sum(UINT a, UINT b) {
	UINT c;
	c = a + b;
	return c;
}
_declspec(dllexport)
UINT Res(UINT a, UINT b) {
	UINT c;
	c = a - b;
	return c;
}

_declspec(dllexport)
UINT Mul(UINT a, UINT b) {
	UINT c;
	c = a * b;
	return c;
}

_declspec(dllexport)
UINT Del(UINT a, UINT b) {
	float c;
	c = a / b;
	return c;
}
}

// При использовании предварительно скомпилированных заголовочных файлов необходим следующий файл исходного кода для выполнения сборки.
