#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_H


#include "i_renter.h"

class ClientCompany : public IRenter {
public:
    ClientCompany(string name, string identification_number, string address, string password);

    string getName() const override;

    string getIdentificationNumber() const override;

    string getAddress() const override;

    string getPassword() const override;

    list<Preference> &getPreferences() override;

private:
    string name;

    string identification_number;

    string address;

    string password;

    list<Preference> preferences;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
