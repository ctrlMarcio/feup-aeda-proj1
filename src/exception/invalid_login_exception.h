#ifndef FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H


#include <stdexcept>


using namespace std;


/*!
 * Represents an exception thrown then a bad login is executed.
 */
class InvalidLoginException : public invalid_argument {
public:
    /*!
     * Establishes a new instance of an InvalidLoginException.
     *
     * @param arg the arguments
     */
    explicit InvalidLoginException(const string &arg);

    /*!
     * Gets the message.
     *
     * @return the message
     */
    string &getMessage();

private:
    /*!
     * The message.
     */
    string message;
};


#endif //FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H
