#include "IntervalRestrictedFunction.h"
#include <stdexcept>

IntervalRestrictedFunction::IntervalRestrictedFunction(const Function& base_function, double lower_bound, double upper_bound)
	: base_function(base_function.clone()), lower_bound(lower_bound), upper_bound(upper_bound) {
    if (lower_bound > upper_bound) {
        throw std::invalid_argument("Lower bound cannot be greater than upper bound.");
	}
}

IntervalRestrictedFunction::IntervalRestrictedFunction(const IntervalRestrictedFunction& other)
	: base_function(other.base_function->clone()), lower_bound(other.lower_bound), upper_bound(other.upper_bound) {}

IntervalRestrictedFunction& IntervalRestrictedFunction::operator=(const IntervalRestrictedFunction& other) {
    if (this != &other) {
        base_function = other.base_function->clone();
        lower_bound = other.lower_bound;
        upper_bound = other.upper_bound;
    }

    return *this;
}

std::optional<double> IntervalRestrictedFunction::operator()(double x) const {
	if (x < lower_bound || x > upper_bound) {
		return std::nullopt;
	}

	return (*base_function)(x);
}

std::unique_ptr<Function> IntervalRestrictedFunction::clone() const {
    return std::make_unique<IntervalRestrictedFunction>(*this);
}
