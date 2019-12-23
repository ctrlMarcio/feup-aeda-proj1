#ifndef FEUP_AEDA_PROJ1_ADMIN_H
#define FEUP_AEDA_PROJ1_ADMIN_H


#include "i_user.h"
#include "i_provider.h"


/*!
 * Represents an admin, an implementation of IProvider.
 */
class Admin : public IProvider {
public:
    /*!
     * Establishes a new instance of an admin.
     *
     * @param name the name
     * @param identification_number the identification number
     * @param address the address
     */
	Admin(string name, string identification_number, string address);

    /*!
     * Prints the information of the admin to an output stream.
     *
     * @param ostream the output stream
     */
	void print(std::ostream &ostream) const override;

    /*!
     * Gets the vehicle list of this provider.
     *
     * @return the vehicle list
     */
	VehicleList &getVehicleList() override;

    /*!
     * Gets the name of this user.
     *
     * @return the name
     */
	string getName() const override;

    /*!
     * Gets the identification number of this user. The identification number is unique and associated to a government
     * unique number such as the tax identification number.
     *
     * @return the identification number
     */
	string getIdentificationNumber() const override;

    /*!
     * Gets the address of this user. The address follows the following format: [street name] [door number],
     * [postal town (town/city)], [postal code], [country name].
     *
     * Example: Oxford Road 28, Aylesbury, HP19 3EQ, United Kingdom
     *
     * @return the address
     */
	string getAddress() const override;

	/*!
	 * Sets the vehicle list of this admin.
	 *
	 * @param vehicleList the vehicle list
	 */
	void setVehicleList(VehicleList *vehicleList);

    /*!
     * Equality operator.
     *
     * @param rhs the admin to compare
     * @return true, if the admins are equal. false, otherwise
     */
	bool operator==(const Admin &rhs) const;

    /*!
     * Inequality operator.
     *
     * @param rhs the admin to compare
     * @return true, if the admins are not equal. false, otherwise
     */
	bool operator!=(const Admin &rhs) const;

private:
    /*!
     * The name of this admin.
     */
	string name;

	/*!
	 * The identification number of this admin.
	 */
	string identification_number;

	/*!
	 * The address of this admin.
	 */
	string address;

	/*!
	 * The reference to the company's vehicle list.
	 */
	VehicleList *vehicle_list = nullptr;
};


#endif //FEUP_AEDA_PROJ1_ADMIN_H
