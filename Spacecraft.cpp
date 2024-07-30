#include <iostream>
#include <string>
using namespace std;
class Spacecraft {
private:
    string name;
    float fuel;
    int crewCapacity;

public:
    Spacecraft(const string& spacecraftName, float initialFuel, int capacity)
        : name(spacecraftName), fuel(initialFuel), crewCapacity(capacity) {}

    void launch() {
        if (fuel > 0) {
            cout << name << " is launching with " << fuel << " units of fuel." << endl;
        } else {
            cout << name << " cannot launch due to insufficient fuel." << endl;
        }
    }

    void land() {
        cout << name << " is landing." << endl;
    }
};
