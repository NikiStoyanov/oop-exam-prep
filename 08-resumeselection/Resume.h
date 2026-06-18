#pragma once
#include <string>
#include <vector>
#include <stdexcept>

class Resume {
private:
	std::string firstName;
	std::string lastName;
	std::string email;
	unsigned age;
	unsigned yearsOfExperience;
	std::vector<std::string> skills;
	double salary;

public:
	Resume(std::string firstName, std::string lastName, std::string email, unsigned age, unsigned yearsOfExperience, const std::vector<std::string>& skills, double salary);

	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getEmail() const;
	unsigned getAge() const;
	unsigned getYearsOfExperience() const;
	const std::vector<std::string>& getSkills() const;
	double getSalary() const;
};

