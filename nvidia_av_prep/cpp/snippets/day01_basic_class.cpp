#include <iostream>

class Sensor
{
private:
    int id;

public:
    Sensor(int sensorId) : id(sensorId)
    {
        std::cout << "Constructor: Sensor " << id << " created\n";
    }

    ~Sensor()
    {
        std::cout << "Destructor: Sensor " << id << " destroyed\n";
    }

    void print() const
    {
        std::cout << "Sensor ID: " << id << "\n";
    }
};

int main()
{
    Sensor s1(101);
    s1.print();
    return 0;
}
