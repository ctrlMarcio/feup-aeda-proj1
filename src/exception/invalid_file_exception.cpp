#include "invalid_file_exception.h"

InvalidFileException::InvalidFileException(std::string file_path, std::string message) :
		file_path(file_path), message(message) {}
