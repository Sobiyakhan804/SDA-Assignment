/* STUDENT 5: Refactored for DIP
   Violation: Services were directly creating 'PeopleDao' objects (Hard Dependency).
   Refactor: Dependency Injection using Interfaces.
*/
class IAuthRepository {
public:
    virtual bool validate(int id, string pass) = 0;
};
class MySQLAuthRepository : public IAuthRepository {
public:
    bool validate(int id, string pass) override {
        return (id == 60032 && pass == "admin123");
    }
};
class SessionManager {
    IAuthRepository& authRepo;
};
