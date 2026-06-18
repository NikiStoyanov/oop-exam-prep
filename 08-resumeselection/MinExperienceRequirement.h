#pragma once
#include "Requirement.h"
#include <format>

class MinExperienceRequirement : public Requirement {
private:
	unsigned minExperience;

public:
	explicit MinExperienceRequirement(unsigned minExperience);

	std::pair<bool, std::string> check(const Resume& resume) const override;

	std::unique_ptr<Requirement> clone() const override;
};

