#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class AutonomousTruck {
private:
    int id;
    double x, y;
    double fuel;
    bool active;

public:
    AutonomousTruck(int truckId, double startX, double startY)
        : id(truckId), x(startX), y(startY), fuel(100), active(true) {}

    void move(double dx, double dy) {

        if (!active)
            return;

        x += dx;
        y += dy;

        fuel -= 5;

        if (fuel <= 0) {
            fuel = 0;
            active = false;
        }
    }

    void logData(ofstream& file) {

        file << id << ","
             << x << ","
             << y << ","
             << fuel << ","
             << active << endl;
    }

    void display() {

        cout << "Truck " << id
             << " | Position (" << x << "," << y << ")"
             << " | Fuel: " << fuel
             << "% | Status: "
             << (active ? "ACTIVE" : "OFFLINE")
             << endl;
    }
};

int main() {

    vector<AutonomousTruck> fleet;

    fleet.push_back(AutonomousTruck(101, 0, 0));
    fleet.push_back(AutonomousTruck(102, 10, 5));
    fleet.push_back(AutonomousTruck(103, 20, 10));

    ofstream logFile("fleet_log.csv");

    logFile << "ID,X,Y,Fuel,Active\n";

    fleet[0].move(5, 3);
    fleet[1].move(-2, 4);
    fleet[2].move(-6, -1);

    cout << "=== Fleet Status ===\n";

    for (auto& truck : fleet) {
        truck.display();
        truck.logData(logFile);
    }

    logFile.close();

    cout << "\nFleet data logged to fleet_log.csv\n";

    return 0;
}
