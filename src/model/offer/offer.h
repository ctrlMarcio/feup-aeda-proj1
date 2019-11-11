#ifndef FEUP_AEDA_PROJ1_OFFER_H
#define FEUP_AEDA_PROJ1_OFFER_H


#include <ostream>
#include <list>
#include "../vehicle/i_vehicle.h"
#include "../schedule/schedule.h"

class Offer {
public:
	Offer(IVehicle &vehicle, std::list<Schedule> available_schedules, float price = 0);

	void removeScheduleAvailability(const Schedule &to_remove);

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
	 *
	 * @param schedule the schedule to add.
	 * @return true if the schedule was successfully added, false otherwise
	 */
	bool addSchedule(const Schedule &schedule);

	/*!
	 * Sets the price of the offer.
	 * The price is in €/h.
	 *
	 * @param price the new price
	 */
	void setPrice(float price);

	/*!
	 * Verifies if another offer is equal to this one.
	 *
	 * @param rhs the another offer
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Offer &rhs) const;

	Offer &operator=(const Offer &offer);

	friend std::ostream &operator<<(std::ostream &ostream, const Offer &offer);

private:
	IVehicle &vehicle;

	std::list<Schedule> available_schedules;

	/*!
	 * The price of the offer.
	 * The price is in €/h.
	 */
	float price;

	void setVehicle(const IVehicle &vehicle);

	void setAvailableSchedules(const std::list<Schedule> &available_schedules);
};


#endif //FEUP_AEDA_PROJ1_OFFER_H
