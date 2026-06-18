#include "Vehicle.h"

Vehicle::Vehicle(std::string plateNumber) : plateNumber(std::move(plateNumber)) {}

const std::string& Vehicle::getPlateNumber() const {
	return plateNumber;
}
