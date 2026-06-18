#include "LinearFunction.h"

LinearFunction::LinearFunction(double slope, double intercept) : slope(slope), intercept(intercept) {}

std::optional<double> LinearFunction::operator()(double x) const {
	return slope * x + intercept;
}

std::unique_ptr<Function> LinearFunction::clone() const {
    return std::make_unique<LinearFunction>(*this);
}
