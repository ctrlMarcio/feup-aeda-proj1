#ifndef FEUP_AEDA_PROJ1_RENTAL_CONTRACT_H
#define FEUP_AEDA_PROJ1_RENTAL_CONTRACT_H


#include "contract.h"
#include "../rental/rental.h"

class RentalContract : public Contract {
public:
    RentalContract(Date date, IUser *user, ContractType contract_type, Rental &rental);

    string getClientName() const;

    Schedule getSchedule() const;

    string getNumberPlate() const;

private:
    Rental &rental;
};


#endif //FEUP_AEDA_PROJ1_RENTAL_CONTRACT_H
