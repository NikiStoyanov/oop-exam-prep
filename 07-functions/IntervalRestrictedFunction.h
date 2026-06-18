#pragma once
#include "Function.h"

class IntervalRestrictedFunction : public Function {
private:
	std::unique_ptr<Function> base_function;
	double lower_bound;
	double upper_bound;

public:
	IntervalRestrictedFunction(const Function& base_function, double lower_bound, double upper_bound);
	IntervalRestrictedFunction(const IntervalRestrictedFunction& other);
	IntervalRestrictedFunction& operator=(const IntervalRestrictedFunction& other);

	IntervalRestrictedFunction(IntervalRestrictedFunction&& other) noexcept = default;
	IntervalRestrictedFunction& operator=(IntervalRestrictedFunction&& other) noexcept = default;

	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};