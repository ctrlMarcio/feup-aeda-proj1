#ifndef FEUP_AEDA_PROJ1_OFFER_H
#define FEUP_AEDA_PROJ1_OFFER_H


#include <ostream>
#include <list>
#include "../vehicle/i_vehicle.h"
#include "../schedule/schedule.h"

class Offer {
public:
	Offer(IVehicle &vehicle, std::list<Schedule> available_schedules);

	void removeScheduleAvailability(const Schedule &to_remove);

	IVehicle &getVehicle() const;

	friend std::ostream &operator<<(std::ostream &ostream, const Offer &offer);

private:
	IVehicle &vehicle;

	std::list<Schedule> available_schedules;

	void setVehicle(const IVehicle &vehicle);

	void setAvailableSchedules(const std::list<Schedule> &available_schedules);
};


#endif //FEUP_AEDA_PROJ1_OFFER_H
