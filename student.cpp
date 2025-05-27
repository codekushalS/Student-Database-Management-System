#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    char grade;
    Student(int roll, string n, char g) : rollNumber(roll), name(n), grade(g) {}

    // Display student data
    void displayStudent() {
        cout<<"Roll Number: "<<rollNumber<<"\n"
            <<"Name: "<< name<<"\n"
            <<"Grade: "<< grade<<"\n";
    }
};

class Node {
public:
    Student student;
    Node* next;

    Node(Student s) : student(s), next(nullptr) {}
};

class StudentDatabase {
private:
    Node* head;

public:
    StudentDatabase() : head(nullptr) {}

    void loadFromFile(StudentDatabase& db) {
        ifstream inFile("students.txt", ios::in);
        int roll;
        string name;
        char grade;

        while (inFile >> roll >> name >> grade) {
            db.addStudent(roll, name, grade);
        }
        inFile.close();
        cout << "Data loaded from file.\n";
    }

    void saveToFile(StudentDatabase& db) {
        ofstream outFile("students.txt", ios::out);
        
        Node* temp = db.head;
        while (temp) {
            outFile << temp->student.rollNumber << "\n"
                    << temp->student.name << "\n"
                    << temp->student.grade << "\n";
            temp = temp->next;
        }
        outFile.close();
        cout << "Data saved to file.\n";
    }

    // Function to add a student to the list
    void addStudent(int roll, string name, char grade) {
        Student newStudent(roll, name, grade);
        Node* newNode = new Node(newStudent);
        
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Student added successfully!\n";
    }

    // Function to update student details (based on roll number)
    void updateStudent(int roll, string newName, char newGrade) {
        Node* temp = head;
        while (temp) {
            if (temp->student.rollNumber == roll) {
                temp->student.name = newName;
                temp->student.grade = newGrade;
                cout << "Student updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    // Function to delete a student by roll number
    void deleteStudent(int roll) {
        if (!head) {
            cout << "Database is empty!\n";
            return;
        }

        if (head->student.rollNumber == roll) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully!\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->student.rollNumber != roll) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Student deleted successfully!\n";
        } else {
            cout << "Student not found!\n";
        }
    }

    // Function to search for a student by roll number
    void searchStudent(int roll) {
        Node* temp = head;
        while (temp) {
            if (temp->student.rollNumber == roll) {
                temp->student.displayStudent();
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!\n";
    }

    // Function to display all students
    void displayAll() {
        Node* temp = head;
        while (temp) {
            temp->student.displayStudent();
            cout << "---------------------\n";
            temp = temp->next;
        }
    }
};