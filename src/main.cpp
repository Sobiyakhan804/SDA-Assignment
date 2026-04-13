/* STUDENT 2: Refactored for OCP
   Violation: main() had long if-else for Teacher, Tutor, Student levels.
   Refactor: Used Strategy Pattern / Polymorphism.
*/

class UserMenuStrategy {
public:
    virtual void showMenu(int id) = 0; // Interface for extension
    virtual ~UserMenuStrategy() {}
};

class StudentMenu : public UserMenuStrategy {
public:
    void showMenu(int id) override { /* Student specific logic */ }
};

class TeacherMenu : public UserMenuStrategy {
public:
    void showMenu(int id) override { /* Teacher specific logic */ }
};

// Now if a new "Admin" type comes, we just add a new class, 
// no need to change main() if-else blocks.
