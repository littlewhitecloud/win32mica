// win32mica.h - Define the functions that need to be exported
#pragma once
#include <Windows.h>

#ifdef APPLYMICA_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

extern "C" {
    DLLEXPORT void ApplyDocumentMica(HWND hwnd, bool theme, bool micaalt);
    DLLEXPORT void ApplyUndocumentMica(HWND hwnd, bool theme, bool micaalt);
}