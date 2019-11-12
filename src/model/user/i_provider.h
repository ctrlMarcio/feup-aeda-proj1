#ifndef FEUP_AEDA_PROJ1_I_PROVIDER_H
#define FEUP_AEDA_PROJ1_I_PROVIDER_H


#include "../../model/vehicle/vehicle_list.h"
#include "i_user.h"

class IProvider : public IUser {
public:
	virtual VehicleList &getVehicleList() = 0;

	virtual void print(std::ostream &ostream) const = 0;

	friend std::ostream &operator<<(std::ostream &ostream, const IProvider &provider);
};


#endif //FEUP_AEDA_PROJ1_I_PROVIDER_H
