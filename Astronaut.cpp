#include <iostream>
#include <string>
using namespace std;
class Astronaut
{
private:
    string name;
    string role;
    int experience;

public:
    Astronaut(const string &astronautName, const string &astronautRole, int astronautExperience)
        : name(astronautName), role(astronautRole), experience(astronautExperience) {}

    void performEVA()
    {
        cout << name << " is performing an EVA." << endl;
    }

    void conductExperiment(const string &experimentName)
    {
        cout << name << " is conducting experiment: " << experimentName << "." << endl;
    }
};
