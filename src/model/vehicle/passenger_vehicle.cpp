#include "passenger_vehicle.h"

#include <utility>

PassengerVehicle::PassengerVehicle(string number_plate, string brand, string model,
								   unsigned int year, unsigned int seat_number) :
		number_plate(std::move(number_plate)), brand(std::move(brand)), model(std::move(model)), year(year), seat_number(seat_number) {}

void PassengerVehicle::print(std::ostream &ostream) const {
	ostream << "Number plate: " << number_plate << std::endl
			<< "Brand: " << brand << std::endl
			<< "Model: " << model << std::endl
			<< "Year: " << year << std::endl
			<< seat_number << " seats" << std::endl;
}

const std::string &PassengerVehicle::getNumberPlate() const {
	return number_plate;
}

const string &PassengerVehicle::getBrand() const {
	return brand;
}

const string &PassengerVehicle::getModel() const {
	return model;
}

unsigned PassengerVehicle::getYear() const {
	return year;
}

unsigned PassengerVehicle::getSeatNumber() const {
	return seat_number;
}

bool PassengerVehicle::isEqual(const IVehicle &vehicle) const {
	return seat_number == dynamic_cast<const PassengerVehicle &>(vehicle).seat_number;
}
