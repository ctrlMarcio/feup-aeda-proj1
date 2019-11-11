#include "invalid_schedule_exception.h"

InvalidScheduleException::InvalidScheduleException(const std::string &message) :
		logic_error(message), message(message) {}
