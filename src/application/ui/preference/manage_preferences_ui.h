#ifndef FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_UI_H
#define FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_UI_H


#include "../../controller/preference/manage_preferences_controller.h"
#include "../ui_manager.h"
#include "../ui.h"

class ManagePreferencesUI : public UI {
public:
	explicit ManagePreferencesUI(const UIManager &ui_manager);

	void run() override;

private:
	ManagePreferencesController controller;

	string addOrRemovePreference() const;

	void showPreferences();

	void addPreference();

	void addPassengerPreference();

	void addCommercialPreference();

	void removePreference();

	string whatPreferenceRemove();
};


#endif //FEUP_AEDA_PROJ1_MANAGE_PREFERENCES_UI_H
