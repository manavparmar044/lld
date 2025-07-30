#include <iostream>
#include <vector>
using namespace std;

// --------------------- Doctor ---------------------
class Doctor {
    string name;
    string specialization;
    bool available;

public:
    Doctor(string name, string specialization) {
        this->name = name;
        this->specialization = specialization;
        available = true;
    }

    string getSpecialization() {
        return specialization;
    }

    string getName() {
        return name;
    }

    bool isAvailable() {
        return available;
    }

    void setAvailability(bool status) {
        available = status;
    }

    void showDetails() {
        cout << "👨‍⚕️ Doctor: " << name << " [" << specialization << "] - "
             << (available ? "Available" : "Busy") << endl;
    }
};

// --------------------- Patient ---------------------
class Patient {
    string name;
    int age;
    string illness;

public:
    Patient(string name, int age, string illness) {
        this->name = name;
        this->age = age;
        this->illness = illness;
    }

    string getIllness() {
        return illness;
    }

    string getName() {
        return name;
    }

    void showDetails() {
        cout << "🧑‍⚕️ Patient: " << name << ", Age: " << age
             << ", Illness: " << illness << endl;
    }
};

// --------------------- Appointment ---------------------
class Appointment {
    Doctor* doctor;
    Patient* patient;

public:
    Appointment(Doctor* d, Patient* p) {
        doctor = d;
        patient = p;
    }

    void showAppointment() {
        cout << "📅 Appointment -> ";
        cout << patient->getName() << " with Dr. " << doctor->getName()
             << " (" << doctor->getSpecialization() << ")" << endl;
    }
};

// --------------------- Hospital ---------------------
class Hospital {
    vector<Doctor*> doctors;
    vector<Appointment*> appointments;

public:
    void addDoctor(Doctor* d) {
        doctors.push_back(d);
    }

    void bookAppointment(Patient* p) {
        string illness = p->getIllness();

        for (Doctor* d : doctors) {
            if (d->getSpecialization() == illness && d->isAvailable()) {
                d->setAvailability(false);
                Appointment* a = new Appointment(d, p);
                appointments.push_back(a);
                cout << "✅ Appointment booked successfully!\n";
                return;
            }
        }

        cout << "❌ No available doctor for illness: " << illness << endl;
    }

    void showAppointments() {
        cout << "\n📋 All Appointments:\n";
        for (Appointment* a : appointments) {
            a->showAppointment();
        }
    }

    ~Hospital() {
        for (Doctor* d : doctors) delete d;
        for (Appointment* a : appointments) delete a;
    }
};

int main() {
    Hospital h;

    // Adding doctors
    h.addDoctor(new Doctor("Dr. Smith", "Cardiology"));
    h.addDoctor(new Doctor("Dr. Brown", "Neurology"));
    h.addDoctor(new Doctor("Dr. Watson", "Orthopedics"));

    // Creating patients
    Patient* p1 = new Patient("Alice", 40, "Cardiology");
    Patient* p2 = new Patient("Bob", 55, "Neurology");
    Patient* p3 = new Patient("Charlie", 30, "Orthopedics");
    Patient* p4 = new Patient("Daisy", 45, "Cardiology"); // No doctor now

    // Booking appointments
    h.bookAppointment(p1);
    h.bookAppointment(p2);
    h.bookAppointment(p3);
    h.bookAppointment(p4); // Should fail

    // Show all appointments
    h.showAppointments();

    // Cleanup patients
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}

