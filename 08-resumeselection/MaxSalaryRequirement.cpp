#include "MaxSalaryRequirement.h"

MaxSalaryRequirement::MaxSalaryRequirement(double maxSalary) : maxSalary(maxSalary) {}

std::pair<bool, std::string> MaxSalaryRequirement::check(const Resume& resume) const {
	if (resume.getSalary() <= maxSalary) {
		return { true, "" };
	}

	return { false, std::format("Expected at most {} for salary", maxSalary) };
}

std::unique_ptr<Requirement> MaxSalaryRequirement::clone() const {
	return std::make_unique<MaxSalaryRequirement>(*this);
}
