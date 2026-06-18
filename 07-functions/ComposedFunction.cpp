#include "ComposedFunction.h"

ComposedFunction::ComposedFunction(const ComposedFunction& other) {
	for (const auto& func : other.functions) {
		functions.push_back(func->clone());
	}
}

ComposedFunction& ComposedFunction::operator=(const ComposedFunction& other) {
	if (this != &other) {
		functions.clear();

		for (const auto& func : other.functions) {
			functions.push_back(func->clone());
		}
	}

	return *this;
}

ComposedFunction& ComposedFunction::then(const Function& func) {
	functions.push_back(func.clone());

	return *this;
}

void ComposedFunction::removeAt(unsigned index) {
	if (index >= functions.size()) {
		throw std::out_of_range("Invalid index for removal.");
	}

	functions.erase(functions.begin() + index);
}

Function* ComposedFunction::getAt(unsigned index) {
	return functions.at(index).get();
}

const Function* ComposedFunction::getAt(unsigned index) const {
	return functions.at(index).get();
}

unsigned ComposedFunction::getFunctionsCount() const {
	return functions.size();
}

bool ComposedFunction::isEmpty() const {
	return functions.empty();
}

std::optional<double> ComposedFunction::operator()(double x) const {
	double result = x;

	for (const auto& func : functions) {
		std::optional<double> current = (*func)(result);

		if (!current.has_value()) {
			return std::nullopt;
		} else {
			result = current.value();
		}
	}

	return result;
}

std::unique_ptr<Function> ComposedFunction::clone() const {
	return std::make_unique<ComposedFunction>(*this);
}
