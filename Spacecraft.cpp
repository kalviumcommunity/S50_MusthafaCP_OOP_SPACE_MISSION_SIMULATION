#include <iostream>
#include <string>

using namespace std;

class Spacecraft
{
private:
    static int missionCount;
    string name;
    float fuel;
    int crewCapacity;

public: 
    //Constructor
    Spacecraft(const string &name, float fuel, int crewCapacity)
    {
        setName(name);
        setFuel(fuel);
        setCrewCapacity(crewCapacity);
    }

    //Destructor
    ~Spacecraft()
    {
        missionCount--;
    }


    string getName() const
    {
        return this->name;
    }

    void setName(const string &name)
    {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            this->name = "Unnamed Spacecraft";
        }
    }

    float getFuel() const
    {
        return this->fuel;
    }

    void setFuel(float fuel)
    {
        if (fuel >= 0)
        {
            this->fuel = fuel;
        }
        else
        {
            this->fuel = 0;
        }
    }

    int getCrewCapacity() const
    {
        return this->crewCapacity;
    }

    void setCrewCapacity(int crewCapacity)
    {
        if (crewCapacity > 0)
        {
            this->crewCapacity = crewCapacity;
        }
        else
        {
            this->crewCapacity = 1; // minimum crew capacity
        }
    }

    void launch()
    {
        if (this->fuel > 0)
        {
            cout << this->name << " is launching with " << this->fuel << " units of fuel." << endl;
            missionCount++;
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
        setFuel(this->fuel + amount);
        cout << this->name << " has been refueled to " << this->fuel << " units of fuel." << endl;
        return *this;
    }

    static int getMissionCount()
    {
        return missionCount;
    }
};

int Spacecraft::missionCount = 0;
