#ifndef FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H
#define FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H


#include <stdexcept>


using namespace std;


class InvalidLoginException : public invalid_argument {
public:
    explicit InvalidLoginException(const string &arg);
};


#endif //FEUP_AEDA_PROJ1_INVALID_LOGIN_EXCEPTION_H
