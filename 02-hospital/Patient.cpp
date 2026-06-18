#include "Patient.h"
#include <stdexcept>
#include <algorithm>

Patient::Patient(std::string name, std::string egn, std::string diagnosis, unsigned room)
	: name(std::move(name)), diagnosis(std::move(diagnosis)), room(room) {
	if (egn.size() != 10) {
        throw std::invalid_argument("EGN must be a 10-digit number");
    }

	this->egn = egn;
}

const std::string& Patient::getName() const {
    return name;
}

const std::string& Patient::getEgn() const {
    return egn;
}

const std::string& Patient::getDiagnosis() const {
	return diagnosis;
}

void Patient::setDiagnosis(const std::string& newDiagnosis) {
	diagnosis = newDiagnosis;
}

unsigned Patient::getRoom() const {
    return room;
}

std::strong_ordering operator<=>(const Patient& p1, const Patient& p2) {
	return p1.egn <=> p2.egn;
}

std::ostream& operator<<(std::ostream& os, const Patient& patient) {
	return os << "Patient: " << patient.name << ", EGN: " << patient.egn << ", Diagnosis: " << patient.diagnosis << ", Room: " << patient.room;
}
