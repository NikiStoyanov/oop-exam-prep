#pragma once
#include "Requirement.h"
#include <algorithm>
#include <format>

class SkillRequirement : public Requirement {
private:
	std::string skill;

public:
	explicit SkillRequirement(std::string skill);

	std::pair<bool, std::string> check(const Resume& resume) const override;

	std::unique_ptr<Requirement> clone() const override;
};

