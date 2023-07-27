"""Export the funtion for python"""
from ctypes import windll
from pathlib import Path
from sys import getwindowsversion
from platform import platform

if getwindowsversion().build < 22000:
    raise OSError("To apply mica effect to the win32 application, please use Windows 11")

env = Path(__file__).parent
plugin = windll.LoadLibrary(str(env / "win32mica.dll"))

class MICATHEME:
	LIGHT = False
	DARK = True

def ApplyMica(hwnd: int, theme: bool = MICATHEME.DARK):
    """Apply mica effect for Win32 Applications"""
    if getwindowsversion().build < 22523:
        plugin.ApplyUndocumentMica(hwnd, theme)
    else:
        plugin.ApplyDocumentMica(hwnd, theme)


# Future idea: Follow system if user change the windows theme
