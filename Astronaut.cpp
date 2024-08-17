#include <iostream>
#include <string>

using namespace std;

class Astronaut
{
private:
    static int totalAstronauts;
    string name;
    string role;
    int experience;

public:
    Astronaut(const string &name, const string &role, int experience)
    {
        this->name = name;
        this->role = role;
        this->experience = experience;
        totalAstronauts++;
    }

    ~Astronaut()
    {
        totalAstronauts--;
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

    static int getTotalAstronauts()
    {
        return totalAstronauts;
    }
};


int Astronaut::totalAstronauts = 0;
