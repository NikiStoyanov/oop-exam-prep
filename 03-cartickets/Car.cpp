#include "Car.h"

Car::Car(std::string plateNumber, std::string owner, std::string brand, std::string model, unsigned year)
	: Vehicle(std::move(plateNumber)), owner(std::move(owner)), brand(std::move(brand)), model(std::move(model)), year(year) {}

const std::string& Car::getOwner() const {
	return owner;
}

const std::string& Car::getBrand() const {
	return brand;
}

const std::string& Car::getModel() const {
	return model;
}

unsigned Car::getYear() const {
    return year;
}

void Car::displayInfo(std::ostream& os) const {
	os << "Car Information:\n"
	   << "-- Plate Number: " << getPlateNumber() << "\n"
	   << "-- Owner: " << owner << "\n"
	   << "-- Brand: " << brand << "\n"
	   << "-- Model: " << model << "\n"
	   << "-- Year: " << year << "\n"
	   << "---------------------" << std::endl;
}

std::unique_ptr<Vehicle> Car::clone() const {
	return std::make_unique<Car>(*this);
}