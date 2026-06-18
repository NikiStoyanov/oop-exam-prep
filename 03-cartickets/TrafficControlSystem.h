#pragma once
#include "Vehicle.h"
#include "Ticket.h"
#include <stdexcept>
#include <vector>
#include <optional>
#include <functional>

class TrafficControlSystem {
private:
	std::vector<std::unique_ptr<Vehicle>> vehicles;
	std::vector<Ticket> tickets;

public:
	void addVehicle(std::unique_ptr<Vehicle> vehicle);
	void removeVehicle(const std::string& plateNumber);

	const Vehicle* findVehicle(const std::string& plateNumber) const;
	std::vector<const Vehicle*> findVehicles(const std::function<bool(const Vehicle& s)>& predicate) const;

	void issueTicket(const std::string& plateNumber, double price, const std::string& date);
	void removeTicket(const std::string& plateNumber);
	std::vector<Ticket*> findTickets(const std::string& plateNumber);
	std::vector<const Ticket*> findTickets(const std::string& plateNumber) const;
	std::vector<const Ticket*> findTickets(const std::function<bool(const Ticket& s)>& predicate) const;
};