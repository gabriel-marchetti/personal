from tkinter import *
from tkinter import ttk

if __name__ == 'main':
    root = Tk()
    root.title("Temperature Visualizer")

    mainframe = ttk.Frame(root, padding='3 3 12 12')
    mainframe.grid(column=0, row=0, sticky=(N, W, E, S))
    root.columnconfigure(0, weight=0)
    root.rowconfigure(0, weight=0)

    