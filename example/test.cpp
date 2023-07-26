#include <Windows.h>
#include "plugin.h" 
#pragma comment(lib, "plugin.lib")
#pragma comment(lib, "user32.lib")

int main() {
	ApplyDocumentMica(FindWindowW(NULL, L"Mica Example"), true);
	return 0;
} 
