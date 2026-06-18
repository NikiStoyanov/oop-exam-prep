#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
private:
	std::string owner;
	std::string brand;
	std::string model;
	unsigned year;

public:
	Car(std::string plateNumber, std::string owner, std::string brand, std::string model, unsigned year);
	const std::string& getOwner() const;
	const std::string& getBrand() const;
	const std::string& getModel() const;
	unsigned getYear() const;
	void displayInfo(std::ostream& os = std::cout) const override;
	std::unique_ptr<Vehicle> clone() const override;
};