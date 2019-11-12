#ifndef FEUP_AEDA_PROJ1_INVALID_FILE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_FILE_EXCEPTION_H


#include <exception>
#include <string>

/*!
 * Represents an exception that indicates an invalid file.
 * E.g.: the file does not exist or it is impossible to open it.
 */
class InvalidFileException : std::exception {
public:
	/*!
	 * Constructs the exception with the path to the file and a message.
	 *
	 * @param file_path the path to the file
	 * @param message the message
	 */
	InvalidFileException(std::string file_path, std::string message = "The file is invalid");

private:
	/*!
	 * The path to the invalid file.
	 */
	std::string file_path;

	/*!
	 * The representative message of the exception.
	 */
	std::string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_FILE_EXCEPTION_H
