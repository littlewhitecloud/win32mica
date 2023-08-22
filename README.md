# win32mica
Apply mica effect for win32 applications

### Win32
#### C++
> If you want to run the example, please copy `win32mica.h` `win32mica.lib` `win32mica.dll` here and compile the file
```c++
#include <Windows.h>
#include "win32mica.h" 
#pragma comment(lib, "win32mica.lib")
#pragma comment(lib, "user32.lib")

// true to apply dark mode
// false to apply light mode

// Works for Windows 11 22523+
ApplyDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), ...);
// Works for Windows 11 22523-
// ApplyUnDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), ...);
```

#### Example
```c++
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "win32mica.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "win32mica.lib")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{

    const wchar_t CLASS_NAME[]  = L"Mica Window Class";
    
    WNDCLASS wc = { };

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        WS_EX_LAYERED,
        CLASS_NAME,
        L"Mica Win32 Application",
        WS_OVERLAPPEDWINDOW,

        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL, 
        NULL,
        hInstance,
        NULL
        );

    if (hwnd == NULL)
    {
        return 0;
    }

	SetLayeredWindowAttributes(hwnd, RGB(255, 255, 255), 0, LWA_COLORKEY);
	ApplyDocumentMica(FindWindowW(NULL, L"Mica Win32 Application"), true); 
	
    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/32320336-482b-4752-8a81-987b31367541)

### Other UI
#### Python
```python
# from win32mica import ApplyMica
# ApplyMica(hwnd: int, theme: bol): function
#    hwnd: your window hwnd
#    theme: true -> dark | false -> light
# 
# from win32mica import MICATHEME
# MICATHEME: class
#    LIGHT: bool = False
#    DARK: bool  = True

# Basic usage
import ctypes
ApplyMica(ctypes.windll.user32.FindWindowW(ctypes.c_char_p(None), "{Target Window Name}"), ...);
```

#### Example
```python
from tkinter import Tk
from win32mica import ApplyMica, MICATHEME
from ctypes import windll, c_char_p

example = Tk() # Create a Tk window
example.geometry("1165x605") # Set the size of the window
example.title("Mica Example") # Set the title of the window
# Without this line, the FindWindowW can't find the hwnd correctly
example.iconbitmap("") # Set the icon of the window

example["background"] = "black" # Add this line if you want the full mica effect(Also light mode)
ApplyMica(windll.user32.FindWindowW(c_char_p(None), "Mica Example"), MICATHEME.DARK) # Use False or MICATHEME.LIGHT to apply light mica effect

example.mainloop() # Window mainloop
```

![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/fd519b6e-3ff3-4423-a987-079b2d2d4213)
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/0a784df0-bf5d-4cf4-b6d1-cd170a396753)


