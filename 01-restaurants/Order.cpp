#include "Order.h"

Order::Order() : id(nextOrderId++) {}

void Order::addDish(const std::shared_ptr<Dish>&dish, unsigned quantity) {
	if (isFinished || !dish || quantity == 0) {
		throw std::invalid_argument("Invalid operation: cannot add dish to finished order or invalid dish/quantity.");
	}

	for (unsigned i = 0; i < quantity; i++) {
		dishes.push_back(dish);
	}
}

bool Order::removeOneDish(const std::string& name) {
	auto it = std::find_if(dishes.begin(), dishes.end(), [&name](const std::weak_ptr<Dish>& d) {
			auto dish = d.lock();

			return dish && dish->getName() == name;
		});

	if (it != dishes.end()) {
		dishes.erase(it);
		return true;
	}

	return false;
}

double Order::getTotalPrice() const
{
	return std::accumulate(dishes.begin(), dishes.end(), 0.0, [](double sum, const std::weak_ptr<Dish>& d) {
			if (auto dish = d.lock()) {
				return sum + dish->getPrice();
			}

			return sum;
		});
}

void Order::finishOrder() {
	isFinished = true;
}

std::ostream& operator<<(std::ostream& os, const Order& order) {
	os << "Order ID: " << order.id << ", Finished: " << (order.isFinished ? "Yes" : "No") << ", Total Price: $" << order.getTotalPrice();
}

unsigned Order::nextOrderId = 1;