#pragma once
class Table {
private:
	unsigned number;
	unsigned seats;

public:
	Table(unsigned number, unsigned seats);

	unsigned getNumber() const;
	unsigned getSeats() const;
};

