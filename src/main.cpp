#include "util/date.h"
#include "model/company/company.h"
#include "ui/ui/ui_manager.h"
#include "ui/ui/initial_page/initial_page_ui.h"

int main(int argc, char *argv[]) {
    Company company("Google Ride+");

    UIManager ui_manager(company);

    ui_manager.setCurrent(new InitialPageUI(ui_manager));
}