#ifndef FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
#define FEUP_AEDA_PROJ1_CLIENT_COMPANY_H


#include "../../model/preference/preference_list.h"
#include "i_renter.h"


/*!
 * Represents a client company, an implementation of IRenter.
 */
class ClientCompany : public IRenter {
public:
    /*!
     * Establishes a new instance of a client company.
     *
     * @param name the name
     * @param identification_number the identification number
     * @param address the address
     */
    ClientCompany(string name, string identification_number, string address);

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
     * Gets the preference list of this renter.
     *
     * @return the preference list
     */
	PreferenceList getPreferenceList() const override;

    /*!
     * Gets the preference list of this renter.
     *
     * @return the preference list
     */
	PreferenceList &getPreferenceList() override;

    /*!
     * Equality operator.
     *
     * @param rhs the client to compare
     * @return true, if the clients are equal. false, otherwise
     */
    bool operator==(const ClientCompany &rhs) const;

    /*!
	 * Inequality operator.
	 *
	 * @param rhs the client to compare
	 * @return true, if the clients are not equal. false, otherwise
	 */
    bool operator!=(const ClientCompany &rhs) const;

private:
    /*!
     * The name of this client.
     */
    string name;

    /*!
     * The identification number of this client.
     */
    string identification_number;

    /*!
     * The address of this client.
     */
    string address;

    /*!
     * The preferences list of this client.
     */
	PreferenceList preference_list;
};


#endif //FEUP_AEDA_PROJ1_CLIENT_COMPANY_H
