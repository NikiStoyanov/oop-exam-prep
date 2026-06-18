#pragma once
#include "Pool.hpp"
#include "Resume.h"

class ResumePool : public Pool<Resume> {
private:

public:
	Resume* findByEmail(const std::string& email);
	const Resume* findByEmail(const std::string& email) const;

	std::vector<Resume> filterBySkill(const std::string& skill);
	const std::vector<Resume> filterBySkill(const std::string& skill) const;

	double averageSalary() const;
};

