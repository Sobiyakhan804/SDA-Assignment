/* STUDENT 3: Refactored for LSP
   Violation: If Teacher and Student inherit from People, 
              but Student is forced to have 'giveGrades()' which they can't do.
   Refactor: Ensure base class only has common behaviors.
*/

class People {
public:
    virtual string getRole() = 0;
    string getName() { return name; }
private:
    string name;
};

// Subclasses can replace People without breaking the system
class Student : public People {
    string getRole() override { return "Student"; }
};

class Teacher : public People {
    string getRole() override { return "Teacher"; }
};
