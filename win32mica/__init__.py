from ctypes import windll
from pathlib import Path
from sys import getwindowsversion

env = Path(__file__).parent
plugin = windll.LoadLibrary(str(env / "plugin.dll"))

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
