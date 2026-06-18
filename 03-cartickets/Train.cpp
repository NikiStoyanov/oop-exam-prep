#include "Train.h"

Train::Train(std::string plateNumber, unsigned countOfDrivers, unsigned countOfWagons, unsigned countOfSeats, unsigned countOfStandingPlaces)
	: Vehicle(std::move(plateNumber)), countOfDrivers(countOfDrivers), countOfWagons(countOfWagons), countOfSeats(countOfSeats), countOfStandingPlaces(countOfStandingPlaces) {}

unsigned Train::getCountOfDrivers() const {
    return countOfDrivers;
}

unsigned Train::getCountOfWagons() const {
    return countOfWagons;
}

unsigned Train::getCountOfSeats() const {
    return countOfSeats;
}

unsigned Train::getCountOfStandingPlaces() const {
    return countOfStandingPlaces;
}

void Train::displayInfo(std::ostream& os) const {
    os << "Train Information:\n"
       << "-- Plate Number: " << getPlateNumber() << "\n"
       << "-- Count of Drivers: " << countOfDrivers << "\n"
       << "-- Count of Wagons: " << countOfWagons << "\n"
       << "-- Count of Seats: " << countOfSeats << "\n"
       << "-- Count of Standing Places: " << countOfStandingPlaces << "\n"
	   << "---------------------" << std::endl;
}

std::unique_ptr<Vehicle> Train::clone() const {
    return std::make_unique<Train>(*this);
}