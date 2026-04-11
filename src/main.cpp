#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// ==========================================
// STUDENT 3: Liskov Substitution Principle (LSP)
// Base class focus on common identity only.
// ==========================================
class User {
protected:
    int id;
    string name;
public:
    User(int id, string name) : id(id), name(name) {}
    virtual string getRole() const = 0;
    string getName() const { return name; }
    int getId() const { return id; }
    virtual ~User() {}
};

// ==========================================
// STUDENT 4: Interface Segregation Principle (ISP)
// Splitting big interfaces into small, specific ones.
// ==========================================
class ISubjectViewer {
public:
    virtual void viewSubjects() = 0;
    virtual ~ISubjectViewer() {}
};

class IAccountManager {
public:
    virtual void changeName(string newName) = 0;
    virtual ~IAccountManager() {}
};

// ==========================================
// User Type Classes (LSP & ISP Implementation)
// ==========================================
class Student : public User, public ISubjectViewer {
public:
    using User::User;
    string getRole() const override { return "Student"; }
    void viewSubjects() override { cout << "Displaying enrolled subjects for student...\n"; }
};

class Teacher : public User, public ISubjectViewer, public IAccountManager {
public:
    using User::User;
    string getRole() const override { return "Teacher"; }
    void viewSubjects() override { cout << "Displaying all departmental subjects...\n"; }
    void changeName(string newName) override { this->name = newName; }
};

// ==========================================
// STUDENT 5: Dependency Inversion Principle (DIP)
// High-level logic depends on Abstractions (Interfaces)
// ==========================================
class IAuthRepository {
public:
    virtual bool validate(int id, string pass) = 0;
    virtual ~IAuthRepository() {}
};

// Low-level detail (Mock Database)
class MySQLAuthRepository : public IAuthRepository {
public:
    bool validate(int id, string pass) override {
        return (id == 60032 && pass == "admin123"); // Example check
    }
};

// ==========================================
// STUDENT 1: Single Responsibility Principle (SRP)
// Separate classes for UI, Input, and Business Logic
// ==========================================
class InputHandler {
public:
    static int getLimitInput(int start, int end) {
        int choice;
        while (!(cin >> choice) || choice < start || choice > end) {
            cout << "Invalid! Enter (" << start << "-" << end << "): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        return choice;
    }
};

class UIProvider {
public:
    void showWelcome(string name) { cout << "\nWelcome, " << name << "!\n"; }
    void showMainMenu() {
        cout << "\n1. View Subjects\n2. Logout\nChoice: ";
    }
};

// ==========================================
// STUDENT 2: Open/Closed Principle (OCP)
// Strategy Pattern: Adding new roles doesn't change the Login System
// ==========================================
class SessionManager {
    IAuthRepository& authRepo;
    UIProvider ui;
public:
    SessionManager(IAuthRepository& repo) : authRepo(repo) {}

    void startSession(User* user) {
        ui.showWelcome(user->getName());
        bool active = true;
        while (active) {
            ui.showMainMenu();
            int choice = InputHandler::getLimitInput(1, 2);
            if (choice == 1) {
                // Polymorphic call: Har user apna specific view dikhayega
                if (auto viewer = dynamic_cast<ISubjectViewer*>(user)) {
                    viewer->viewSubjects();
                }
            } else {
                active = false;
            }
        }
    }
};

// ==========================================
// MAIN EXECUTION
// ==========================================
int main() {
    // Boilerplate for DIP
    MySQLAuthRepository db;
    SessionManager session(db);
    
    cout << "--- STUDENT DATABASE MANAGEMENT SYSTEM ---\n";
    cout << "Enter User ID: ";
    int id = InputHandler::getLimitInput(1, 99999);
    cout << "Enter Password: ";
    string pass; cin >> pass;

    // Simulating user retrieval from DB
    if (id == 60032) {
        unique_ptr<User> currentUser = make_unique<Student>(60032, "Sobiya");
        session.startSession(currentUser.get());
    } else {
        cout << "Login Failed!\n";
    }

    return 0;
}
