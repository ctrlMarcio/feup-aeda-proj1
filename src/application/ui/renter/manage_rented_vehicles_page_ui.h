#ifndef FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_UI_H
#define FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_UI_H


#include "../ui.h"
#include "../ui_manager.h"
#include "../../controller/renter/manage_rented_vehicles_page_controller.h"

class ManageRentedVehiclesPageUI : public UI {
public:
    explicit ManageRentedVehiclesPageUI(UIManager &ui_manager);

    void run() override;

private:
    UIManager &ui_manager;

    ManageRentedVehiclesPageController controller;

    string getRental();

    string rentals();

    string getDate(Date &date);

    bool verifyFormat(Date &date, const string &date_string);
};


#endif //FEUP_AEDA_PROJ1_MANAGE_RENTED_VEHICLES_PAGE_UI_H
