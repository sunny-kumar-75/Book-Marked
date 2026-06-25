#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDate(int d, int m, int y);

    // Utility
    std::string toString() const;
    void fromString(const std::string& dateStr); // Format DD/MM/YYYY

    // Static utility to get current date
    static Date getCurrentDate();
    
    // Difference in days between two dates (this - other)
    int differenceInDays(const Date& other) const;
};

#endif // DATE_H
