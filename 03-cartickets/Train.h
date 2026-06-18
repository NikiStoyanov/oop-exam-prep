#pragma once
#include "Vehicle.h"

class Train : public Vehicle {
private:
	unsigned countOfDrivers;
	unsigned countOfWagons;
	unsigned countOfSeats;
	unsigned countOfStandingPlaces;

public:
	Train(std::string plateNumber, unsigned countOfDrivers, unsigned countOfWagons, unsigned countOfSeats, unsigned countOfStandingPlaces);
	unsigned getCountOfDrivers() const;
	unsigned getCountOfWagons() const;
	unsigned getCountOfSeats() const;
	unsigned getCountOfStandingPlaces() const;
	void displayInfo(std::ostream& os = std::cout) const override;
	std::unique_ptr<Vehicle> clone() const override;
};