#include "QuadraticFunction.h"

QuadraticFunction::QuadraticFunction(double a, double b, double c) : a(a), b(b), c(c) {}

std::optional<double> QuadraticFunction::operator()(double x) const {
	return a * x * x + b * x + c;
}

std::unique_ptr<Function> QuadraticFunction::clone() const {
    return std::make_unique<QuadraticFunction>(*this);
}
