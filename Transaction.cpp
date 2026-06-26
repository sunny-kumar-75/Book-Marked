#include "Transaction.h"
#include <bits/stdc++.h>

using namespace std;

Transaction::Transaction() {
    transactionId = "";
    bookIsbn = "";
    memberId = "";
    isReturned = false;
}

Transaction::Transaction(string tId, string isbn, string mId, Date issue, Date due) {
    transactionId = tId;
    bookIsbn = isbn;
    memberId = mId;
    issueDate = issue;
    dueDate = due;
    isReturned = false;
}

string Transaction::getTransactionId() const { 
    return transactionId; 
}

string Transaction::getBookIsbn() const { 
    return bookIsbn; 
}

string Transaction::getMemberId() const { 
    return memberId; 
}

Date Transaction::getIssueDate() const { 
    return issueDate; 
}

Date Transaction::getDueDate() const { 
    return dueDate; 
}

Date Transaction::getReturnDate() const { 
    return returnDate; 
}

bool Transaction::getIsReturned() const { 
    return isReturned; 
}

void Transaction::markAsReturned(Date returnD) {
    isReturned = true;
    returnDate = returnD;
}

string Transaction::toCSV() const {
    string csv = transactionId + "," + bookIsbn + "," + memberId + "," + 
                      issueDate.toString() + "," + dueDate.toString() + "," + 
                      (isReturned ? "1" : "0") + ",";
    if (isReturned) {
        csv += returnDate.toString();
    } else {
        csv += "N/A";
    }
    return csv;
}

void Transaction::fromCSV(const string& csvLine) {
    stringstream ss(csvLine);
    string token;

    getline(ss, transactionId, ',');
    getline(ss, bookIsbn, ',');
    getline(ss, memberId, ',');
    
    getline(ss, token, ',');
    issueDate.fromString(token);
    
    getline(ss, token, ',');
    dueDate.fromString(token);
    
    getline(ss, token, ',');
    isReturned = (token == "1");
    
    getline(ss, token, ',');
    if (isReturned && token != "N/A") {
        returnDate.fromString(token);
    }
}
