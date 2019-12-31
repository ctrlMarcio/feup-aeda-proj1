#include "transfer_contract.h"

TransferContract::TransferContract(Date date, IUser *user, ContractType contract_type, Offer &offer) : Contract(date,
                                                                                                                 user,
                                                                                                                 contract_type),
                                                                                                        offer(offer) {}

string TransferContract::getProviderName() const {
    return offer.getProvider().getName();
}

const list<Schedule> &TransferContract::getAvailableSchedules() const {
    return offer.getAvailableSchedules();
}

string TransferContract::getNumberPlate() const {
    return offer.getVehicle().getNumberPlate();
}

float TransferContract::getOfferPrice() const {
    return offer.getPrice();
}
