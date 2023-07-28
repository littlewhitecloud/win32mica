"""Export the funtion to python"""
from ctypes import windll
from pathlib import Path
from sys import getwindowsversion

if getwindowsversion().build < 22000:
    raise OSError("Use Windows 11 to apply mica effect to the win32 application")

plugin = windll.LoadLibrary(str(Path(__file__).parent / "win32mica.dll"))

class MICATHEME:
	LIGHT: bool = False
	DARK: bool = True
		
def ApplyMica(hwnd: int, theme: bool) -> None:
    """Apply mica effect for Win32 Applications
    Args:
        hwnd(int): The target window's hwnd
        theme(bool):
            false -> light
            true -> dark
    """
    if getwindowsversion().build < 22523: # Mica isn't a public api
        plugin.ApplyUndocumentMica(hwnd, theme)
    else:
        plugin.ApplyDocumentMica(hwnd, theme)


# Future idea: Follow system if user change the windows theme
