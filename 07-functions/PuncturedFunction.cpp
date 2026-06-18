#include "PuncturedFunction.h"

PuncturedFunction::PuncturedFunction(const Function& base_function, const std::unordered_set<double>& not_defined_points)
    : base_function(base_function.clone()), not_defined_points(not_defined_points) {}

PuncturedFunction::PuncturedFunction(const PuncturedFunction& other)
    : base_function(other.base_function->clone()), not_defined_points(other.not_defined_points) {}

PuncturedFunction& PuncturedFunction::operator=(const PuncturedFunction& other) {
    if (this != &other) {
        base_function = other.base_function->clone();
        not_defined_points = other.not_defined_points;
    }

    return *this;
}

std::optional<double> PuncturedFunction::operator()(double x) const {
    if (not_defined_points.contains(x)) {
        return std::nullopt;
    }

    return (*base_function)(x);
}

std::unique_ptr<Function> PuncturedFunction::clone() const {
    return std::make_unique<PuncturedFunction>(*this);
}
