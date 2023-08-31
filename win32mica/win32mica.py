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


class MICAMODE:
    DEFAULT: bool = False
    ALT: bool = True


def ApplyMica(hwnd: int = 0, theme: bool = True, micaalt: bool = True) -> None:
    """Apply mica effect for Win32 Applications
    Args:
        hwnd(int): The target window's hwnd
        theme(bool):
            false -> light
            true -> dark
        micaalt(bool):
            false -> default
            true -> alt
    """
    if getwindowsversion().build < 22523:  # Mica isn't a public api
        plugin.ApplyUndocumentMica(hwnd, theme, micaalt)
    else:
        plugin.ApplyDocumentMica(hwnd, theme, micaalt)


# Future idea: Follow system if user change the windows theme
