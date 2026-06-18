#pragma once
#include <iostream>
#include <memory>
#include <string>

class Vehicle {
private:
	std::string plateNumber;

public:
	explicit Vehicle(std::string plateNumber);
	const std::string& getPlateNumber() const;

	virtual ~Vehicle() = default;
	virtual void displayInfo(std::ostream& os = std::cout) const = 0;
	virtual std::unique_ptr<Vehicle> clone() const = 0;
};

