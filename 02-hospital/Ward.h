#pragma once
#include "Patient.h"
#include <vector>
#include <memory>
class Ward {
private:
	std::string name;
	std::vector<std::shared_ptr<Patient>> patients;

public:
	Ward(std::string name);
	const std::string& getName() const;

	void addPatient(const std::shared_ptr<Patient>& patient);
	bool removePatient(const std::string& egn);
	std::shared_ptr<Patient> findPatient(const std::string& egn) const;
	unsigned getPatientCount() const;

	friend std::ostream& operator<<(std::ostream& os, const Ward& ward);
	Ward& operator()(const std::string& egn, const std::string& newDiagnosis);
	explicit operator bool() const;
};