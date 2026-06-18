#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
	std::string owner;
	unsigned maxSpeed;

public:
	Motorcycle(std::string plateNumber, std::string owner, unsigned maxSpeed);
	const std::string& getOwner() const;
	unsigned getMaxSpeed() const;
	void displayInfo(std::ostream& os = std::cout) const override;
	std::unique_ptr<Vehicle> clone() const override;
};