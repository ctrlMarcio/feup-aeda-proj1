#ifndef FEUP_AEDA_PROJ1_IO_UTIL_H
#define FEUP_AEDA_PROJ1_IO_UTIL_H

#include <list>

/*!
 * Provides a collection of utilities useful for dealing with io operations.
 */
#include <string>

namespace io_util {

	/*!
	 * Asks a question in the terminal, returning the answer as a float.
	 *
	 * @param question the question to ask
	 * @return the answer as a float
	 */
	float askFloat(const std::string &question);

	/*!
	 * Asks a question in the terminal, returning the answer as a float.
	 *
	 * @param question the question to ask
	 * @return the answer as a float
	 */
	double askDouble(const std::string &question);

	/*!
	 * Asks a question in the terminal, returning the answer as an unsigned int.
	 *
	 * @param question the question to ask
	 * @return the answer as an unsigned int
	 */
	unsigned askUnsigned(const std::string &question);

	/*!
	 * Asks a question in the terminal, returning the answer as a bool.
	 *
	 * @param question the question to ask
	 * @return the answer as a bool
	 */
	bool askBool(const std::string &question);

	/*!
	 * Asks a question in the terminal, returning the answer as a bool.
	 *
	 * @param question the question to ask
	 * @return the answer as a bool
	 */
	std::string askString(const std::string &question);

};


#endif //FEUP_AEDA_PROJ1_IO_UTIL_H
