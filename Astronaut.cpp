#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class Person
{
protected:
    string name;

public:
    // Constructor
    Person(const string &name)
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
            this->name = "Unknown";
        }
    }

    // Pure virtual function to make Person an abstract class
    virtual void introduce() const = 0; 

    // Virtual Destructor
    virtual ~Person() {}
};

// Derived class: Astronaut
class Astronaut : public Person
{
private:
    static int totalAstronauts;
    string role;
    int experience;

public:
    // Constructor
    Astronaut(const string &name, const string &role, int experience) : Person(name)
    {
        setRole(role);
        setExperience(experience);
        totalAstronauts++;
    }

    // Destructor
    ~Astronaut()
    {
        totalAstronauts--;
    }

    string getRole() const
    {
        return this->role;
    }

    void setRole(const string &role)
    {
        if (!role.empty())
        {
            this->role = role;
        }
        else
        {
            this->role = "Scientist";
        }
    }

    int getExperience() const
    {
        return this->experience;
    }

    void setExperience(int experience)
    {
        if (experience >= 0)
        {
            this->experience = experience;
        }
        else
        {
            this->experience = 0;
        }
    }

    // Overriding the pure virtual function
    void introduce() const override
    {
        cout << "I am Astronaut " << this->name << " with the role of " << this->role << " and " << this->experience << " years of experience." << endl;
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

    static int getTotalAstronauts()
    {
        return totalAstronauts;
    }
};

// Initializing static member
int Astronaut::totalAstronauts = 0;