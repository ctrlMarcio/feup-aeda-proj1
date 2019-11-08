#ifndef FEUP_AEDA_PROJ1_I_USER_H
#define FEUP_AEDA_PROJ1_I_USER_H


#include <string>


using namespace std;

class IUser {
public:
    virtual string getName() const = 0;

    virtual string getIdentificationNumber() const = 0;

    virtual string getAddress() const = 0;

    virtual string getPassword() const = 0;
};


#endif //FEUP_AEDA_PROJ1_I_USER_H
