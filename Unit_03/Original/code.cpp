#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    Patient *next;
};

Patient *head = NULL;

// Add Patient
void addPatient() {
    Patient *p = new Patient;

    cout << "Enter ID: ";
    cin >> p->id;
    cout << "Enter Name: ";
    cin >> p->name;

    p->next = head;
    head = p;

    cout << "Patient added.\n";
}

// Display Patients
void display() {
    Patient *temp = head;

    while (temp != NULL) {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name;
        temp = temp->next;
    }
}

// Search Patient
void search() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Patient *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Patient Found: " << temp->name;
            return;
        }
        temp = temp->next;
    }

    cout << "Patient not found.";
}

int main() {
    int choice;

    do {
        cout << "\n\n1. Add Patient";
        cout << "\n2. Display Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addPatient(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: cout << "Exit"; break;
            default: cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}
