#ifndef FEUP_AEDA_PROJ1_OFFER_MANAGER_H
#define FEUP_AEDA_PROJ1_OFFER_MANAGER_H


#include <vector>
#include "../../model/preference/preference_list.h"
#include "offer.h"


using namespace std;

class OfferManager {
public:
	/*!
	 * Creates an offer.
	 *
	 * @param vehicle the vehicle
	 * @param available_schedules the available schedules:
	 * @return the created offer
	 */
	static Offer createOffer(IVehicle &vehicle, const std::list<Schedule> &available_schedules);

	/*!
	 * Gets a container of recommended offers given a container of preferences.
	 *
	 * @param preference_list the list of preferences
	 * @return the container of recommended offers
	 */
	vector<Offer *> getRecommendedOffers(const PreferenceList &preference_list) const;

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
	 * @return true if the offer was successfully removed, false otherwise
	 */
	bool remove(const Offer &offer);

	/*!
	 * Returns the container of offers.
	 *
	 * @return the container of offers.
	 */
	vector<Offer> &getOffers();

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
