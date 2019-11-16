#include <fstream>
#include "rental_manager.h"
#include "../../exception/invalid_file_exception.h"
#include "../../application/io/file_handling.h"
#include "../../util/string_util.h"

Rental RentalManager::build(Offer &offer, const Schedule &schedule, IRenter &renter) {
	return Rental{offer, schedule, renter};
}

Rental RentalManager::build(Offer &offer, const Date &begin, const Date &end, IRenter &renter) {
	return Rental{offer, begin, end, renter};
}

bool RentalManager::isValid(const Rental &rental) {
	bool valid = (rental.getOffer().hasSchedule(rental.getSchedule()));

	if (!valid)
		return false;

	// verifies if the rental already exists.
	return std::find(this->rentals.begin(), this->rentals.end(), rental) == this->rentals.end();
}

bool RentalManager::add(Rental rental) {
	if (!isValid(rental))
		return false;

	rentals.push_back(rental);
	return true;
}

void RentalManager::read(const std::string &directory, OfferManager &offer_manager, UserManager &user_manager) {
	std::string file_path = directory + "/" + file_handling::rental;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open())
		throw InvalidFileException(file_path);

	std::string line;
	while (getline(ifstream, line)) {
		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);

		std::string provider_id = params[0];
		std::string renter_id = params[1];
		std::string number_plate = params[2];

		IProvider &provider = *user_manager.getProvider(provider_id);
		IRenter &renter = *user_manager.getRenter(renter_id);
		IVehicle &vehicle = provider.getVehicleList().get(number_plate);
		Offer &offer = offer_manager.getOfferOf(vehicle);

		Date *begin = Date::getDate(params[3]);
		Date *end = Date::getDate(params[4]);
		auto *schedule = new Schedule(*begin, *end);

		auto *rental = new Rental(offer, *schedule, renter);
		this->add(*rental);
	}

	ifstream.close();
}

void RentalManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::rental;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const Rental &rental : rentals) {
		ofstream << rental.getOffer().getProvider().getIdentificationNumber() << file_handling::delimiter
				 << rental.getRenter().getIdentificationNumber() << file_handling::delimiter
				 << rental.getOffer().getVehicle().getNumberPlate() << file_handling::delimiter;

		Date::printDate(ofstream, rental.getSchedule().getBegin());
		ofstream << file_handling::delimiter;
		Date::printDate(ofstream, rental.getSchedule().getEnd());
		ofstream << std::endl;
	}

	ofstream.close();
}

const std::list<Rental> &RentalManager::getAllRentals() const {
	return rentals;
}
