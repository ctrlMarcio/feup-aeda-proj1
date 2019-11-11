#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_H


#include "../../model/preference/preference_list.h"
#include "i_renter.h"

class ClientCompany : public IRenter {
public:
    ClientCompany(string name, string identification_number, string address);

    string getName() const override;

    string getIdentificationNumber() const override;

    string getAddress() const override;

	PreferenceList &getPreferenceList() override;

private:
    string name;

    string identification_number;

    string address;

	PreferenceList preference_list{};
};


#endif //FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
