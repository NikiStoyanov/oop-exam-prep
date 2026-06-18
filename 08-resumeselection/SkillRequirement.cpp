#include "SkillRequirement.h"

SkillRequirement::SkillRequirement(std::string skill) : skill(std::move(skill)) {}

std::pair<bool, std::string> SkillRequirement::check(const Resume& resume) const {
	const auto& skills = resume.getSkills();

	if (std::find(skills.cbegin(), skills.cend(), skill) != skills.cend()) {
		return { true, "" };
	}

	return { false, std::format("Missing skill: {}", skill) };
}

std::unique_ptr<Requirement> SkillRequirement::clone() const {
    return std::make_unique<SkillRequirement>(*this);
}
