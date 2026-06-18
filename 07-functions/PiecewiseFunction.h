#pragma once
#include "Function.h"

class PiecewiseFunction : public Function {
private:
	std::unique_ptr<Function> left;
	std::unique_ptr<Function> right;
	double point;

public:
	PiecewiseFunction(const Function& left, const Function& right, double point);
	PiecewiseFunction(const PiecewiseFunction& other);
	PiecewiseFunction& operator=(const PiecewiseFunction& other);

	PiecewiseFunction(PiecewiseFunction&& other) noexcept = default;
	PiecewiseFunction& operator=(PiecewiseFunction&& other) noexcept = default;

	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};

