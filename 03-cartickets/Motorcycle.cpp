#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string plateNumber, std::string owner, unsigned maxSpeed)
	: Vehicle(std::move(plateNumber)), owner(std::move(owner)), maxSpeed(maxSpeed) {}

const std::string& Motorcycle::getOwner() const {
	return owner;
}

unsigned Motorcycle::getMaxSpeed() const {
    return maxSpeed;
}

void Motorcycle::displayInfo(std::ostream& os) const {
	os << "Motorcycle Information:\n"
	   << "-- Plate Number: " << getPlateNumber() << "\n"
	   << "-- Owner: " << owner << "\n"
	   << "-- Max Speed: " << maxSpeed << " km/h\n"
	   << "---------------------" << std::endl;
}

std::unique_ptr<Vehicle> Motorcycle::clone() const {
	return std::make_unique<Motorcycle>(*this);
}