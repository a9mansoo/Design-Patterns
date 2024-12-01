from logger import InfoLogger, ErrorLogger, WarningLogger
from dataclasses import dataclass


@dataclass
class Request:
    level: str
    msg: str





if __name__ == "__main__":
    info_logger = InfoLogger()
    error_logger = ErrorLogger()
    warn_logger = WarningLogger()

    info_logger.add_handler(warn_logger)
    warn_logger.add_handler(error_logger)

    obj_log = Request("ERROR", "Something went wrong!")
    obj_log_2 = Request("WARN", "This is a warning")
    obj_log_3 = Request("INFO", "This is an info level")
    info_logger.handle_logging(obj_log_3)
    info_logger.handle_logging(obj_log_2)
    info_logger.handle_logging(obj_log_3)
    info_logger.handle_logging(obj_log)
