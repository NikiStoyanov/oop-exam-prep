#include "Product.h"

Product::Product(std::string name, double price, std::string category) 
	: name(std::move(name)), price(price), category(std::move(category)) {
	if (price < 0) {
		throw std::invalid_argument("Price cannot be negative.");
	}
}

const std::string& Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}

const std::string& Product::getCategory() const {
	return category;
}

bool operator==(const Product& lhs, const Product& rhs) {
	return (lhs.getName() == rhs.getName()) 
		&& (lhs.getPrice() == rhs.getPrice())
		&& (lhs.getCategory() == rhs.getCategory());
}

bool operator!=(const Product& lhs, const Product& rhs) {
	return !(lhs == rhs);
}