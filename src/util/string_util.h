#ifndef FEUP_AEDA_PROJ1_STRING_UTIL_H
#define FEUP_AEDA_PROJ1_STRING_UTIL_H


#include <vector>
#include <string>

/*!
 * Collection of utilities related to std::strings.
 */
namespace string_util {

	/*!
	 * Splits a string into a vector of tokens. This tokens should be delimited by a special string.
	 * E.g.: When calling string_util::split("Hi my name is Abel", " "), it should return a vector with the strings
	 * "Hi", "my", "name", "is", "Abel".
	 *
	 * @param string the string to split
	 * @param delimiter the delimiter that separates tokens
	 * @return a vector with all the tokens
	 */
	std::vector<std::string> split(const std::string string, const std::string delimiter);

}


#endif //FEUP_AEDA_PROJ1_STRING_UTIL_H
