#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle{
    string numberPlate;
    string type;

    public:
    Vehicle(string number,string type){
        this->numberPlate = number;
        this->type = type;
    }

    string getNumberPlate() {
        return numberPlate;
    }

    string getType() {
        return type;
    }

    void showInfo() {
        cout << "Vehicle: " << type << ", Number Plate: " << numberPlate << endl;
    }
};

class ParkingSlot{
    int slotNumber;
    bool isOccupied;
    Vehicle *vehicle;

    public:
    ParkingSlot(int num){
        slotNumber = num;
        isOccupied = false;
        vehicle = nullptr;
    }

    bool isAvailable() {
        return !isOccupied;
    }

    int getSlotNumber() {
        return slotNumber;
    }

    void parkVehicle(Vehicle* v) {
        isOccupied = true;
        vehicle = v;

        cout << "Vehicle parked at slot " << slotNumber << endl;
    }

    void removeVehicle() {
        if (isOccupied) {

            cout << "Vehicle with number " << vehicle->getNumberPlate() 
                 << " removed from slot " << slotNumber << endl;
            vehicle = nullptr;
            isOccupied = false;
        }
    }

    Vehicle* getVehicle() {
    return vehicle;
}

    void showSlotStatus() {
        if (isOccupied) {
            cout << "[Slot " << slotNumber << "] Occupied by ";
            vehicle->showInfo();
        } else {
            cout << "[Slot " << slotNumber << "] Available" << endl;
        }
    }
};

class ParkingLot{
    vector<ParkingSlot*> slots;
    public:
    ParkingLot(int totalSlots){
        for (int i = 1; i <= totalSlots; i++) {
            slots.push_back(new ParkingSlot(i));
        }
    }

    void park(Vehicle *v){
        for(ParkingSlot * slot: slots){
            if(slot->isAvailable()){
                slot->parkVehicle(v);
                return;
            }
        }
        cout << "No available slots for vehicle " << v->getNumberPlate() << endl;
    }

    void unpark(string numberPlate) {
    for (ParkingSlot* slot : slots) {
        if (!slot->isAvailable() && slot->getVehicle()->getNumberPlate() == numberPlate) {
            slot->removeVehicle();
            return;
        }
    }

    cout << "Vehicle with number " << numberPlate << " not found in lot." << endl;
}
void showStatus() {
        cout << "\n--- Parking Lot Status ---" << endl;

        for (ParkingSlot* slot : slots) {
            slot->showSlotStatus();
        }
    }

    ~ParkingLot() {
        for (ParkingSlot* slot : slots) {
            delete slot;
        }
    }
};

int main() {
    ParkingLot lot(3);  // A lot with 3 slots

    Vehicle* v1 = new Vehicle("MH12AB1234", "Car");
    Vehicle* v2 = new Vehicle("MH13CD5678", "Bike");
    Vehicle* v3 = new Vehicle("MH14EF9012", "Car");
    Vehicle* v4 = new Vehicle("MH15GH3456", "Truck");

    lot.park(v1);
    lot.park(v2);
    lot.park(v3);
    lot.park(v4);  // No slot available

    lot.showStatus();

    lot.unpark("MH13CD5678");
    lot.showStatus();

    // Clean up
    
    delete v1;
    delete v2;
    delete v3;
    delete v4;

    return 0;
}
