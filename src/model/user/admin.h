#ifndef FEUP_AEDA_PROJ1_ADMIN_H
#define FEUP_AEDA_PROJ1_ADMIN_H


#include "i_user.h"
#include "i_provider.h"

class Admin : public IProvider {
public:
	Admin(string name, string identification_number, string address);

	void print(std::ostream &ostream) const override;

	VehicleList &getVehicleList() override;

	string getName() const override;

	string getIdentificationNumber() const override;

	string getAddress() const override;

	void setVehicleList(VehicleList *vehicleList);

	bool operator==(const Admin &rhs) const;

	bool operator!=(const Admin &rhs) const;

private:
	string name;

	string identification_number;

	string address;

	/*!
	 * The reference to the company's vehicle list.
	 */
	VehicleList *vehicle_list;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_H
