#ifndef FEUP_AEDA_PROJ1_I_VEHICLE_H
#define FEUP_AEDA_PROJ1_I_VEHICLE_H


#include <ostream>
#include <string>
#include <fstream>


using namespace std;


/*!
 * A IVehicle provides the data implementation for a vehicle.
 */
class IVehicle {
public:
    /*!
     * Gets the number plate of this vehicle.
     *
     * @return the number plate
     */
    virtual const string &getNumberPlate() const = 0;

    /*!
     * Gets the brand of this vehicle.
     *
     * @return the brand
     */
    virtual const string &getBrand() const = 0;

    /*!
     * Gets the model of this vehicle.
     *
     * @return the model
     */
    virtual const string &getModel() const = 0;

    /*!
     * Gets the manufacturing year of this vehicle.
     *
     * @return the year
     */
    virtual unsigned getYear() const = 0;

    /*!
     * Gets the type of a vehicle.
     *
     * @return the type of a vehicle
     */
    virtual const string &getType() const = 0;

    /*!
     * Prints the vehicle information in an ostream.
     *
     * @param ostream the ostream
     */
    virtual void print(std::ostream &ostream) const = 0;

    /*!
     * Prints the vehicle information to a file.
     *
     * @param ofstream of the file
     */
    virtual void printToFile(ofstream &ofstream) const = 0;

    /*!
     * Compares to another vehicles, first verifying if they are from the same type, and them comparing them.
     *
     * @param vehicle the other vehicle
     * @return true if they are equal, false otherwise
     */
    bool operator==(const IVehicle &vehicle) const;

    /*!
     * Prints a vehicle in an ostream.
     *
     * @param ostream the ostream
     * @param vehicle the vehicle
     * @return the changed ostream
     */
    friend ostream &operator<<(ostream &ostream, const IVehicle &vehicle);

private:
    /*!
     * Compares to another vehicle of the same type.
     *
     * @param vehicle the other vehicle
     * @return true if they are equal, false otherwise
     */
    virtual bool isEqual(const IVehicle &vehicle) const = 0;
};


#endif //FEUP_AEDA_PROJ1_I_VEHICLE_H
