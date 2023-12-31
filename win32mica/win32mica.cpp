// win32mica.cpp - Apply mica for win32 applications
#include <Windows.h>
#include <dwmapi.h>
#include "win32mica.h"

#pragma comment(lib, "Dwmapi.lib")

void ApplyDocumentMica(HWND hwnd, bool theme, bool micaalt) {
	MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 38, mica_value = 0x00; // Windows 11 23523+

    mica_value = micaalt ? 0x04 : 0x02;

    DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &theme, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));
}

void ApplyUndocumentMica(HWND hwnd, bool theme, bool micaalt)
{
    MARGINS margins = {-1, -1, -1, -1};
	int mica_entry = 1029, mica_value = 0x01; // Windows 11 23523-

    mica_value = micaalt ? 0x04 : 0x01;

    DwmExtendFrameIntoClientArea(hwnd, &margins);
	DwmSetWindowAttribute(hwnd, 20, &theme, sizeof(int));
	DwmSetWindowAttribute(hwnd, mica_entry, &mica_value, sizeof(int));
}
