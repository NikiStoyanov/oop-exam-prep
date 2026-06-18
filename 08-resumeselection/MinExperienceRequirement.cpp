#include "MinExperienceRequirement.h"

MinExperienceRequirement::MinExperienceRequirement(unsigned minExperience) : minExperience(minExperience) {}

std::pair<bool, std::string> MinExperienceRequirement::check(const Resume& resume) const {
	if (resume.getYearsOfExperience() >= minExperience) {
		return { true, "" };
	}

	return { false, std::format("Expected {} years of experience.", minExperience)};
}

std::unique_ptr<Requirement> MinExperienceRequirement::clone() const {
    return std::make_unique<MinExperienceRequirement>(*this);
}
