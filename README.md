# win32mica
Apply mica effect for win32 applications

### Python
#### Usage
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
# MICAMODE: class
#    DEFAULT: bool = False
#    ALT: bool = True

import ctypes
ApplyMica(ctypes.windll.user32.FindWindowW(ctypes.c_char_p(None), "{Target Window Name}"), MICATHEME, MICAMODE);
```

### Example
```python
from tkinter import Tk
from win32mica import ApplyMica, MICATHEME, MICAMODE
from ctypes import windll, c_char_p

example = Tk() # Create a Tk window
example.geometry("1165x605") # Set the size of the window
example.title("Mica Example") # Set the title of the window
# Without this line, the FindWindowW can't find the hwnd correctly
example.iconbitmap("") # Set the icon of the window

example["background"] = "black" # Add this line if you want the full mica effect(Also light mode)
ApplyMica(windll.user32.FindWindowW(c_char_p(None), "Mica Example"), MICATHEME.DARK, MICAMODE.ALT)
# Use False or MICATHEME.LIGHT to apply light mica effect
# USe False or MICAMODE.DEFAULT to apply mica effect, not mica alt

example.mainloop() # Window mainloop
```

### C++
> If you want to run the example, please copy `win32mica.h` `win32mica.lib` `win32mica.dll` here and compile the file

#### Usage
```c++
#include <Windows.h>
#include "win32mica.h" 
#pragma comment(lib, "win32mica.lib")
#pragma comment(lib, "user32.lib")

// true to apply dark mode
// false to apply light mode

// Works for Windows 11 22523+
ApplyDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), MICATHEME, MICAMODE);
// Works for Windows 11 22523-
// ApplyUnDocumentMica(FindWindowW(NULL, L"{Target Window Name}"), MICATHEME, MICAMODE);
```

### Light mode
#### Mica
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/025d49b7-35fc-40c4-ba25-56bf593b166f)
#### Mica Alt
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/aeb58144-de5c-48d5-b9e3-eff94830d249)
### Dark mode
#### Mica
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/839aa12f-9159-46d2-a963-4816b5601ef0)
#### Mica Alt
![image](https://github.com/littlewhitecloud/win32mica/assets/71159641/e8c19471-b91f-466d-8ef5-ebfa5c47fb17)