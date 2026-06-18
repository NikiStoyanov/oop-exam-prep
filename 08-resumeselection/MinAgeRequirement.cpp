#include "MinAgeRequirement.h"

MinAgeRequirement::MinAgeRequirement(unsigned minAge) : minAge(minAge) {}

std::pair<bool, std::string> MinAgeRequirement::check(const Resume& resume) const {
	if (resume.getAge() >= minAge) {
		return { true, "" };
	}

	return { false, std::format("Expected {} years", minAge) };
}

std::unique_ptr<Requirement> MinAgeRequirement::clone() const {
	return std::make_unique<MinAgeRequirement>(*this);
}
