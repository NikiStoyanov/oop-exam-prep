#include "Ticket.h"

Ticket::Ticket(std::string plateNumber, double price, std::string date)
    : plateNumber(std::move(plateNumber)), price(price), date(std::move(date)) {}

const std::string& Ticket::getPlateNumber() const {
	return plateNumber;
}

double Ticket::getPrice() const {
    return price;
}

const std::string& Ticket::getDate() const {
    return date;
}

bool Ticket::getIsPaid() const {
    return isPaid;
}

void Ticket::pay() {
	isPaid = true;
}

void Ticket::displayInfo(std::ostream & os) const {
    os << "Ticket Information:\n"
        << "-- Plate Number: " << plateNumber << "\n"
        << "-- Price: " << price << "\n"
        << "-- Date: " << date << "\n"
        << "-- Status: " << (isPaid ? "Paid" : "Unpaid") << "\n";
}
