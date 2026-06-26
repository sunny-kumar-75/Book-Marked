#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

FileManager::FileManager(string bFile, string uFile, string tFile)
    : booksFile(bFile), usersFile(uFile), transactionsFile(tFile) {}

void FileManager::loadBooks(vector<Book>& books) {
    ifstream file(booksFile);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        Book b;
        b.fromCSV(line);
        books.push_back(b);
    }
    file.close();
}

void FileManager::saveBooks(const vector<Book>& books) {
    ofstream file(booksFile);
    if (!file.is_open()) {
        cerr << "Error opening books file for writing." << endl;
        return;
    }

    for (const auto& b : books) {
        file << b.toCSV() << "\n";
    }
    file.close();
}

void FileManager::loadUsers(vector<User>& users) {
    ifstream file(usersFile);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, pwd, role;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, pwd, ',');
        getline(ss, role, ',');

        users.push_back(User(id, name, pwd, role));
    }
    file.close();
}

void FileManager::saveUsers(const vector<User>& users) {
    ofstream file(usersFile);
    if (!file.is_open()) {
        cerr << "Error opening users file for writing." << endl;
        return;
    }

    for (const auto& u : users) {
        file << u.toCSV() << "\n";
    }
    file.close();
}

void FileManager::loadTransactions(vector<Transaction>& transactions) {
    ifstream file(transactionsFile);
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        Transaction t;
        t.fromCSV(line);
        transactions.push_back(t);
    }
    file.close();
}

void FileManager::saveTransactions(const vector<Transaction>& transactions) {
    ofstream file(transactionsFile);
    if (!file.is_open()) {
        cerr << "Error opening transactions file for writing." << endl;
        return;
    }

    for (const auto& t : transactions) {
        file << t.toCSV() << "\n";
    }
    file.close();
}
