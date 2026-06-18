#pragma once
#include <string>
#include <iostream>

class Ticket {
private:
	std::string plateNumber;
	double price;
	std::string date;
	bool isPaid = false;

public:
	Ticket(std::string plateNumber, double price, std::string date);
	const std::string& getPlateNumber() const;
	double getPrice() const;
	const std::string& getDate() const;
	bool getIsPaid() const;
	void pay();
	void displayInfo(std::ostream& os = std::cout) const;
};