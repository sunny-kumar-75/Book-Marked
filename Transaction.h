#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"

class Transaction {
private:
    std::string transactionId;
    std::string bookIsbn;
    std::string memberId;
    Date issueDate;
    Date dueDate;
    Date returnDate;
    bool isReturned;

public:
    Transaction();
    Transaction(std::string tId, std::string isbn, std::string mId, Date issue, Date due);

    // Getters
    std::string getTransactionId() const;
    std::string getBookIsbn() const;
    std::string getMemberId() const;
    Date getIssueDate() const;
    Date getDueDate() const;
    Date getReturnDate() const;
    bool getIsReturned() const;

    
    void markAsReturned(Date returnD);

    
    std::string toCSV() const;
    void fromCSV(const std::string& csvLine);
};

#endif 
