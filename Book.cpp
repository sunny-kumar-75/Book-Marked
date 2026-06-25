#include "Book.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

Book::Book() {
    isbn = "";
    title = "";
    author = "";
    totalCopies = 0;
    availableCopies = 0;
}

Book::Book(string isbn, string title, string author, int total, int available) {
    this->isbn = isbn;
    this->title = title;
    this->author = author;
    this->totalCopies = total;
    this->availableCopies = available;
}

string Book::getIsbn() const { 
    return isbn; 
}

string Book::getTitle() const { 
    return title; 
}

string Book::getAuthor() const { 
    return author; 
}

int Book::getTotalCopies() const { 
    return totalCopies; 
}

int Book::getAvailableCopies() const { 
    return availableCopies; 
}

void Book::setTitle(const string& t) { 
    title = t; 
}

void Book::setAuthor(const string& a) { 
    author = a; 
}
void Book::setTotalCopies(int t) {
    int diff = t - totalCopies;
    totalCopies = t;
    availableCopies += diff;
    if (availableCopies < 0) availableCopies = 0;
}

bool Book::issueBook() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

void Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
    }
}

void Book::displayBook() const {
    string t = title.length() > 32 ? title.substr(0, 29) + "..." : title;
    string a = author.length() > 22 ? author.substr(0, 19) + "..." : author;
    cout << left << setw(17) << isbn 
         << setw(35) << t 
         << setw(25) << a 
         << availableCopies << "/" << totalCopies << endl;
}

string Book::toCSV() const {
    return isbn + "," + title + "," + author + "," + to_string(totalCopies) + "," + to_string(availableCopies);
}

void Book::fromCSV(const string& csvLine) {
    stringstream ss(csvLine);
    string token;
    
    getline(ss, isbn, ',');
    getline(ss, title, ',');
    getline(ss, author, ',');
    
    getline(ss, token, ',');
    if(!token.empty()) totalCopies = stoi(token);
    
    getline(ss, token, ',');
    if(!token.empty()) availableCopies = stoi(token);
}
