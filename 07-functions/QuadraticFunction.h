#pragma once
#include "Function.h"

class QuadraticFunction : public Function {
private:
	double a;
	double b;
	double c;

public:
	QuadraticFunction(double a, double b, double c);
	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};

