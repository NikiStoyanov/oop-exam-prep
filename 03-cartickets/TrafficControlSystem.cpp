#include "TrafficControlSystem.h"

void TrafficControlSystem::addVehicle(std::unique_ptr<Vehicle> vehicle) {
    if (vehicle) {
        vehicles.push_back(std::move(vehicle));
    }
}

void TrafficControlSystem::removeVehicle(const std::string& plateNumber) {
    std::erase_if(vehicles, [&plateNumber](const std::unique_ptr<Vehicle>& vehicle) {
        return vehicle->getPlateNumber() == plateNumber;
		});
}

const Vehicle* TrafficControlSystem::findVehicle(const std::string& plateNumber) const {
    auto it = std::find_if(vehicles.begin(), vehicles.end(), [&plateNumber](const std::unique_ptr<Vehicle>& vehicle) {
            return vehicle->getPlateNumber() == plateNumber;
		});

	return (it != vehicles.end()) ? it->get() : nullptr;
}

std::vector<const Vehicle*> TrafficControlSystem::findVehicles(const std::function<bool(const Vehicle&)>& predicate) const {
    std::vector<const Vehicle*> matched;

    for (const auto& vehicle : vehicles) {
        if (predicate(*vehicle)) {
            matched.push_back(vehicle.get());
        }
    }

    return matched;
}

void TrafficControlSystem::issueTicket(const std::string& plateNumber, double price, const std::string& date) {
    auto it = std::find_if(vehicles.begin(), vehicles.end(), [&plateNumber](const std::unique_ptr<Vehicle>& vehicle) {
        return vehicle->getPlateNumber() == plateNumber;
		});

    if (it == vehicles.end()) {
		throw std::invalid_argument("No vehicle with plate number " + plateNumber + " found.");
	}

	tickets.emplace_back(plateNumber, price, date);
}

void TrafficControlSystem::removeTicket(const std::string & plateNumber) {
    auto it = std::find_if(tickets.begin(), tickets.end(), [&plateNumber](const Ticket& ticket) {
        return ticket.getPlateNumber() == plateNumber; 
        });

    if (it == tickets.end()) {
		throw std::invalid_argument("No ticket with plate number " + plateNumber + " found.");
	}

	tickets.erase(it);
}

std::vector<const Ticket*> TrafficControlSystem::findTickets(const std::string & plateNumber) const {
	std::vector<const Ticket*> matched;

    for (const auto& ticket : tickets) {
        if (ticket.getPlateNumber() == plateNumber) {
            matched.push_back(&ticket);
        }
	}

	return matched;
}

std::vector<Ticket*> TrafficControlSystem::findTickets(const std::string& plateNumber) {
    std::vector<Ticket*> matched;

    for (auto& ticket : tickets) {
        if (ticket.getPlateNumber() == plateNumber) {
            matched.push_back(&ticket);
        }
    }

    return matched;
}

std::vector<const Ticket*> TrafficControlSystem::findTickets(const std::function<bool(const Ticket& s)>& predicate) const {
	std::vector<const Ticket*> matched;

    for (const auto& ticket : tickets) {
        if (predicate(ticket)) {
            matched.push_back(&ticket);
        }
    }

    return matched;
}

