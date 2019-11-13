#include "invalid_login_exception.h"

InvalidLoginException::InvalidLoginException(const string &arg) : invalid_argument(arg), message(arg) {}

string &InvalidLoginException::getMessage() {
    return message;
}
