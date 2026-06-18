#pragma once
#include <iostream>
#include <string>

class Patient {
private:
	std::string name;
	std::string egn;
	std::string diagnosis;
	unsigned room;

public:
	Patient(std::string name, std::string egn, std::string diagnosis, unsigned room);
	const std::string& getName() const;
	const std::string& getEgn() const;
	const std::string& getDiagnosis() const;
	void setDiagnosis(const std::string& newDiagnosis);
	unsigned getRoom() const;

	friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
	friend std::strong_ordering operator<=>(const Patient& p1, const Patient& p2);
};