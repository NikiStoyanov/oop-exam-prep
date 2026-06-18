#pragma once
#include "Car.h"
#include "Motorcycle.h"
#include "Train.h"
#include <sstream>

class VehicleFactory {
public:
    static std::unique_ptr<Vehicle> createVehicle(const std::string& input);
};

