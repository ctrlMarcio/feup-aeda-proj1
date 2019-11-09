#ifndef FEUP_AEDA_PROJ1_CLIENT_H
#define FEUP_AEDA_PROJ1_CLIENT_H


#include "i_renter.h"
#include "i_provider.h"

class Client : public IRenter, public IProvider {
public:
    Client(string name, string identification_number, string address, string password);

    string getName() const override;

    string getIdentificationNumber() const override;

    string getAddress() const override;

    string getPassword() const override;

    VehicleList &getVehicleList() override;

    list<Preference> &getPreferences() override;

private:
    string name;

    string identification_number;

    string address;

    string password;

    VehicleList vehicle_list;

    list<Preference> preferences;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_H
