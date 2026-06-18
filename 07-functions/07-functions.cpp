#include <iostream>
#include <iomanip>
#include <string>

#include "LinearFunction.h"
#include "QuadraticFunction.h"
#include "IntervalRestrictedFunction.h"
#include "PuncturedFunction.h"
#include "PiecewiseFunction.h"
#include "ComposedFunction.h"

void printResult(const std::string& testName, double x, const std::optional<double>& result) {
    std::cout << std::left << std::setw(35) << testName
        << "| x = " << std::setw(4) << x << " | Result = ";
    if (result.has_value()) {
        std::cout << result.value() << "\n";
    }
    else {
        std::cout << "Undefined (std::nullopt)\n";
    }
}

int main() {
    std::cout << "========================================\n";
    std::cout << "       FUNCTION HIERARCHY TESTS         \n";
    std::cout << "========================================\n\n";

    // 1. Basic functions
    std::cout << "--- 1. Basic Functions ---\n";
    LinearFunction linear(2, 1);       // f(x) = 2x + 1
    QuadraticFunction quad(1, -2, 1);  // f(x) = x^2 - 2x + 1

    printResult("Linear: 2x + 1", 3, linear(3));       // Expected: 7
    printResult("Quadratic: x^2 - 2x + 1", 3, quad(3));  // Expected: 4


    // 2. Interval restricted function
    std::cout << "\n--- 2. Restricted Functions ---\n";
    IntervalRestrictedFunction restricted(quad, 0, 5);

    printResult("Restricted Quad [0, 5]", 3, restricted(3)); // Expected: 4
    printResult("Restricted Quad [0, 5]", 6, restricted(6)); // Expected: Undefined

    PuncturedFunction punctured(linear, { 3.0, 5.0 });
    printResult("Punctured Linear {3, 5}", 2, punctured(2)); // Expected: 5
    printResult("Punctured Linear {3, 5}", 3, punctured(3)); // Expected: Undefined


    // 3. Piecewise function
    std::cout << "\n--- 3. Piecewise Function ---\n";
    LinearFunction leftBranch(-1, 0); // f(x) = -x
    LinearFunction rightBranch(1, 0); // f(x) = x
    PiecewiseFunction absValue(leftBranch, rightBranch, 0);

    printResult("Piecewise (Abs Value)", -5, absValue(-5)); // Expected: 5
    printResult("Piecewise (Abs Value)", 5, absValue(5));   // Expected: 5
    printResult("Piecewise (Abs Value)", 0, absValue(0));   // Expected: Undefined


    // 4. Composed function
    std::cout << "\n--- 4. Composed Function ---\n";
    ComposedFunction comp;

    printResult("Empty Composition (Identity)", 42, comp(42)); // Expected: 42

    comp.then(linear).then(quad);
    printResult("Composed (Linear -> Quad)", 3, comp(3)); // Expected: 36

    ComposedFunction compWithUndefined;
    compWithUndefined.then(punctured).then(quad);
    printResult("Composed with Punctured", 2, compWithUndefined(2)); // Expected: 16
    printResult("Composed with Punctured", 3, compWithUndefined(3)); // Expected: Undefined


    std::cout << "\n========================================\n";
    std::cout << "All tests completed. No crashes! :)\n";
    std::cout << "========================================\n";

    return 0;
}