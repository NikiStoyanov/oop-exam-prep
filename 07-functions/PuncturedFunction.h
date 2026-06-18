#pragma once
#include "Function.h"
#include <unordered_set>

class PuncturedFunction : public Function {
private:
	std::unique_ptr<Function> base_function;
	std::unordered_set<double> not_defined_points;

public:
	PuncturedFunction(const Function& base_function, const std::unordered_set<double>& not_defined_points);
	PuncturedFunction(const PuncturedFunction& other);
	PuncturedFunction& operator=(const PuncturedFunction& other);

	PuncturedFunction(PuncturedFunction&& other) noexcept = default;
	PuncturedFunction& operator=(PuncturedFunction&& other) noexcept = default;

	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};

