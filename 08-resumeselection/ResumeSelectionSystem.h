#pragma once
#include <iostream>
#include "Requirement.h"
#include "ResumePool.h"
class ResumeSelectionSystem {
private:
	std::vector<std::unique_ptr<Requirement>> requirements;
	ResumePool resumes;

public:
	ResumeSelectionSystem() = default;
	ResumeSelectionSystem(const ResumeSelectionSystem& other);
	ResumeSelectionSystem& operator=(const ResumeSelectionSystem& other);

	ResumeSelectionSystem(ResumeSelectionSystem&& other) noexcept = default;
	ResumeSelectionSystem& operator=(ResumeSelectionSystem&& other) noexcept = default;

	void addRequirement(const Requirement& requirement);
	void addResume(const Resume& resume);
	Resume* findResume(const std::string& email);
	const Resume* findResume(const std::string& email) const;
	void removeResume(const std::string& email);
	const ResumePool& getPool() const;
};