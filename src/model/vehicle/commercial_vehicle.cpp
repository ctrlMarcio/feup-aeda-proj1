#include "commercial_vehicle.h"

#include <utility>

CommercialVehicle::CommercialVehicle(string number_plate, string brand, string model,
									 unsigned int year, double cargo_volume, double max_weight, bool is_refrigerated) :
		number_plate(std::move(number_plate)), brand(std::move(brand)), model(std::move(model)), year(year), cargo_volume(cargo_volume),
		max_weight(max_weight), is_refrigerated(is_refrigerated) {}

const string &CommercialVehicle::getNumberPlate() const {
	return number_plate;
}

const string &CommercialVehicle::getBrand() const {
	return brand;
}

const string &CommercialVehicle::getModel() const {
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
	return is_refrigerated;
}

bool CommercialVehicle::operator==(const CommercialVehicle &rhs) const {
	return number_plate == rhs.number_plate &&
		   brand == rhs.brand &&
		   model == rhs.model &&
		   year == rhs.year &&
		   cargo_volume == rhs.cargo_volume &&
		   max_weight == rhs.max_weight &&
		   is_refrigerated == rhs.is_refrigerated;
}

bool CommercialVehicle::isEqual(const IVehicle &vehicle) const {
	CommercialVehicle commercialVehicle = dynamic_cast<const CommercialVehicle &>(vehicle);

	return *this == commercialVehicle;
}
