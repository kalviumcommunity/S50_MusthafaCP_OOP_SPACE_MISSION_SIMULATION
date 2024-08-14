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
    Astronaut() : name(""), role(""), experience(0) {}

    Astronaut(const string &name, const string &role, int experience)
    {
        this->name = name;
        this->role = role;
        this->experience = experience;
    }

    void performEVA()
    {
        cout << this->name << " is performing an EVA." << endl;
    }

    void conductExperiment(const string &experimentName)
    {
        cout << this->name << " is conducting experiment: " << experimentName << "." << endl;
    }

    Astronaut *getSelf()
    {
        return this;
    }

    string getName() const
    {
        return this->name;
    }

    string getRole() const
    {
        return this->role;
    }

    int getExperience() const
    {
        return this->experience;
    }
};

