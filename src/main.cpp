/* STUDENT 5: Refactored for DIP
   Violation: Services were directly creating 'PeopleDao' objects (Hard Dependency).
   Refactor: Dependency Injection using Interfaces.
*/

// Abstraction
class IPeopleRepository {
public:
    virtual People* findById(int id) = 0;
};

// Low-level Detail
class PeopleDao : public IPeopleRepository {
public:
    People* findById(int id) override { /* Database logic */ return nullptr; }
};

// High-level Service depends on Interface, not Dao
class TeacherServices {
    IPeopleRepository* repo;
public:
    TeacherServices(IPeopleRepository* r) : repo(r) {} // Injected via constructor
    
    void showStudents() {
        repo->findById(1); // Works with any repository implementation
    }
};
