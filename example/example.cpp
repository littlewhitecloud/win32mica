#include <Windows.h>
#include "win32mica.h" 
#pragma comment(lib, "win32mica.lib")
#pragma comment(lib, "user32.lib")

int main() {
	ApplyDocumentMica(FindWindowW(NULL, L"Mica Example"), true);
	return 0;
} 
