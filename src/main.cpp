/* STUDENT 4: Refactored for ISP
   Violation: A giant 'Service' interface forcing everyone to implement 
              AddSubject, AddTutor, and ViewGrades.
   Refactor: Split into smaller interfaces.
*/

class ISubjectViewer {
public:
    virtual void viewSubjects() = 0;
};

class ISubjectManager {
public:
    virtual void addSubject(string name) = 0;
};

// Student only implements what they need
class StudentUser : public ISubjectViewer {
    void viewSubjects() override { /* ... */ }
};

// Teacher implements both
class TeacherUser : public ISubjectViewer, public ISubjectManager {
    void viewSubjects() override { /* ... */ }
    void addSubject(string name) override { /* ... */ }
};
