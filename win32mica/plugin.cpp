#include <Windows.h>
#include <dwmapi.h>
#pragma comment(lib, "Dwmapi.lib")

__declspec(dllexport) void ApplyDocumentMica(HWND hwnd, bool theme) {
	/* Apply mica for win32 applications */
	MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 38, mica_value = 0x02; // Windows 11 23523+
	DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &theme, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));
}

__declspec(dllexport) void ApplyUndocumentMica(HWND hwnd, bool theme) {
	/* Apply mica for win32 applications */
	MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 1029, mica_value = 0x01; // Windows 11 23523-
	DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &theme, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));	
}
