#pragma once
#include "Patient.h"
#include "Ward.h"
#include <algorithm>
#include <numeric>

class Hospital {
private:
	std::string name;
	std::vector<Ward> wards;

	Hospital(std::string name);

public:
	Hospital(const Hospital&) = delete;
	Hospital& operator=(const Hospital&) = delete;

	static Hospital& getInstance();
	void setName(const std::string& newName);
	const std::string& getName() const;

	void addWard(const std::string& name);
	void removeWard(const std::string& name);
	Ward* findWard(const std::string& name);
	const Ward* findWard(const std::string& name) const;

	Ward& operator[](const std::string& name);
	std::vector<const Ward*> getPatientInWards(const std::string& egn) const;
	unsigned countPatientWards(const std::string& egn) const;

	friend std::ostream& operator<<(std::ostream& os, const Hospital& hospital);
	explicit operator bool() const;
};