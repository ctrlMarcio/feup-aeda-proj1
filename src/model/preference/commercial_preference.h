#ifndef FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
#define FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H


#include <ostream>


/*!
 * Represents a preference for a CommercialVehicle.
 */
class CommercialPreference {
public:
    /*!
     * Establishes a new CommercialPreference instance.
     *
     * @param minYear the min year
     * @param cargoVolume the cargo volume
     * @param minMaxWeight the min max weight
     * @param refrigerated the refrigeration condition
     */
	CommercialPreference(unsigned int minYear, float cargoVolume, float minMaxWeight, bool refrigerated);

	/*!
	 * Gets the min year.
	 *
	 * @return the min year.
	 */
	unsigned int getMinYear() const;

	/*!
	 * Gets the cargo volume.
	 *
	 * @return the cargo volume.
	 */
	float getCargoVolume() const;

	/*!
	 * Gets the min max weight.
	 *
	 * @return the min max weight
	 */
	float getMinMaxWeight() const;

	/*!
	 * Gets the refrigeration condition.
	 *
	 * @return true, if the vehicle is refrigerated. false, otherwise
	 */
	bool isRefrigerated() const;

	friend std::ostream &operator<<(std::ostream &ostream, const CommercialPreference &commercial_preference);

private:
    /*!
     * The min year.
     */
	unsigned min_year;

	/*!
	 * The cargo volume.
	 */
	float cargo_volume;

	/*!
	 * The min max weight.
	 */
	float min_max_weight;

	/*!
	 * Whether the vehicle is refrigerated or not.
	 */
	bool refrigerated;
};


#endif //FEUP_AEDA_PROJ1_COMMERCIAL_PREFERENCE_H
