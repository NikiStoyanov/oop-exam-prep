#pragma once
#include "Requirement.h"
#include <format>

class MinAgeRequirement : public Requirement {
private:
	unsigned minAge;

public:
	explicit MinAgeRequirement(unsigned minAge);

	std::pair<bool, std::string> check(const Resume& resume) const override;

	std::unique_ptr<Requirement> clone() const override;
};

