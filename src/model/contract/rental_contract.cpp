#include "rental_contract.h"

RentalContract::RentalContract(Date date, IUser *user, ContractType contract_type, Rental &rental) : Contract(
        date, user, contract_type), rental(rental) {}

string RentalContract::getClientName() const {
    return rental.getRenter().getName();
}

Schedule RentalContract::getSchedule() const {
    return rental.getSchedule();
}

string RentalContract::getNumberPlate() const {
    return rental.getOffer().getVehicle().getNumberPlate();
}
