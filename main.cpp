#include <iostream>
#include <string>
#include "Astronaut.cpp"
#include "Spacecraft.cpp"

using namespace std;

int main()
{
    string astronautName;
    string astronautRole;
    int astronautExperience;
    string roles[] = {"Commander", "Pilot", "Engineer", "Scientist"};
    vector<Astronaut*> astronauts;

    char addMore;
    do
    {
        cout << "Enter the name of the astronaut: ";
        getline(cin, astronautName);

        int roleChoice;
        cout << "Choose a role for the astronaut:" << endl;
        for (int j = 0; j < 4; ++j)
        {
            cout << j + 1 << ". " << roles[j] << endl;
        }
        cout << "Enter role number: ";
        cin >> roleChoice;
        cin.ignore();

        if (roleChoice >= 1 && roleChoice <= 4)
        {
            astronautRole = roles[roleChoice - 1];
        }
        else
        {
            cout << "Invalid choice. Defaulting to Scientist." << endl;
            astronautRole = "Scientist";
        }

        cout << "Enter the experience (in years) of the astronaut: ";
        cin >> astronautExperience;
        cin.ignore();

        astronauts.push_back(new Astronaut(astronautName, astronautRole, astronautExperience));

        cout << "Add another astronaut? (y/n): ";
        cin >> addMore;
        cin.ignore();

    } while (addMore == 'y' || addMore == 'Y');


    string spacecraftName;
    float spacecraftFuel;
    int spacecraftCrewCapacity;

    cout << "Enter the name of the spacecraft: ";
    getline(cin, spacecraftName);
    cout << "Enter the initial fuel of the spacecraft: ";
    cin >> spacecraftFuel;
    cout << "Enter the crew capacity of the spacecraft: ";
    cin >> spacecraftCrewCapacity;

    Spacecraft *spacecraft = new Spacecraft(spacecraftName, spacecraftFuel, spacecraftCrewCapacity);

    cout << endl << endl;

    spacecraft->launch();

    for (auto astronaut : astronauts)
    {
        if (astronaut->getRole() == "Engineer")
        {
            cout << astronaut->getName() << " is performing maintenance tasks." << endl;
        }
        else if (astronaut->getRole() == "Scientist")
        {
            astronaut->conductExperiment("Microgravity Study");
        }
        else if (astronaut->getRole() == "Pilot")
        {
            cout << astronaut->getName() << " is assisting with navigation." << endl;
        }
        else if (astronaut->getRole() == "Commander")
        {
            cout << astronaut->getName() << " is overseeing the mission." << endl;
        }
        astronaut->performEVA();
    }

    spacecraft->refuel(50.0).launch();
    spacecraft->land();

    cout << "Total number of astronauts: " << Astronaut::getTotalAstronauts() << endl;
    cout << "Total number of missions: " << Spacecraft::getMissionCount() << endl;

    for (int i = 0; i < astronauts.size(); ++i)
    {
        Astronaut *self = astronauts[i]->getSelf();
        cout << "Current astronaut " << i + 1 << ": " << endl
             << self->getName() << endl
             << self->getRole() << endl
             << self->getExperience() << " years experienced" << endl;

        cout << endl;
        cout << endl;
    }

    delete spacecraft;
    for (auto astronaut : astronauts)
    {
        delete astronaut;
    }
    
    return 0;
}
