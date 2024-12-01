import abc


class LoggerInterface(abc.ABC):

    @abc.abstractmethod
    def handle_logging(self, request):
        pass
