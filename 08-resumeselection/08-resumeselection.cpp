#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "Resume.h"
#include "Requirement.h"
#include "MinExperienceRequirement.h"
#include "SkillRequirement.h"
#include "MinAgeRequirement.h"
#include "MaxSalaryRequirement.h"
#include "Pool.hpp"
#include "ResumePool.h"
#include "ResumeSelectionSystem.h"

int main() {
    std::vector<std::pair<std::string, std::string>> config = {
        {"min_experience", "3"},
        {"skill",          "C++"},
        {"skill",          "OOP"},
        {"max_salary",     "8000"},
        {"min_age",        "21"},
    };

    ResumeSelectionSystem system;

    for (const auto& [type, value] : config) {
        if (type == "min_experience") {
            system.addRequirement(MinExperienceRequirement(std::stoul(value)));
        }
        else if (type == "skill") {
            system.addRequirement(SkillRequirement(value));
        }
        else if (type == "min_age") {
            system.addRequirement(MinAgeRequirement(std::stoul(value)));
        }
        else if (type == "max_salary") {
            system.addRequirement(MaxSalaryRequirement(std::stod(value)));
        }
    }

    Resume r1("Ivan", "Ivanov", "ivan@mail.com", 25, 5, { "C++", "OOP", "SQL" }, 7000.0);
    std::cout << "--- Test 1: Successful addition ---\n";
    try {
        system.addResume(r1);
        std::cout << "Accepted: " << r1 << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    Resume r2("Maria", "Petrova", "maria@mail.com", 19, 1, { "Java" }, 9000.0);
    std::cout << "\n--- Test 2: Rejected resume ---\n";
    try {
        system.addResume(r2);
        std::cout << "Accepted: " << r2 << "\n";
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "--- Test 3: Duplicated email ---\n";
    try {
        system.addResume(r1);
        std::cout << "Accepted: " << r1 << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Declined: " << e.what() << "\n";
    }

    std::cout << "\n--- Test 4: Search ---\n";
    auto found = system.findResume("ivan@mail.com");
    if (found) {
        std::cout << "Found resume: " << *found << "\n";
    }

    std::cout << "\n--- Test 5: Filtering and statistics ---\n";
    auto cppDevs = system.getPool().filterBySkill("C++");
    std::cout << "C++ candidates: " << cppDevs.size() << "\n";
    std::cout << "Average desired salary: " << system.getPool().averageSalary() << "\n";

    std::cout << "\n--- Test 6: Template Pool with another type ---\n";
    Pool<std::string> tags;
    tags.add("senior");
    tags.add("remote");
    tags.add("junior");

    auto seniorTags = tags.filter([](const std::string& t) { return t == "senior"; });
    std::cout << "Found 'senior' tags: " << seniorTags.size() << "\n";

    std::cout << "\n--- Test 7: Copying the system ---\n";
    ResumeSelectionSystem system2 = system;

    system2.addRequirement(SkillRequirement("Python"));

    std::cout << "The systems are copied successfully and work independently!\n";

    return 0;
}