#include "Restaurant.h"

Restaurant::Restaurant(const std::string name) : name(name) {}

const std::string& Restaurant::getName() const {
	return name;
}

std::shared_ptr<Table> Restaurant::findTable(unsigned number) const {
	auto it = std::find_if(tables.begin(), tables.end(), [&number](const std::shared_ptr<Table>& t) {
			return t && t->getNumber() == number;
		});

	return (it != tables.end()) ? *it : nullptr;
}

void Restaurant::removeTable(unsigned number) {
	auto table = findTable(number);

	if (!table) {
		throw std::invalid_argument("Table number does not exist");
	}


}

void Restaurant::addTable(unsigned number, unsigned seats) {
	if (findTable(number)) {
		throw std::invalid_argument("Table number already exists");
	}

	tables.push_back(std::make_shared<Table>(number, seats));
}

void Restaurant::addTable(const std::shared_ptr<Table>&table) {
	if (!table) {
		throw std::invalid_argument("Table cannot be null");
	}

	if (findTable(table->getNumber())) {
		throw std::invalid_argument("Table number already exists");
	}

	tables.push_back(table);
}

void 
