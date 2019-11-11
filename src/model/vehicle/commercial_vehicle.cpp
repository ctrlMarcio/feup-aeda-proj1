#include "commercial_vehicle.h"

#include <utility>

CommercialVehicle::CommercialVehicle(string number_plate, string brand, string model, unsigned int year,
                                     double cargo_volume, double max_weight, bool refrigerated) : number_plate(
        std::move(number_plate)), brand(std::move(brand)), model(std::move(model)), year(year),
                                                                                                  cargo_volume(
                                                                                                          cargo_volume),
                                                                                                  max_weight(
                                                                                                          max_weight),
                                                                                                  refrigerated(
                                                                                                          refrigerated) {
}

string CommercialVehicle::getNumberPlate() const {
    return number_plate;
}

string CommercialVehicle::getBrand() const {
    return brand;
}

string CommercialVehicle::getModel() const {
    return model;
}

unsigned int CommercialVehicle::getYear() const {
    return year;
}

double CommercialVehicle::getCargoVolume() const {
    return cargo_volume;
}

double CommercialVehicle::getMaxWeight() const {
    return max_weight;
}

bool CommercialVehicle::isRefrigerated() const {
    return refrigerated;
}

bool CommercialVehicle::isEqual(const IVehicle &vehicle) const {
    const CommercialVehicle commercial_vehicle = dynamic_cast<const CommercialVehicle &>(vehicle);
    return commercial_vehicle.number_plate == number_plate && commercial_vehicle.brand == brand &&
           commercial_vehicle.model == model && commercial_vehicle.year == year &&
           commercial_vehicle.cargo_volume == cargo_volume
           && commercial_vehicle.max_weight == max_weight && commercial_vehicle.refrigerated == refrigerated;
}
