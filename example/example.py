# from win32mica import ApplyMica
# ApplyMica(hwnd: int, theme: bool)
#    hwnd: your window hwnd
#    theme: true -> dark | false -> light
# 
# from win32mica import MICATHEME
# MICATHEME: class
#    LIGHT: bool = 0
#    DARK: bool  = 1


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
