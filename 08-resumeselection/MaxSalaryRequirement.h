#pragma once
#include "Requirement.h"
#include <format>

class MaxSalaryRequirement : public Requirement {
private:
	double maxSalary;

public:
	explicit MaxSalaryRequirement(double maxSalary);

	std::pair<bool, std::string> check(const Resume& resume) const override;

	std::unique_ptr<Requirement> clone() const override;
};

