#ifndef FEUP_AEDA_PROJ1_RENT_VEHICLE_UI_H
#define FEUP_AEDA_PROJ1_RENT_VEHICLE_UI_H


#include "../ui_manager.h"
#include "../ui.h"
#include "../../controller/rental/rent_vehicle_controller.h"

class RentVehicleUI : public UI {
public:
	RentVehicleUI(UIManager &ui_manager, Offer &offer);

	void run() override;

private:
	RentVehicleController controller;

	void showVehicle();

	void showAvailableSchedules();

	Rental requestRental();

	Date requestDate();

	bool confirms(Rental &rental);
};


#endif //FEUP_AEDA_PROJ1_RENT_VEHICLE_UI_H
