#include <iostream>
#include <print>
#include "LinearFunction.h"

int main() {
	LinearFunction l1(2, 1);

	auto result = l1(3);

	std::println("{}", result.value());
}