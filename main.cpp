#include <iostream>
#include <string>
#include "Astronaut.cpp"
#include "Spacecraft.cpp"

using namespace std;

int main() {
    int NUM_ASTRONAUTS;
    cout << "Enter the number of astronauts: ";
    cin >> NUM_ASTRONAUTS;
    cin.ignore(); 

    Astronaut astronauts[NUM_ASTRONAUTS];

    string astronautName;
    string astronautRole;
    int astronautExperience;

    string roles[] = {"Commander", "Pilot", "Engineer", "Scientist"};

    // Collect astronaut details
    for (int i = 0; i < NUM_ASTRONAUTS; ++i) {
        cout << "Enter the name of astronaut " << (i + 1) << ": ";
        getline(cin, astronautName);
        
        int roleChoice;
        cout << "Choose a role for astronaut " << (i + 1) << ":" << endl;
        for (int j = 0; j < 4; ++j) {
            cout << j + 1 << ". " << roles[j] << endl;
        }
        cout << "Enter role number: ";
        cin >> roleChoice;
        cin.ignore();
        
        if (roleChoice >= 1 && roleChoice <= 4) {
            astronautRole = roles[roleChoice - 1];
        } else {
            cout << "Invalid choice. Defaulting to Scientist." << endl;
            astronautRole = "Scientist";
        }

        cout << "Enter the experience (in years) of astronaut " << (i + 1) << ": ";
        cin >> astronautExperience;
        cin.ignore();

        astronauts[i] = Astronaut(astronautName, astronautRole, astronautExperience);
    }

    // Spacecraft setup
    string spacecraftName;
    float spacecraftFuel;
    int spacecraftCrewCapacity;

    cout << "Enter the name of the spacecraft: ";
    getline(cin, spacecraftName);
    cout << "Enter the initial fuel of the spacecraft: ";
    cin >> spacecraftFuel;
    cout << "Enter the crew capacity of the spacecraft: ";
    cin >> spacecraftCrewCapacity;

    Spacecraft spacecraft(spacecraftName, spacecraftFuel, spacecraftCrewCapacity);


    // Spacecraft launch
    spacecraft.launch();

    // Astronaut tasks
    for (int i = 0; i < NUM_ASTRONAUTS; ++i) {
        if (astronauts[i].getRole() == "Engineer") {
            cout << astronauts[i].getName() << " is performing maintenance tasks." << endl;
        } else if (astronauts[i].getRole() == "Scientist") {
            astronauts[i].conductExperiment("Microgravity Study");
        } else if (astronauts[i].getRole() == "Pilot") {
            cout << astronauts[i].getName() << " is assisting with navigation." << endl;
        } else if (astronauts[i].getRole() == "Commander") {
            cout << astronauts[i].getName() << " is overseeing the mission." << endl;
        }
        astronauts[i].performEVA();
    }

    spacecraft.refuel(50.0).launch();
    spacecraft.land();

    for (int i = 0; i < NUM_ASTRONAUTS; ++i) {
        Astronaut *self = astronauts[i].getSelf();
        cout << "Current astronaut object: " << self->getName() << endl;
    }

    return 0;
}
