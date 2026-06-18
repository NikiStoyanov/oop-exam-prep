#include "Hospital.h"

Hospital::Hospital(std::string name) : name(std::move(name)) {}

Hospital& Hospital::getInstance() {
	static Hospital instance("City Hospital");

	return instance;
}

void Hospital::setName(const std::string& newName) {
	name = newName;
}

const std::string& Hospital::getName() const {
	return name;
}

void Hospital::addWard(const std::string& name) {
	if (findWard(name) != nullptr) {
		throw std::logic_error("Ward with the same name already exists in the hospital");
	}

	wards.emplace_back(name);
}

void Hospital::removeWard(const std::string & name) {
	std::erase_if(wards, [&name](const Ward& ward) {
		return ward.getName() == name;
		});
}

Ward* Hospital::findWard(const std::string& name) {
	auto it = std::find_if(wards.begin(), wards.end(), [&name](const Ward& ward) {
		return ward.getName() == name;
		});

	return (it != wards.end()) ? &(*it) : nullptr;
}

const Ward* Hospital::findWard(const std::string& name) const {
	auto it = std::find_if(wards.begin(), wards.end(), [&name](const Ward& ward) {
		return ward.getName() == name;
		});

	return (it != wards.end()) ? &(*it) : nullptr;
}

Ward& Hospital::operator[](const std::string& name) {
	Ward* found = findWard(name);

	if (!found) {
		throw std::out_of_range("Ward with the given name not found in the hospital");
	}

	return *found;
}

std::vector<const Ward*> Hospital::getPatientInWards(const std::string& egn) const {
	std::vector<const Ward*> foundIn;

	for (const auto& ward : wards) {
		if (ward.findPatient(egn) != nullptr) {
			foundIn.push_back(&ward);
		}
	}

	return foundIn;
}

unsigned Hospital::countPatientWards(const std::string& egn) const {
	return std::count_if(wards.begin(), wards.end(), [&egn](const auto& ward) {
		return ward.findPatient(egn) != nullptr;
		});
}

Hospital::operator bool() const {
	unsigned wardsCount = wards.size();
	unsigned patientsCount = std::accumulate(wards.begin(), wards.end(), 0u, [](unsigned sum, const Ward& ward) {
		return sum + ward.getPatientCount();
		});

	double avgPatientsPerWard = (wardsCount > 0) ? (double)patientsCount / wardsCount : 0;

	return avgPatientsPerWard >= 20;
}

std::ostream& operator<<(std::ostream& os, const Hospital& hospital) {
	os << "Hospital: " << hospital.name << "\nWards:\n";
	os << std::string(20, '-') << "\n";
	for (const auto& ward : hospital.wards) {
		os << ward << "\n" << std::string(20, '-') << "\n";
	}

	return os;
}
