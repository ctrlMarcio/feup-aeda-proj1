#ifndef FEUP_AEDA_PROJ1_ADMIN_H
#define FEUP_AEDA_PROJ1_ADMIN_H


#include "i_user.h"

class Admin : public IUser {
public:
    Admin(string name, string identification_number, string address);

    string getName() const override;

    string getIdentificationNumber() const override;

    string getAddress() const override;

private:
    string name;

    string identification_number;

    string address;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_H
