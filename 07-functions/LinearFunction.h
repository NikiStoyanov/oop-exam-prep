#pragma once
#include "Function.h"

class LinearFunction : public Function {
private:
	double slope;
	double intercept;

public:
	LinearFunction(double slope, double intercept);
	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};

