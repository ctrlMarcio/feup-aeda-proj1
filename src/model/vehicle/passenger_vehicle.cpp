#include "passenger_vehicle.h"

#include "../../application/io/file_handling.h"
#include <utility>
#include "../../util/date.h"
#include "../../exception/invalid_vehicle_exception.h"

const string PassengerVehicle::TYPE = "passenger";

PassengerVehicle::PassengerVehicle(string number_plate, string brand, string model,
								   unsigned int year, unsigned int seat_number) :
		number_plate(std::move(number_plate)), brand(std::move(brand)), model(std::move(model)), seat_number(seat_number) {
	setYear(year);
}

void PassengerVehicle::printToFile(ofstream &ofstream) const {
	ofstream << "passenger" << file_handling::delimiter
			 << number_plate << file_handling::delimiter
			 << brand << file_handling::delimiter
			 << model << file_handling::delimiter
			 << year << file_handling::delimiter
			 << seat_number;
}

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
	return number_plate == dynamic_cast<const PassengerVehicle &>(vehicle).number_plate;
}

const string &PassengerVehicle::getType() const {
    return TYPE;
}

void PassengerVehicle::setYear(unsigned year) {
	Date now;
	Date toVerify(1, 1, year);

	if (toVerify.getYear() > now.getYear())
		throw InvalidVehicleException("The year is invalid.");

	this->year = year;
}
