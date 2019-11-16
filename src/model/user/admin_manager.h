#ifndef FEUP_AEDA_PROJ1_ADMIN_MANAGER_H
#define FEUP_AEDA_PROJ1_ADMIN_MANAGER_H


#include <list>
#include <algorithm>
#include "admin.h"


using namespace std;


/*!
 * Represents a class that is responsible for managing admins.
 */
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

    /*!
     * Adds an admin to the list.
     *
     * @param admin the admin
     * @return true, if the admin is added successfully. false, otherwise
     */
    bool add(Admin &admin);

    /*!
     * Removes an admin from the list.
     *
     * @param admin the admin
     * @return true, if the admin is removed successfully. false, otherwise
     */
    bool remove(Admin &admin);

    /*!
     * Verifies if an admin is in the list or not.
     *
     * @param admin the admin
     * @return true, if the admin is in the list. false, otherwise
     */
    bool has(Admin &admin) const;

    /*!
     * Verifies if an admin is in the list or not.
     *
     * @param identification_number the identification number of the admin
     * @return true, if the admin is in the list. false, otherwise
     */
    bool has(const string &identification_number) const;

    /*!
     * Gets a specific admin given a identification number.
     *
     * @param identification_number the identification number
     * @return a pointer to the admin
     */
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
