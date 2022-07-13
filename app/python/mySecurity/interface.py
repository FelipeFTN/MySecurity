import kivy 

from kivy.app import App
from kivy.uix.button import Label

class Application(App):
    def build(self):
        return Label(text="MySecurity!")
