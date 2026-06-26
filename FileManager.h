#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class FileManager {
private:
    std::string booksFile;
    std::string usersFile;
    std::string transactionsFile;

public:
    FileManager(std::string bFile, std::string uFile, std::string tFile);

    void loadBooks(std::vector<Book>& books);
    void saveBooks(const std::vector<Book>& books);

    void loadUsers(std::vector<User>& users);
    void saveUsers(const std::vector<User>& users);

    void loadTransactions(std::vector<Transaction>& transactions);
    void saveTransactions(const std::vector<Transaction>& transactions);
};

#endif // FILEMANAGER_H
