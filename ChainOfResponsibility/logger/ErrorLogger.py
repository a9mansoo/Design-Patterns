from .BaseLogger import BaseLogger


class ErrorLogger(BaseLogger):

    def __init__(self):
        super().__init__("ERROR")
