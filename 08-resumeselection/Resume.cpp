#include "Resume.h"

Resume::Resume(std::string firstName, std::string lastName, std::string email, unsigned age, unsigned yearsOfExperience, const std::vector<std::string>& skills, double salary)
    : firstName(std::move(firstName)), lastName(std::move(lastName)), email(std::move(email)), age(age), yearsOfExperience(yearsOfExperience), skills(skills) {
    if (salary < 0) {
        throw std::invalid_argument("Salary must be a positive number!");
    }

    this->salary = salary;
}

const std::string& Resume::getFirstName() const {
    return firstName;
}

const std::string& Resume::getLastName() const {
    return lastName;
}

const std::string& Resume::getEmail() const {
    return email;
}

unsigned Resume::getAge() const {
    return age;
}

unsigned Resume::getYearsOfExperience() const {
    return yearsOfExperience;
}

const std::vector<std::string>& Resume::getSkills() const {
    return skills;
}

double Resume::getSalary() const {
    return salary;
}

std::ostream& operator<<(std::ostream& os, const Resume& r) {
    os << r.getFirstName() << " " << r.getLastName() << " (" << r.getEmail() << ")";
    return os;
}