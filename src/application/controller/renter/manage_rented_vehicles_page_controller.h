#ifndef FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_CONTROLLER_H
#define FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_CONTROLLER_H


#include "../../../auth/current_session/current_session.h"
#include "../../../model/rental/rental_manager.h"

class ManageRentedVehiclesPageController {
public:
    explicit ManageRentedVehiclesPageController(CurrentSession &current_session, RentalManager &rental_manager);

    vector<Rental *> getActiveRentals();

    bool setDeliveryDate(Rental *rental, Date end_date);
private:
    CurrentSession &current_session;

    RentalManager &rental_manager;
};


#endif //FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_CONTROLLER_H
