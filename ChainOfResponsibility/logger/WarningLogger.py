from .BaseLogger import BaseLogger


class WarningLogger(BaseLogger):

    def __init__(self):
        super().__init__("WARN")
