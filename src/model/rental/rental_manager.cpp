#include <fstream>
#include "rental_manager.h"
#include "../../exception/invalid_file_exception.h"
#include "../../application/io/file_handling.h"
#include "../../util/string_util.h"
#include "../contract/contract_manager.h"

Rental RentalManager::build(Offer &offer, const Schedule &schedule, IRenter &renter) {
	return Rental(offer, schedule, renter);
}

Rental RentalManager::build(Offer &offer, const Date &begin, const Date &end, IRenter &renter) {
	return Rental(offer, begin, end, renter);
}

bool RentalManager::isValid(Rental &rental) {
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

void RentalManager::read(const std::string &directory, OfferManager &offer_manager, UserManager &user_manager,
						 ContractManager &contract_manager) {
	std::string file_path = directory + "/" + file_handling::rental;

	ifstream ifstream;
	ifstream.open(file_path);

	if (!ifstream.is_open()) {
		std::cout << file_path << " not found! Creating an empty one." << endl;
		std::ofstream file{file_path};
		ifstream.open(file_path);
	}

	std::string line;
	while (getline(ifstream, line)) {
		line = string_util::removeCarriageReturn(line);

		std::vector<std::string> params = string_util::split(line, file_handling::delimiter);

		std::string provider_id = params[0];
		std::string renter_id = params[1];
		std::string number_plate = params[2];
		Date celebration_date = Date::getDate(params[3]);

		IProvider &provider = *user_manager.getProvider(provider_id);
		IRenter *renter = user_manager.getRenter(renter_id);
		IVehicle &vehicle = provider.getVehicleList().get(number_plate);
		Offer &offer = offer_manager.getOfferOf(vehicle);

		Date begin = Date::getDate(params[4]);
		Date end = Date::getDate(params[5]);
		Schedule schedule(begin, end);

		Rental rental(offer, schedule, *renter, celebration_date);
		this->add(rental);

		Contract *contract = new RentalContract(celebration_date, renter, ContractType::RENTAL, rentals.back());
		contract_manager.add(contract);
	}

	ifstream.close();
}

void RentalManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::rental;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (Rental rental : rentals) {
		ofstream << rental.getOffer().getProvider().getIdentificationNumber() << file_handling::delimiter
				 << rental.getRenter().getIdentificationNumber() << file_handling::delimiter
				 << rental.getOffer().getVehicle().getNumberPlate() << file_handling::delimiter;

		Date::printDateToFile(ofstream, rental.getCelebrationDate());
		ofstream << file_handling::delimiter;
		Date::printDateToFile(ofstream, rental.getSchedule().getBegin());
		ofstream << file_handling::delimiter;
		Date::printDateToFile(ofstream, rental.getSchedule().getEnd());
		ofstream << std::endl;
	}

	ofstream.close();
}

const std::list<Rental> &RentalManager::getAllRentals() const {
	return rentals;
}

std::list<Rental> &RentalManager::getAllRentals() {
	return rentals;
}

std::vector<Rental *> RentalManager::getRentals(const string &identification_number) {
    std::vector<Rental *> result;
    for (Rental &rental : rentals)
        if (rental.getRenter().getIdentificationNumber() == identification_number)
            result.push_back(&rental);
    return result;
}
