#pragma once
#include <memory>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Table.h"
#include "Dish.h"

class Order {
private:
	static unsigned nextOrderId;
	unsigned id;
	bool isFinished = false;
	std::vector<std::weak_ptr<Dish>> dishes;

public:
	Order();
	void addDish(const std::shared_ptr<Dish>& dish, unsigned quantity = 1);
	bool removeOneDish(const std::string& name);

	double getTotalPrice() const;
	void finishOrder();

	friend std::ostream& operator<<(std::ostream& os, const Order& order);
};
