#include "Hospital.h"

int main() {
    Hospital& hosp = Hospital::getInstance();

    std::string cardiology = "Cardiology";
    std::string neurology = "Neurology";
    hosp.addWard(cardiology);
    hosp.addWard(neurology);

    // 1. Create patients properly with shared pointers
    auto p1 = std::make_shared<Patient>("John Doe", "1234567890", "Flu", 101);
    auto p2 = std::make_shared<Patient>("Jane Smith", "0987654321", "Cold", 102);

    // 2. Add them to the wards
    hosp[cardiology].addPatient(p1);
    hosp[cardiology].addPatient(p2);
    hosp[neurology].addPatient(p2);

    // 3. Chained call to update diagnosis
    hosp[cardiology]("1234567890", "Pneumonia")("0987654321", "Asthma");

    std::cout << "--- Hospital state after admission ---" << std::endl;
    std::cout << hosp << std::endl;

    std::cout << "--- Searching for patient in wards ---" << std::endl;
    std::string searchEgn = "0987654321"; // Searching for Jane Smith

    // Get the vector of pointers to the wards
    auto foundWards = hosp.getPatientInWards(searchEgn);
    std::cout << "Patient with EGN " << searchEgn << " is found in:" << std::endl;
    for (const auto& w : foundWards) {
        // Use arrow operator because w is a pointer!
        std::cout << "- " << w->getName() << std::endl;
    }

    std::cout << "Total wards admitted to: "
        << hosp.countPatientWards(searchEgn) << std::endl;

    std::cout << "\n--- Testing for overcrowding (operator bool) ---" << std::endl;
    if (hosp) {
        std::cout << "Warning: The hospital is overcrowded (average >= 20 patients per ward)!" << std::endl;
    }
    else {
        std::cout << "The hospital is operating at normal capacity." << std::endl;
    }

    std::cout << "\n--- Discharging and closing ---" << std::endl;

    // Discharge Jane from Cardiology
    hosp[cardiology].removePatient(searchEgn);
    std::cout << "After discharging Jane from Cardiology, she is in "
        << hosp.countPatientWards(searchEgn) << " ward(s)." << std::endl;

    // Close the Neurology ward completely
    hosp.removeWard(neurology);
    std::cout << "After closing Neurology, the hospital looks like this:" << std::endl;
    std::cout << hosp << std::endl;

    return 0;
}
