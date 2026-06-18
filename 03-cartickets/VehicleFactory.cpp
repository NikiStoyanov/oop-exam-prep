#include "VehicleFactory.h"

std::unique_ptr<Vehicle> VehicleFactory::createVehicle(const std::string& input) {
    std::istringstream stream(input);
    std::string type, regNum;

    stream >> type >> regNum;

    if (type == "Car") {
        std::string owner, brand, model;
        int year;

        stream >> owner >> brand >> model >> year;
        return std::make_unique<Car>(regNum, owner, brand, model, year);
    }
    else if (type == "Motorcycle") {
        std::string owner;
        int maxSpeed;

        stream >> owner >> maxSpeed;
        return std::make_unique<Motorcycle>(regNum, owner, maxSpeed);
    }
    else if (type == "Train") {
        int machinists, wagons, seats, standing;

        stream >> machinists >> wagons >> seats >> standing;
        return std::make_unique<Train>(regNum, machinists, wagons, seats, standing);
    }
    else {
        throw std::invalid_argument("Непознат тип превозно средство: " + type);
    }
}