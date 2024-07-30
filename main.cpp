#include <iostream>
#include <string>
#include "Astronaut.cpp"
#include "Spacecraft.cpp"
using namespace std;

int main() {
    // Variables for astronaut input
    string astronautName1, astronautRole1;
    int astronautExperience1;

    string astronautName2, astronautRole2;
    int astronautExperience2;

    // Variables for spacecraft input
    string spacecraftName;
    float spacecraftFuel;
    int spacecraftCrewCapacity;

    // Get input for the first astronaut
    cout << "Enter the name of the first astronaut: ";
    getline(cin, astronautName1);
    cout << "Enter the role of the first astronaut: ";
    getline(cin, astronautRole1);
    cout << "Enter the experience (in years) of the first astronaut: ";
    cin >> astronautExperience1;
    cin.ignore(); // Ignore the newline character left in the buffer

    // Get input for the second astronaut
    cout << "Enter the name of the second astronaut: ";
    getline(cin, astronautName2);
    cout << "Enter the role of the second astronaut: ";
    getline(cin, astronautRole2);
    cout << "Enter the experience (in years) of the second astronaut: ";
    cin >> astronautExperience2;
    cin.ignore(); // Ignore the newline character left in the buffer

    // Create astronaut objects
    Astronaut astronaut1(astronautName1, astronautRole1, astronautExperience1);
    Astronaut astronaut2(astronautName2, astronautRole2, astronautExperience2);

    // Get input for the spacecraft
    cout << "Enter the name of the spacecraft: ";
    getline(cin, spacecraftName);
    cout << "Enter the initial fuel of the spacecraft: ";
    cin >> spacecraftFuel;
    cout << "Enter the crew capacity of the spacecraft: ";
    cin >> spacecraftCrewCapacity;

    // Create a spacecraft object
    Spacecraft spacecraft(spacecraftName, spacecraftFuel, spacecraftCrewCapacity);

    // Simulate mission operations
    spacecraft.launch();
    astronaut1.performEVA();
    astronaut2.conductExperiment("Microgravity Study");

    // Demonstrate method chaining using the this pointer
    spacecraft.refuel(50.0).launch();

    spacecraft.land();

    // Demonstrate returning the current object and printing the astronaut's name
    Astronaut* self1 = astronaut1.getSelf();
    cout << "Current astronaut objects: " << self1->getName() << endl;
    Astronaut* self2 = astronaut2.getSelf();
    cout << "Current astronaut objects: " << self2->getName() << endl;

    return 0;
}
