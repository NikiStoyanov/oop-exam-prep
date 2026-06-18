#pragma once
#include "Order.h"
#include "Table.h"
#include "Dish.h"
class Restaurant {
private:
	std::string name;
	std::vector<std::shared_ptr<Table>> tables;
	std::vector<std::shared_ptr<Dish>> menu;
	std::vector<std::shared_ptr<Order>> orders;

public:
	Restaurant(const std::string name);
	const std::string& getName() const;

	std::shared_ptr<Table> findTable(unsigned number) const;
	void removeTable(unsigned number);
	void addTable(unsigned number, unsigned seats);
	void addTable(const std::shared_ptr<Table>& table);
};

