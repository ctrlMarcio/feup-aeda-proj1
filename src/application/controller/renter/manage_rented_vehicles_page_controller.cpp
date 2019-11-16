#include "manage_rented_vehicles_page_controller.h"

ManageRentedVehiclesPageController::ManageRentedVehiclesPageController(CurrentSession &current_session,
                                                                       RentalManager &rental_manager) :
        current_session(current_session),
        rental_manager(rental_manager) {}

vector<Rental *> ManageRentedVehiclesPageController::getActiveRentals() {
    vector<Rental *> rentals = rental_manager.getRentals(current_session.getUser().getIdentificationNumber());
    vector<Rental *> result;
    Date now;
    for (Rental *rental : rentals)
        if (now > rental->getSchedule().getEnd())
            result.push_back(rental);
    return result;
}

bool ManageRentedVehiclesPageController::setDeliveryDate(Rental *rental, Date end_date) {
    Date now;
    if (end_date > now && end_date < rental->getSchedule().getEnd()){
        rental->getSchedule().setEnd(now);
        return true;
    } else {
        return false;
    }
}
