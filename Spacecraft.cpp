#include <iostream>
#include <string>

using namespace std;

class Spacecraft
{
private:
    string name;
    float fuel;
    int crewCapacity;

public:
    Spacecraft(const string &name, float fuel, int crewCapacity)
    {
        this->name = name;
        this->fuel = fuel;
        this->crewCapacity = crewCapacity;
    }

    void launch()
    {
        if (this->fuel > 0)
        {
            cout << this->name << " is launching with " << this->fuel << " units of fuel." << endl;
        }
        else
        {
            cout << this->name << " cannot launch due to insufficient fuel." << endl;
        }
    }

    void land()
    {
        cout << this->name << " is landing." << endl;
    }

    Spacecraft &refuel(float amount)
    {
        this->fuel += amount;
        cout << this->name << " has been refueled to " << this->fuel << " units of fuel." << endl;
        return *this;
    }
};
