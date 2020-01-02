#ifndef FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H


#include "../../../model/vehicle/vehicle_list.h"
#include "../../../model/offer/offer_manager.h"
#include "../../../auth/current_session/current_session.h"

class EditVehicleController {
public:
    EditVehicleController(IProvider &provider, OfferManager &offer_manager, ContractManager &contract_manager,
                          CurrentSession &current_session);

    const vector<IVehicle *> &getVehicles() const;

    void setVehicle(IVehicle *vehicle);

    bool isUpToRent();

    bool createOffer(const std::list<Schedule> &schedules, float price);

    bool removeOffer();

    bool changePrice(float price);

    void setOffer();

    bool addSchedule(Schedule schedule);

private:
    VehicleList &vehicle_list;

    OfferManager &offer_manager;

    IProvider &provider;

    IVehicle *vehicle = nullptr;

    Offer *offer = nullptr;

    ContractManager &contract_manager;

    CurrentSession &current_session;
};


#endif //FEUP_AEDA_PROJ1_EDIT_VEHICLE_CONTROLLER_H
