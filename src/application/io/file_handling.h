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
	extern std::string delimiter;

	/*!
	 * The delimiter that separates different params from the same date.
	 * E.g.: "12.11.2019.12.21.43" should describe 12/12/2019 at 12H21m43s.
	 */
	extern std::string time_delimiter;

	/*!
	 * The name of the file that stores auth users.
	 */
	extern std::string auth_user;

	/*!
	 * The name of the file that stores offers.
	 */
	extern std::string offer;

	/*!
	 * The name of the file that stores rentals.
	 */
	extern std::string rental;

	/*!
	 * The name of the file that stores client companies.
	 */
	extern std::string client_company;
}


#endif //FEUP_AEDA_PROJ1_FILE_HANDLING_H
