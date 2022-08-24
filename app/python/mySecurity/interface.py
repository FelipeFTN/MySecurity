from tkinter import *

WIDTH = 300
HEIGHT = 250


class mySecurity(Frame):
    def __init__(self):
        Frame.__init__(self)

        SCREEN_WIDTH = self.master.winfo_screenwidth()
        SCREEN_HEIGHT = self.master.winfo_screenheight()
        POSITION_X = int(SCREEN_WIDTH/2 - WIDTH/2)
        POSITION_Y = int(SCREEN_HEIGHT/2 - HEIGHT/2)

        self.pack()

        self.master.title("MySecurity")
        self.master.geometry(f"{WIDTH}x{HEIGHT}+{POSITION_X}+{POSITION_Y}")
        self.master.resizable(False, False)
        # self.master.iconbitmap("mySecurity.ico")

        self.label0 = Label(self, text="MySecurity", width=25)
        self.label0.pack()

        self.input0 = Text(self, width=15, height=1)
        self.input0.pack()

        self.button0 = Button(self, text="Authenticate")
        self.button0.pack()


def main():
    mysecurity = mySecurity()

    mysecurity.mainloop()