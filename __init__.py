from ctypes import windll
from pathlib import Path
from sys import getwindowsversion

env = Path(__file__).parent
plugin = windll.LoadLibrary(str(env / "plugin.dll"))

def ApplyMica(hwnd: int, theme: bool):
	if getwindowsversion().build < 22523:
		plugin.ApplyUndocumentMica(hwnd, theme)
	else:
		plugin.ApplyDocumentMica(hwnd, theme)
