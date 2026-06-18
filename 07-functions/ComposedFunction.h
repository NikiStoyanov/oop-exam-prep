#pragma once
#include "Function.h"
#include <vector>
#include <stdexcept>

class ComposedFunction : public Function {
private:
	std::vector<std::unique_ptr<Function>> functions;

public:
	ComposedFunction() = default;
	ComposedFunction(const ComposedFunction& other);
	ComposedFunction& operator=(const ComposedFunction& other);

	ComposedFunction(ComposedFunction&& other) noexcept = default;
	ComposedFunction& operator=(ComposedFunction&& other) noexcept = default;

	ComposedFunction& then(const Function& func);
	void removeAt(unsigned index);
	Function* getAt(unsigned index);
	const Function* getAt(unsigned index) const;
	unsigned getFunctionsCount() const;
	bool isEmpty() const;

	std::optional<double> operator()(double x) const override;
	std::unique_ptr<Function> clone() const override;
};