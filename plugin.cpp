#include <Windows.h>
#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")
 
__declspec(dllexport) void ApplyDocumentMica(HWND hwnd, bool mode = true) {
	/* Apply mica for win32 applications */
	MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 38, mica_value = 0x02;
	DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &mode, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));
}

__declspec(dllexport) void ApplyUndocumentMica(HWND hwnd, bool theme = true) {
	/* Apply mica for win32 applications */
	MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 1029, mica_value = 0x01, mode;
	DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &mode, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));	
	
} 
