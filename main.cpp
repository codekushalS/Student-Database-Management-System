#include <iostream>
#include "student.cpp"
using namespace std;


int main() {
    StudentDatabase db;
    db.loadFromFile(db); // Load existing student data from file

    int choice;
    do {
        cout << "\nStudent Database Management\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Search Student\n";
        cout << "5. Display All Students\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int roll;
        string name;
        char grade;

        switch (choice) {
            case 1:
                cout << "Enter roll number, name, and grade: ";
                cin >> roll >> name >> grade;
                db.addStudent(roll, name, grade);
                break;

            case 2:
                cout << "Enter roll number, new name, and new grade: ";
                cin >> roll >> name >> grade;
                db.updateStudent(roll, name, grade);
                break;

            case 3:
                cout << "Enter roll number to delete: ";
                cin >> roll;
                db.deleteStudent(roll);
                break;

            case 4:
                cout << "Enter roll number to search: ";
                cin >> roll;
                db.searchStudent(roll);
                break;

            case 5:
                db.displayAll();
                break;

            case 6:
                db.saveToFile(db);  // Save before exiting
                cout << "Exiting... Data saved.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}