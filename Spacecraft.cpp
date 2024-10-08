#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string name;

public:
    // Constructor
    Vehicle(const string &name)
    {
        setName(name);
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
            this->name = "Unnamed Vehicle";
        }
    }

    // Virtual function to demonstrate polymorphism
    virtual void launch() const
    {
        cout << this->name << " (Vehicle) is launching..." << endl;
    }

    // Virtual Destructor to ensure proper cleanup
    virtual ~Vehicle() {}
};


class Spacecraft : public Vehicle
{
private:
    static int missionCount;
    float fuel;
    int crewCapacity;

public:
    // Constructor
    Spacecraft(const string &name, float fuel, int crewCapacity) : Vehicle(name)
    {
        setFuel(fuel);
        setCrewCapacity(crewCapacity);
    }

    // Destructor
    ~Spacecraft()
    {
        missionCount--;
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
            this->crewCapacity = 1;
        }
    }

    // Overriding the virtual function for polymorphism
    void launch() const override
    {
        if (this->fuel > 0)
        {
            cout << this->name << " (Spacecraft) is launching with " << this->fuel << " units of fuel." << endl;
            missionCount++;
        }
        else
        {
            cout << this->name << " (Spacecraft) cannot launch due to insufficient fuel." << endl;
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