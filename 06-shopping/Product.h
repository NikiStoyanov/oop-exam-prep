#pragma once
#include <string>
#include <stdexcept>

class Product {
private:
	std::string name;
	double price;
	std::string category;
public:
	Product(std::string name, double price, std::string category);
	
	const std::string& getName() const;
	double getPrice() const;
	const std::string& getCategory() const;
};

bool operator==(const Product& lhs, const Product& rhs);
bool operator!=(const Product& lhs, const Product& rhs);