#ifndef FEUP_AEDA_PROJ1_I_PROVIDER_H
#define FEUP_AEDA_PROJ1_I_PROVIDER_H


#include "../../model/vehicle/vehicle_list.h"

class IProvider {
public:
    virtual VehicleList &getVehicleList() = 0;
};


#endif //FEUP_AEDA_PROJ1_I_PROVIDER_H
