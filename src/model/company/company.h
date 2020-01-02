#ifndef FEUP_AEDA_PROJ1_COMPANY_H
#define FEUP_AEDA_PROJ1_COMPANY_H


#include "../rental/rental_manager.h"
#include "../offer/offer_manager.h"
#include "user_manager.h"
#include "../vehicle/vehicle_manager.h"
#include "../contract/contract_manager.h"


/*!
 * Represents the company.
 */
class Company {
public:
    /*!
     * Establishes a new instance of a Company.
     *
     * @param name the company
     */
	explicit Company(string name);

	/*!
	 * Updates the information of the company according to the current day.
	 */
	void update();

	/*!
	 * Reads the company information from specific files in a directory.
	 *
	 * @param directory the directory
	 */
	void read(const std::string &directory);

	/*!
	 * Writes the company information to a directory.
	 *
	 * @param directory the directory
	 */
	void write(const std::string &directory);

	/*!
	 * Gets the name of the company.
	 *
	 * @return the name
	 */
	string getName() const;

	/*!
	 * Gets the user manager of the company.
	 *
	 * @return the user manager
	 */
	UserManager &getUserManager();

	/*!
	 * Gets the rental manager of the company.
	 *
	 * @return the rental manager
	 */
	RentalManager &getRentalManager();

	/*!
	 * Gets the offer manager of the company.
	 *
	 * @return the rental manager
	 */
	OfferManager &getOfferManager();

	/*!
	 * Gets the vehicle manager of the company.
	 *
	 * @return the vehicle manager
	 */
	VehicleManager &getVehicleManager();

	/*!
	 * Gets the contract manager of the company.
	 *
	 * @return the contract manager
	 */
	ContractManager &getContractManager();

private:
    /*!
     * The name of the company.
     */
    string name;

    /*!
     * The user manager of the company.
     */
	UserManager user_manager;

	/*!
	 * The offer manager of the company.
	 */
	OfferManager offer_manager;

	/*!
	 * The rental manager of the company.
	 */
	RentalManager rental_manager;

	/*!
	 * The vehicle manager of the company.
	 */
	VehicleManager vehicle_manager;

	/*!
	 * The contract manager of the company.
	 */
	ContractManager contract_manager;
};


#endif //FEUP_AEDA_PROJ1_COMPANY_H
