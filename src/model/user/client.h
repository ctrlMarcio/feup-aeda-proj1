#ifndef FEUP_AEDA_PROJ1_CLIENT_H
#define FEUP_AEDA_PROJ1_CLIENT_H


#include "../../model/preference/preference_list.h"
#include "i_renter.h"
#include "i_provider.h"

class Client : public IRenter, public IProvider {
public:
    Client(string name, string identification_number, string address);

    string getName() const override;

    string getIdentificationNumber() const override;

    string getAddress() const override;

    VehicleList &getVehicleList() override;

	PreferenceList &getPreferenceList() override;

private:
    string name;

    string identification_number;

    string address;

    VehicleList vehicle_list;

	PreferenceList preference_list;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_H
