import tkinter as tk
from tkinter import ttk

class PaintApp:
    def __init__(self, root : tk.Tk) -> None:
        self.root = root
        self.canvas_width = 800
        self.canvas_height = 600
        self.canvas = tk.Canvas(self.root, 
                                width=self.canvas_width, 
                                height=self.canvas_height,
                                bg='white',
                                bd=3,
                                relief=tk.SUNKEN)
        self.canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)    
    
        self.setup_tools()
        self.setup_events()

        self.prev_x = None
        self.prev_y = None

    # Supose we want to create a pen and a eraser
    def setup_tools(self):
        self.brush_sizes = [2, 4, 6, 8]
        self.selected_size = self.brush_sizes[1]

        self.tool_frame = tk.LabelFrame(self.root, text='Tools')
        self.tool_frame.pack(side=tk.RIGHT,
                             padx=5,
                             pady=5,
                             fill=tk.Y)

        self.brush_sizes_label = ttk.Label(self.tool_frame, text='Brush Sizes: ')
        self.brush_sizes_label.pack(side=tk.TOP, padx=5, pady=5)

        self.brush_size_combobox = ttk.Combobox(self.tool_frame, 
                                                values=self.brush_sizes, 
                                                state='readonly')
        self.brush_size_combobox.current(0)
        self.brush_size_combobox.pack(side=tk.TOP, padx=5, pady=5)
        self.brush_size_combobox.bind('<<ComboboxSelected>>',
                                      lambda event: self.select_size(int(self.brush_size_combobox.get())))

        # self.rectangle_button = ttk.Button(self.tool_frame,
        #                                    text='Rectangle',
        #                                    command=self.draw_square)
        # self.rectangle_button.pack(side=tk.TOP, padx=5, pady=5)

        self.clear_button = ttk.Button(self.tool_frame, text="Clear Canvas", command=self.clear_canvas)
        self.clear_button.pack(side=tk.TOP, padx=5, pady=5)

    def setup_events(self):
        self.canvas.bind('<B1-Motion>', self.draw)
        self.canvas.bind('<ButtonRelease-1>', self.release)

    def draw(self, event : tk.Event):
        if self.prev_x is not None and self.prev_y is not None:
            self.canvas.create_line(self.prev_x,
                                    self.prev_y,
                                    event.x,
                                    event.y,
                                    fill='black',
                                    width=self.selected_size,
                                    smooth=True)
            
        self.prev_x = event.x
        self.prev_y = event.y

    def select_size(self, size):
        self.selected_size = size

    def release(self, event : tk.Event):
        self.prev_x = None
        self.prev_y = None

    def clear_canvas(self):
        self.canvas.delete('all')
    

if __name__ == '__main__':
    root = tk.Tk()
    root.title("Simpler Paint")
    app = PaintApp(root)
    root.mainloop()