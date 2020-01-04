#include <fstream>
#include "admin_manager.h"
#include "../../application/io/file_handling.h"
#include "../../exception/invalid_file_exception.h"
#include "../../util/string_util.h"

Admin AdminManager::build(const string &name, const string &identification_number, const string &address) {
	return Admin(name, identification_number, address);
}

void AdminManager::setVehicleList(VehicleList *vehicle_list) {
	for (Admin &admin : admins)
		admin.setVehicleList(vehicle_list);
}

bool AdminManager::add(Admin &admin) {
	if (has(admin) || has(admin.getIdentificationNumber())) return false;
	admins.push_back(admin);
	return true;
}

bool AdminManager::remove(Admin &admin) {
	if (!has(admin) || !has(admin.getIdentificationNumber())) return false;
	admins.erase(find(admins.begin(), admins.end(), admin));
	return true;
}

bool AdminManager::has(Admin &admin) const {
	return find(admins.begin(), admins.end(), admin) != admins.end();
}

bool AdminManager::has(const string &identification_number) const {
	return find_if(admins.begin(), admins.end(), [&identification_number](const Admin &admin){
		return admin.getIdentificationNumber() == identification_number;
	}) != admins.end();
}

Admin *AdminManager::get(const string &identification_number) {
	auto it = admins.begin();

	while (it != admins.end()){
		if ((*it).getIdentificationNumber() == identification_number){
			return &(*it);
		}
		it++;
	}

	return nullptr;
}

void AdminManager::read(const std::string &directory) {
	std::string file_path = directory + "/" + file_handling::admin;

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
		std::string name = params[0];
		std::string identification_number = params[1];
		std::string address = params[2];

		Admin *admin = new Admin(name, identification_number, address);
		this->add(*admin);
	}

	ifstream.close();
}

void AdminManager::write(const std::string &directory) const {
	std::string file_path = directory + "/" + file_handling::admin;

	ofstream ofstream;
	ofstream.open(file_path);

	if (!ofstream.is_open())
		throw InvalidFileException(file_path);

	for (const Admin &admin : admins)
		ofstream << admin.getName() << file_handling::delimiter << admin.getIdentificationNumber()
				 << file_handling::delimiter << admin.getAddress() << std::endl;

	ofstream.close();
}
