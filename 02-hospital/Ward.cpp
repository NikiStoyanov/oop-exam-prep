#include "Ward.h"
#include <stdexcept>
#include <algorithm>

Ward::Ward(std::string name) : name(std::move(name)) {}

const std::string& Ward::getName() const {
	return name;
}

void Ward::addPatient(const std::shared_ptr<Patient>& patient) {
    if (!patient) {
        throw std::invalid_argument("Patient cannot be null");
	}

    bool isAlreadyInWard = std::any_of(patients.begin(), patients.end(), [&patient](const std::shared_ptr<Patient>& p) {
            return p && (p->getEgn() == patient->getEgn());
        });

    if(isAlreadyInWard) {
        throw std::logic_error("Patient with the same EGN already exists in this ward");
    }
    
	patients.push_back(patient);
}

bool Ward::removePatient(const std::string& egn) {
    if (egn.size() != 10) {
        throw std::invalid_argument("EGN must be a 10-digit number");
	}

    auto count = std::erase_if(patients, [&egn](const std::shared_ptr<Patient>& p) {
            return p && (p->getEgn() == egn);
		});

    return count > 0;
}

std::shared_ptr<Patient> Ward::findPatient(const std::string& egn) const {
    if (egn.size() != 10) {
        throw std::invalid_argument("EGN must be a 10-digit number");
    }

    auto it = std::find_if(patients.begin(), patients.end(), [&egn](const std::shared_ptr<Patient>& p) {
        return p && (p->getEgn() == egn);
        });

	return (it != patients.end()) ? *it : nullptr;
}

unsigned Ward::getPatientCount() const {
    return patients.size();
}

Ward& Ward::operator()(const std::string& egn, const std::string& newDiagnosis) {
	auto patient = findPatient(egn);

    if (patient) {
        patient->setDiagnosis(newDiagnosis);
    }
    else {
        throw std::invalid_argument("Patient with this EGN not found in the ward.");
    }

    return *this;
}

Ward::operator bool() const {
    return patients.size() > 0;
}

std::ostream& operator<<(std::ostream& os, const Ward& ward) {
	os << "Ward: " << ward.name << "\nPatients:\n";
	os << "-----------------------------------\n";
    for (const auto& patient : ward.patients) {
        if (patient) {
            os << *patient << "\n";
		}
	}
    os << "-----------------------------------\n";
	return os;
}
