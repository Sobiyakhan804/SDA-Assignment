/* STUDENT 1: Refactored for SRP
   Violation: Original init() was doing UI, Input, and Login logic.
   Refactor: Created separate classes for UI and Authentication.
*/

class ConsoleUI {
public:
    void displayMainMenu() {
        cout << "|====== STUDENT DATABASE MANAGEMENT SYSTEM ======| \n";
        cout << "|  1. Login | 2. Show Info | 3. Exit | \n";
    }
    
    void displayTeacherMenu() {
        // Only responsible for printing the menu
        cout << "1. Show Students\n2. Add Student... (etc)\n";
    }
};

class AuthenticationService {
public:
    // Only responsible for the logic of logging in
    int login(int id, string password) {
        if (PeopleServices::login(id, password)) {
            return id;
        }
        return -1;
    }
};
