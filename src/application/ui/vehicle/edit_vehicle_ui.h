#ifndef FEUP_AEDA_PROJ1_EDIT_VEHICLE_UI_H
#define FEUP_AEDA_PROJ1_EDIT_VEHICLE_UI_H


#include "../../controller/vehicle/edit_vehicle_controller.h"
#include "../ui_manager.h"

class EditVehicleUI : public UI {
public:
	explicit EditVehicleUI(UIManager &ui_manager);

	void run() override;

private:
	EditVehicleController controller;

	void showAllVehicles() const;

	int chooseVehicle();

	void createOffer();

	std::list<Schedule> requestSchedules();

	Date requestDate();

	void editOffer();

	void changePrice();

	void addOffer();

	void addSchedule();
	Schedule askSchedule();
};


#endif //FEUP_AEDA_PROJ1_EDIT_VEHICLE_UI_H
