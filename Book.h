#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    int totalCopies;
    int availableCopies;

public:
    Book();
    Book(std::string isbn, std::string title, std::string author, int total, int available);

    std::string getIsbn() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;

    void setTitle(const std::string& t);
    void setAuthor(const std::string& a);
    void setTotalCopies(int t);

    bool issueBook();
    void returnBook();

    void displayBook() const;
    
    std::string toCSV() const;
    void fromCSV(const std::string& csvLine);
};

#endif 
