#pragma once
#include <optional>
#include <memory>

class Function {
public:
	virtual std::optional<double> operator()(double x) const = 0;
	virtual std::unique_ptr<Function> clone() const = 0;

	virtual ~Function() = default;
};