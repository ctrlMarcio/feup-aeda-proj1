#ifndef FEUP_AEDA_PROJ1_USER_MANAGER_H
#define FEUP_AEDA_PROJ1_USER_MANAGER_H


#include "../../model/user/client_manager.h"
#include "../../model/user/admin_manager.h"
#include "../../model/user/client_company_manager.h"


/*!
 * Represents the manager for each type of user.
 */
class UserManager {
public:
    /*!
     * Reads the manager information for a specific file in a directory.
     *
     * @param directory the directory
     * @param vehicle_list the vehicle list
     */
	void read(const std::string &directory, VehicleList *vehicle_list);

	/*!
	 * Writes the manager information to a specific file in a directory.
	 *
	 * @param directory the directory
	 */
	void write(const std::string &directory);

	/*!
	 * Gets a provider given an identification number.
	 *
	 * @param identification_number the identification number
	 * @return a pointer to the provider
	 */
	IProvider *getProvider(const std::string &identification_number);

    /*!
     * Gets a renter given an identification number.
     *
     * @param identification_number the identification number
     * @return a pointer to the renter
     */
	IRenter *getRenter(const std::string &identification_number);

	/*!
	 * Gets the admin manager.
	 *
	 * @return the admin manager
	 */
	AdminManager &getAdminManager();

	/*!
	 * Gets the client company manager.
	 *
	 * @return the client company manager
	 */
	ClientCompanyManager &getClientCompanyManager();

	/*!
	 * Gets the client manager.
	 *
	 * @return the client manager
	 */
	ClientManager &getClientManager();

private:
    /*!
     * The admin manager.
     */
	AdminManager admin_manager;

	/*!
	 * The client company manager.
	 */
	ClientCompanyManager client_company_manager;

	/*!
	 * The client manager.
	 */
	ClientManager client_manager;
};


#endif //FEUP_AEDA_PROJ1_USER_MANAGER_H
