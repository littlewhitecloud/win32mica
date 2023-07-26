#pragma once
#include <Windows.h>

#ifdef APPLYMICA_EXPORTS
#define APPLYMICA_API __declspec(dllexport)
#else
#define APPLYMICA_API __declspec(dllimport)
#endif

extern "C" APPLYMICA_API void ApplyDocumentMica(HWND hwnd, bool theme);
extern "C" APPLYMICA_API void ApplyUndocumentMica(HWND hwnd, bool theme);
