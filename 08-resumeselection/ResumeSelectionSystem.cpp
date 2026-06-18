#include "ResumeSelectionSystem.h"

ResumeSelectionSystem::ResumeSelectionSystem(const ResumeSelectionSystem& other)
    : resumes(other.resumes) {
    for (const auto& requirement : other.requirements) {
        requirements.push_back(requirement->clone());
    }
}

ResumeSelectionSystem& ResumeSelectionSystem::operator=(const ResumeSelectionSystem & other) {
    if (this != &other) {
        requirements.clear();

        resumes = other.resumes;

        for (const auto& requirement : other.requirements) {
            requirements.push_back(requirement->clone());
        }
    }

    return *this;
}

void ResumeSelectionSystem::addRequirement(const Requirement& requirement) {
    requirements.push_back(requirement.clone());
}

void ResumeSelectionSystem::addResume(const Resume& resume) {
    if (resumes.findByEmail(resume.getEmail()) != nullptr) {
        throw std::logic_error("Resume with this email already exists!");
    }

    std::vector<std::string> errors;
    for (const auto& req : requirements) {
        auto [passed, reason] = req->check(resume);
        if (!passed) {
            errors.push_back(reason);
        }
    }

    if (!errors.empty()) {
        std::string errorMessage = "Declined because:\n";
        for (const auto& err : errors) {
            errorMessage += "- " + err + "\n";
        }
        throw std::logic_error(errorMessage);
    }

    resumes.add(resume);
}

Resume* ResumeSelectionSystem::findResume(const std::string& email) {
    return resumes.findByEmail(email);
}

const Resume* ResumeSelectionSystem::findResume(const std::string& email) const {
    return resumes.findByEmail(email);
}

void ResumeSelectionSystem::removeResume(const std::string& email) {
    if (resumes.findByEmail(email) == nullptr) {
        throw std::logic_error("Cannot remove: Resume with this email does not exist!");
    }

    resumes.removeItem([&email](const Resume& resume) {
        return resume.getEmail() == email;
        });
}

const ResumePool& ResumeSelectionSystem::getPool() const {
    return resumes;
}