#ifndef FEUP_AEDA_PROJ1_OFFER_MANAGER_H
#define FEUP_AEDA_PROJ1_OFFER_MANAGER_H


#include <vector>
#include "../../model/preference/preference_list.h"
#include "../user/client.h"
#include "offer.h"
#include "../../model/company/user_manager.h"

class IProvider;

using namespace std;

class OfferManager {
public:
	/*!
	 * Creates an offer.
	 *
	 * @param vehicle the vehicle
	 * @param available_schedules the available schedules
	 * @param provider the provider that created the offer
	 * @return the created offer
	 */
	static Offer build(IVehicle &vehicle, const std::list<Schedule> &available_schedules, IProvider &provider);

	/*!
	 * Gets a container of recommended offers given a container of preferences.
	 *
	 * @param preference_list the list of preferences
	 * @return the container of recommended offers
	 */
	vector<Offer *> getRecommendedOffers(const PreferenceList &preference_list);

	/*!
	 * Verifies if already exists offers for a given vehicle.
	 *
	 * @param vehicle the given vehicle
	 * @return true if there exists offers, false otherwise
	 */
	bool hasOfferOf(const IVehicle &vehicle) const;

	/*!
	 * Returns the offer for a given vehicle.
	 *
	 * @param vehicle the given vehicle
	 * @return the offer for the vehicle
	 */
	Offer &getOfferOf(const IVehicle &vehicle);

	/*!
	 * Adds an offer to the container.
	 *
	 * @param offer the offer to add
	 * @return true if the offer was successfully added, false otherwise
	 */
	bool add(const Offer &offer);

	/*!
	 * Removes an offer from the container.
	 *
	 * @param offer the offer to remove
	 * @return true if the offer was successfully removed, false otherwiseShould be a relative directory starting in the / (root) of the project.
	 */
	bool remove(const Offer &offer);

	/*!
	 * Returns the container of offers.
	 *
	 * @return the container of offers.
	 */
	vector<Offer> &getOffers();

	/*!
	 * Reads offers from a file.
	 * Should only be implemented after all the IProvider's read.
	 *
	 * @param directory the directory of the file. The file name is stored in the file_handling namespace
	 * @param the user manager to get access to the offer's users
	 */
	void read(const std::string &directory, UserManager &user_manager);

	/*!
	 * Writes the users to a file.
	 *
	 * @param directory the directory of the file. Should be a relative directory starting in the / (root) of the project. The directory should exist. The file name is stored in the file_handling namespace.
	 */
	void write(const std::string &directory) const;

private:
	/*!
	 * The container of offers.
	 */
	vector<Offer> offers;

	/*!
	 * Verifies if an offer is valid.
	 *
	 * @param offer the offer to verify
	 * @return true if the offer is valid, false otherwise
	 */
	bool isValid(const Offer &offer) const;
};


#endif //FEUP_AEDA_PROJ1_OFFER_MANAGER_H
