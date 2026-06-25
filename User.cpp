#include "User.h"

using namespace std;

User::User() {
    id = "";
    name = "";
    password = "";
    role = "";
}

User::User(string id, string name, string password, string role) {
    this->id = id;
    this->name = name;
    this->password = password;
    this->role = role;
}

string User::getId() const { 
    return id; 
}

string User::getName() const { 
    return name; 
}

string User::getRole() const { 
    return role; 
}

bool User::checkPassword(const string& pwd) const {
    return password == pwd;
}

string User::toCSV() const {
    return id + "," + name + "," + password + "," + role;
}
