#include <bits/stdc++.h>
using namespace std;
#include "Astronaut.cpp"
#include "Spacecraft.cpp"


int main() {
    // Create astronaut objects
    Astronaut astronaut1("Alice", "Commander", 5);
    Astronaut astronaut2("Bob", "Engineer", 3);

    // Create a spacecraft object
    Spacecraft spacecraft("Apollo", 100.0, 3);

    // Simulate mission operations
    spacecraft.launch();
    astronaut1.performEVA();
    astronaut2.conductExperiment("Microgravity Study");
    spacecraft.land();

    return 0;
}
