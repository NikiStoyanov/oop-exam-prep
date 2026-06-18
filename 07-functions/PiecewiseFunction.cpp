#include "PiecewiseFunction.h"

PiecewiseFunction::PiecewiseFunction(const Function& left, const Function& right, double point)
    : left(left.clone()), right(right.clone()), point(point) {}

PiecewiseFunction::PiecewiseFunction(const PiecewiseFunction & other)
    : left(other.left->clone()), right(other.right->clone()), point(other.point) {}

PiecewiseFunction& PiecewiseFunction::operator=(const PiecewiseFunction & other) {
    if (this != &other) {
        left = other.left->clone();
        right = other.right->clone();
        point = other.point;
    }

    return *this;
}

std::optional<double> PiecewiseFunction::operator()(double x) const {
    if (x == point) {
        return std::nullopt;
    } else if (x < point) {
        return (*left)(x);
    } else {
        return (*right)(x);
    }
}

std::unique_ptr<Function> PiecewiseFunction::clone() const {
    return std::make_unique<PiecewiseFunction>(*this);
}
