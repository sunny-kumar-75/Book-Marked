#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string id;
    std::string name;
    std::string password;
    std::string role; // "MEMBER" or "LIBRARIAN"

public:
    User();
    User(std::string id, std::string name, std::string password, std::string role);

    std::string getId() const;
    std::string getName() const;
    std::string getRole() const;
    
    bool checkPassword(const std::string& pwd) const;
    
    std::string toCSV() const;
};

#endif 
