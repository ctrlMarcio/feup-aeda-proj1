#ifndef FEUP_AEDA_PROJ1_ADMIN_MANAGER_H
#define FEUP_AEDA_PROJ1_ADMIN_MANAGER_H


#include <list>
#include <algorithm>
#include "admin.h"


using namespace std;


class AdminManager {
public:
	/*!
	 * Constructs a new Admin given its name, identification number and address.
	 *
	 * @param name the name
	 * @param identification_number the identification number
	 * @param address the address
	 * @return the Admin
	 */
	static Admin build(const string &name, const string &identification_number, const string &address);

	/*!
	 * Sets the company's vehicle list to all the admins.
	 *
	 * @param vehicle_list the pointer to the company's vehicle list
	 */
	void setVehicleList(VehicleList *vehicle_list);

    bool add(Admin &admin);

    bool remove(Admin &admin);

    bool has(Admin &admin) const;

    bool has(const string &identification_number) const;

	Admin *get(const string &identification_number);

	/*!
	 * Reads the admins from a file.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace.
	 */
	void read(const std::string &directory);

	/*!
	 * Writes the admins to a file.
	 *
	 * @param directory the directory of the file. The directory should exist. The file name is stored in the file_handling namespace
	 */
	void write(const std::string &directory) const;

private:
	/*!
	 * The container that has all admins.
	 */
	list<Admin> admins;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_MANAGER_H
