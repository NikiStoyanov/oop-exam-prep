#include "Table.h"

Table::Table(unsigned number, unsigned seats) : number(number), seats(seats) {}

unsigned Table::getNumber() const {
    return number;
}

unsigned Table::getSeats() const {
    return seats;
}
