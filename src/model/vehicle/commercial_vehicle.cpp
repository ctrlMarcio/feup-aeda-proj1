#include "commercial_vehicle.h"

#include "../../application/io/file_handling.h"
#include <utility>

const string CommercialVehicle::TYPE = "commercial";

CommercialVehicle::CommercialVehicle(string number_plate, string brand, string model,
									 unsigned int year, double cargo_volume, double max_weight, bool refrigerated) :
		number_plate(std::move(number_plate)), brand(std::move(brand)), model(std::move(model)), year(year), cargo_volume(cargo_volume),
		max_weight(max_weight), refrigerated(refrigerated) {}

void CommercialVehicle::printToFile(ofstream &ofstream) const {
	ofstream << "commercial" << file_handling::delimiter
			 << number_plate << file_handling::delimiter
			 << brand << file_handling::delimiter
			 << model << file_handling::delimiter
			 << year << file_handling::delimiter
			 << cargo_volume << file_handling::delimiter
			 << max_weight << file_handling::delimiter
			 << refrigerated;
}

void CommercialVehicle::print(std::ostream &ostream) const {
	ostream << "Number plate: " << number_plate << std::endl
			<< "Brand: " << brand << std::endl
			<< "Model: " << model << std::endl
			<< "Year: " << year << std::endl
			<< "Cargo Volume: " << cargo_volume << std::endl
			<< "Max Weight: " << max_weight << std::endl;

	if (!refrigerated)
		ostream << "Not ";
	ostream << "Refrigerated" << std::endl;
}

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
	return refrigerated;
}

bool CommercialVehicle::operator==(const CommercialVehicle &rhs) const {
	return number_plate == rhs.number_plate &&
		   brand == rhs.brand &&
		   model == rhs.model &&
		   year == rhs.year &&
		   cargo_volume == rhs.cargo_volume &&
		   max_weight == rhs.max_weight &&
		   refrigerated == rhs.refrigerated;
}

bool CommercialVehicle::isEqual(const IVehicle &vehicle) const {
	CommercialVehicle commercialVehicle = dynamic_cast<const CommercialVehicle &>(vehicle);

	return *this == commercialVehicle;
}

const string &CommercialVehicle::getType() const {
    return TYPE;
}
