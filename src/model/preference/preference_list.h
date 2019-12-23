#ifndef FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
#define FEUP_AEDA_PROJ1_PREFERENCE_LIST_H


#include "passenger_preference.h"
#include "commercial_preference.h"


/*!
 * Represents the list of preferences of an user.
 */
class PreferenceList {
public:

	/*!
	 * Destructs the preference list, deleting the pointers;
	 */
	virtual ~PreferenceList();

	/*!
	 * Updates the passenger preference, deleting the previous one and building a new one with the given attributes.
	 *
	 * @param min_year the min year
	 * @param seat_number the seat number
	 * @return true, if successfully updated. false, otherwise
	 */
	bool updatePreference(unsigned min_year, unsigned seat_number);

	/*!
     * Updates the commercial preference, deleting the previous one and building a new one with the given attributes.
	 *
	 * @param min_year the min year
	 * @param cargo_volume the cargo volume
	 * @param min_max_weight the max weight
	 * @param refrigerated the refrigeration condition
     * @return true, if successfully updated. false, otherwise
	 */
	bool updatePreference(unsigned min_year, float cargo_volume, float min_max_weight, bool refrigerated);

	/*!
	 * Gets the preferences for the passenger vehicles.
	 *
	 * @return the passenger preference
	 */
	PassengerPreference *getPassengerPreference() const;

	/*!
	 * Returns a pointer to the commercial preference.
	 *
	 * @return the pointer to the commercial preference.
	 */
	CommercialPreference *getCommercialPreference() const;

	/*!
	 * Removes the passenger preference.
	 */
	void removePassengerPreference();

	/*!
	 * Removes the commercial preference.
	 */
	void removeCommercialPreference();

	/*!
	 * Equality operator.
	 *
	 * @param rhs the preference list
	 * @return true, if the preference lists are equal. false, otherwise
	 */
	bool operator==(const PreferenceList &rhs) const;

    /*!
     * Inequality operator.
     *
     * @param rhs the preference list
     * @return true, if the preference lists are not equal. false, otherwise
     */
    bool operator!=(const PreferenceList &rhs) const;

private:
    /*!
     * The passenger preference.
     */
	PassengerPreference *passenger_preference = nullptr;

	/*!
	 * The commercial preference.
	 */
	CommercialPreference *commercial_preference = nullptr;

	/*!
	 * Checks if a preference is valid or not.
	 *
	 * @param preference the preference
	 * @return true, if the preference is valid. false, otherwise
	 */
	bool isValid(PassengerPreference preference) const;

    /*!
     * Checks if a preference is valid or not.
     *
     * @param preference the preference
     * @return true, if the preference is valid. false, otherwise
     */
	bool isValid(CommercialPreference preference) const;
};


#endif //FEUP_AEDA_PROJ1_PREFERENCE_LIST_H
