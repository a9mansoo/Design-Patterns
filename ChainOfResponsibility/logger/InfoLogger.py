from .BaseLogger import BaseLogger


class InfoLogger(BaseLogger):

    def __init__(self):
        super().__init__("INFO")
