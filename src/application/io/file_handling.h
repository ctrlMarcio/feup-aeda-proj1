#ifndef FEUP_AEDA_PROJ1_FILE_HANDLING_H
#define FEUP_AEDA_PROJ1_FILE_HANDLING_H


#include <string>

/*!
 * Represents a set of constants associated with file handling.
 */
namespace file_handling {

	/*!
	 * The delimiter that separates params inside the files.
	 */
	std::string delimiter = ",";

	/*!
	 * The name of the file that stores auth users.
	 */
	std::string auth_user = "auth_user.csv";

}


#endif //FEUP_AEDA_PROJ1_FILE_HANDLING_H
