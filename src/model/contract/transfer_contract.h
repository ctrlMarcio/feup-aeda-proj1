#ifndef FEUP_AEDA_PROJ1_TRANSFER_CONTRACT_H
#define FEUP_AEDA_PROJ1_TRANSFER_CONTRACT_H


#include "contract.h"
#include "../offer/offer.h"
#include "contract_type.h"

class TransferContract : public Contract {
public:
    TransferContract(Date date, IUser *user, ContractType contract_type, Offer &offer);

    string getProviderName() const;

    const list<Schedule> &getAvailableSchedules() const;

    string getNumberPlate() const;

    float getOfferPrice() const;

    Offer &getOffer() override;

private:
    Offer &offer;

};


#endif //FEUP_AEDA_PROJ1_TRANSFER_CONTRACT_H
