#ifndef FEUP_AEDA_PROJ1_OFFER_H
#define FEUP_AEDA_PROJ1_OFFER_H


#include <ostream>
#include <list>
#include "../vehicle/i_vehicle.h"
#include "../schedule/schedule.h"
#include "../user/client.h"

class IProvider;

/*!
 * Represents an offer.
 * An offer indicates that a given vehicle is ready for rental in a given schedule.
 */
class Offer {
public:
	/*!
	 * The constructor of the offer.
	 *
	 * @param vehicle the vehicle to rent
	 * @param available_schedules the available schedules
	 * @param provider the user who provides the vehicle
	 * @param price the price in €/h
	 * @param celebration_date the celebration date
	 */
	Offer(IVehicle &vehicle, std::list<Schedule> available_schedules, IProvider &provider, float price = 0,
		  Date celebration_date = Date());

	/*!
	 * Removes a schedule availability.
	 *
	 * @param to_remove the schedule
	 */
	void removeScheduleAvailability(const Schedule &to_remove);

	/*!
	 * Gets the vehicle.
	 *
	 * @return the vehicle
	 */
	IVehicle &getVehicle() const;

	/*!
	 * Verifies if a schedule is contained in the available schedules.
	 *
	 * @param schedule the schedule to verify
	 * @return true if it is contained, false otherwise
	 */
	bool hasSchedule(const Schedule &schedule) const;

	/*!
	 * Adds a schedule to the offer.
	 *
	 * @param begin the beginning of the schedule
	 * @param end the end of the schedule
	 * @return true if the schedule was successfully added, false otherwise
	 */
	bool addSchedule(const Date &begin, const Date &end);

	/*!
	 * Adds a schedule to the offer.
	 * If the schedule interferes with one that already exists there, merges them into one.
	 *
	 * @param schedule the schedule to add.
	 * @return true if the schedule was successfully added, false otherwise
	 */
	bool addSchedule(Schedule schedule);

	/*!
	 * Sets the price of the offer.
	 * The price is in €/h.
	 *
	 * @param price the new price
	 * @return true if the price is valid, false otherwise
	 */
	bool setPrice(float price);

	/*!
	 * Gets the price per hour
	 *
	 * @return the price per hour
	 */
	float getPrice() const;

	/*!
	 * Gets the schedules in which the offer is available.
	 *
	 * @return the const reference to the list of schedules
	 */
	const list<Schedule> &getAvailableSchedules() const;

	/*!
	 * Gets the user who provided the offer.
	 *
	 * @return the reference to the provider
	 */
	IProvider &getProvider() const;

	const Date &getCelebrationDate() const;

	/*!
	 * Verifies if another offer is equal to this one.
	 * Two offers are equal if the vehicle and the schedules are equal.
	 *
	 * @param rhs the another offer
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Offer &rhs) const;

	Offer &operator=(const Offer &offer);

	friend std::ostream &operator<<(std::ostream &ostream, const Offer &offer);

private:
	/*!
	 * The vehicle that will be rent.
	 */
	IVehicle &vehicle;

	/*!
	 * The schedules in which the offer is available.
	 */
	std::list<Schedule> available_schedules;

	/*!
	 * The user who provided the offer.
	 */
	IProvider &provider;

	/*!
	 * The price of the offer.
	 * The price is in €/h.
	 */
	float price;

	/*!
	 * The celebration date of the offer.
	 */
	Date celebration_date;

	/*!
	 * Sets the vehicle of the offer.
	 *
	 * @param vehicle the vehicle of the offer
	 */
	void setVehicle(const IVehicle &vehicle);

	/*!
	 * Sets the available schedules.
	 *
	 * @param available_schedules the available schedules
	 */
	void setAvailableSchedules(const std::list<Schedule> &available_schedules);

	/*!
	 * Verifies if a price per hour is valid.
	 *
	 * @param price the price per hour
	 * @return true if it is valid, false otherwise
	 */
	static bool isPriceValid(float price);
};


#endif //FEUP_AEDA_PROJ1_OFFER_H
