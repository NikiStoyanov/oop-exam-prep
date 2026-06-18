#include <iostream>
#include <print>
#include <vector>
#include "TrafficControlSystem.h"
#include "VehicleFactory.h"

int main() {
    TrafficControlSystem cat;

    std::cout << "--- 1. Adding Vehicles via Factory ---\n";
    try {
        // Using the Factory pattern to create objects from formatted strings
        auto car1 = VehicleFactory::createVehicle("Car CB1234AB Ivan Toyota Corolla 2018");
        auto car2 = VehicleFactory::createVehicle("Car CA9999XX Petar BMW 320i 2010");
        auto moto = VehicleFactory::createVehicle("Motorcycle B1111BB Georgi 280");

        // Transferring ownership to the system using std::move
        cat.addVehicle(std::move(car1));
        cat.addVehicle(std::move(car2));
        cat.addVehicle(std::move(moto));

        std::cout << "Vehicles successfully registered.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Creation error: " << e.what() << '\n';
    }

    std::cout << "\n--- 2. Issuing Tickets ---\n";
    try {
        // Issuing tickets for registered plate numbers
        cat.issueTicket("CB1234AB", 50.0, "2026-06-18");
        cat.issueTicket("CB1234AB", 150.0, "2026-06-19");
        cat.issueTicket("B1111BB", 300.0, "2026-06-20");
        std::cout << "Tickets successfully issued.\n";

        // Uncommenting the line below will throw an exception (vehicle not found)
        // cat.issueTicket("XX0000YY", 100.0, "2026-06-20"); 
    }
    catch (const std::exception& e) {
        std::cerr << "Expected exception: " << e.what() << '\n';
    }

    std::cout << "\n--- 3. Searching for a Vehicle ---\n";
    // findVehicle returns a const raw pointer to avoid ownership transfer (Observer)
    const Vehicle* foundCar = cat.findVehicle("CB1234AB");
    if (foundCar) {
        std::cout << "Vehicle found:\n";
        foundCar->displayInfo();
    }
    else {
        std::cout << "Vehicle not found.\n";
    }

    std::cout << "\n--- 4. Filtering Tickets (Unpaid) ---\n";
    // Passing a lambda expression as a predicate to filter unpaid tickets
    auto unpaidTickets = cat.findTickets([](const Ticket& t) {
        return !t.getIsPaid();
        });

    std::cout << "Number of unpaid tickets: " << unpaidTickets.size() << "\n";
    for (const auto* ticket : unpaidTickets) {
        ticket->displayInfo();
    }

    std::cout << "\n--- 5. Paying a Ticket ---\n";
    // Retrieving non-const ticket pointers for a specific vehicle to modify them
    std::vector<Ticket*> carTickets = cat.findTickets("CB1234AB");
    if (!carTickets.empty()) {
        std::cout << "Paying the first ticket for CB1234AB...\n";
        carTickets[0]->pay(); // Modifies the actual ticket instance in the system
        carTickets[0]->displayInfo();
    }

    std::cout << "\n--- 6. Removing a Ticket and a Vehicle ---\n";
    try {
        // Removing data to test the std::erase_if implementation
        cat.removeTicket("B1111BB");
        std::cout << "Ticket for B1111BB removed.\n";

        cat.removeVehicle("CA9999XX");
        std::cout << "Vehicle CA9999XX removed.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Deletion error: " << e.what() << '\n';
    }

    return 0;
}