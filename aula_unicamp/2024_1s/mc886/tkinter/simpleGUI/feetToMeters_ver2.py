from tkinter import *
from tkinter import ttk

class FeetToMeters:
    def __init__( self, root : Tk ):
        root.Title("Feet to Meters Converter")

        mainframe = ttk.Frame(root, padding='3 3 12 12')
        mainframe.grid( column=0, row=0, sticky=(N, W, E, S) )
        root.columnconfigure(0, weight=1)
        root.rowconfigure(0, weight=1)

        