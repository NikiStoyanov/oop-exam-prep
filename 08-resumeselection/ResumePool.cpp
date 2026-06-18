#include "ResumePool.h"

Resume* ResumePool::findByEmail(const std::string& email) {
    return findFirst([&email](const Resume& resume){
        return resume.getEmail() == email;
        });
}

const Resume* ResumePool::findByEmail(const std::string& email) const {
    return findFirst([&email](const Resume& resume) {
        return resume.getEmail() == email;
        });
}

std::vector<Resume> ResumePool::filterBySkill(const std::string& skill) {
    return filter([&skill](const Resume& resume) {
        for (const auto& s : resume.getSkills()) {
            if (s == skill) {
                return true;
            }
        }

        return false;
        });
}

const std::vector<Resume> ResumePool::filterBySkill(const std::string& skill) const {
    return filter([&skill](const Resume& resume) {
        for (const auto& s : resume.getSkills()) {
            if (s == skill) {
                return true;
            }
        }

        return false;
        });
}

double ResumePool::averageSalary() const {
    if (isEmpty()) {
        return 0;
    }

    double sum = 0;
    
    for (const auto& r : items) {
        sum += r.getSalary();
    }


    return sum / size();
}
