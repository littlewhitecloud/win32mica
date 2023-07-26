# win32mica
Apply mica effect for win32 applications

### Python
```python
# from win32mica import ApplyMica
# ApplyMica(hwnd: int, theme: bool)
#    hwnd: your window hwnd
#    theme: true -> dark | false -> light
# 
# from win32mica import MICATHEME
# MICATHEME: class
#    LIGHT: bool = 0
#    DARK: bool  = 1


# A small example
from tkinter import Tk
from win32mica import ApplyMica, MICATHEME
from ctypes import windll, c_char_p

example = Tk() # Create a Tk window
example.geometry("1165x605") # Set the size of the window
example.title("Mica Example") # Set the title of the window
# Without this line, the FindWindowW can't find the hwnd correctly
example.iconbitmap("") # Set the icon of the window

example["background"] = "black" # Add this line if you want the full mica effect
ApplyMica(windll.user32.FindWindowW(c_char_p(None), "Mica Example"), MICATHEME.DARK) # Use False to apply light mica effect

example.mainloop() # Window mainloop
```

### C / C++
```c++
#include <Windows.h>
#include "plugin.h" 
#pragma comment(lib, "plugin.lib")
#pragma comment(lib, "user32.lib")

ApplyDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), ...); // Works for Windows 11 22523+
ApplyUnDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), ...); // Works for Windows 11 22523-
```

### View
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/fd519b6e-3ff3-4423-a987-079b2d2d4213)
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/359c2063-c5d2-4ec2-8a7a-c99c6ac301a5)
