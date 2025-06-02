"""
This script opens a specific web page when a hotkey is pressed. In this case, the web page is GeoGebra Classic in Spanish.

First, import the required modules: keyboard and webbrowser.
If you don't have the module keyboard yet, let's install it with:
pip install keyboard
You don't need to install webbrowser because it is included in Python's standard library.
Then, define the open_page() function to open the web page using webbrowser.open().
Set the hotkey 'ctrl+q' with keyboard.add_hotkey() and assign it to the open_page function.
The script will keep running until the 'Esc' key is pressed, which is handled by keyboard.wait('Esc').
"""
import keyboard
import webbrowser

def open_page():
    webbrowser.open('https://www.geogebra.org/classic?lang=es')

keyboard.add_hotkey('ctrl+q', open_page)
keyboard.wait('Esc')
