from .LoggerInterface import LoggerInterface


class BaseLogger(LoggerInterface):

    def __init__(self, log_level):
        self.log_level = log_level
        self.handlers = []
    
    def add_handler(self, handler):
        self.handlers.append(handler)


    def output_to_console(self, request):
        print(f"{request.level}: {request.msg}")


    def handle_logging(self, request):
        self.output_to_console(request)
