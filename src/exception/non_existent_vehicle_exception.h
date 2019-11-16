#ifndef FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H
#define FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H


#include <stdexcept>


/*!
 * Represents an exception of a non existent vehicle.
 */
class NonExistentVehicleException : std::logic_error {
public:
    /*!
     * Establishes a new instance of a NonExistentVehicleException.
     *
     * @param number_plate the number plate
     * @param message the message
     */
	explicit NonExistentVehicleException(const std::string &number_plate, const std::string &message = "The vehicle does not exist.");

private:
    /*!
     * The number plate of the vehicle.
     */
	const std::string &number_plate;

	/*!
	 * The exception message.
	 */
	const std::string &message;
};


#endif //FEUP_AEDA_PROJ1_NON_EXISTENT_VEHICLE_EXCEPTION_H
