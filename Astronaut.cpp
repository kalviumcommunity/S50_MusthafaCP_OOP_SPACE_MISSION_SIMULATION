#include <iostream>
#include <string>

using namespace std;

class Astronaut {
private:
    string name;
    string role;
    int experience;

public:
    // Constructor using the this pointer
    Astronaut(const string& name, const string& role, int experience) {
        this->name = name;
        this->role = role;
        this->experience = experience;
    }

    // Method to perform an EVA
    void performEVA() {
        cout << this->name << " is performing an EVA." << endl;
    }

    // Method to conduct an experiment
    void conductExperiment(const string& experimentName) {
        cout << this->name << " is conducting experiment: " << experimentName << "." << endl;
    }

    // Method to return the current object (for demonstration purposes)
    Astronaut* getSelf() {
        return this;
    }

    // Method to get the astronaut's name
    string getName() const {
        return this->name;
    }
};
