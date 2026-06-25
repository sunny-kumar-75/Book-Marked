#include "Date.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) {
    setDate(d, m, y);
}

bool Date::isLeapYear(int y) const {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

int Date::daysInMonth(int m, int y) const {
    if (m == 2) {
        return isLeapYear(y) ? 29 : 28;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    return 31;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

void Date::setDate(int d, int m, int y) {
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) {
        day = 1;
        month = 1;
        year = 2000;
    } else {
        day = d;
        month = m;
        year = y;
    }
}

string Date::toString() const {
    ostringstream oss;
    oss << setw(2) << setfill('0') << day << "/"
        << setw(2) << setfill('0') << month << "/"
        << year;
    return oss.str();
}

void Date::fromString(const string& dateStr) {
    if (dateStr.length() != 10) return;
    int d, m, y;
    char sep1, sep2;
    istringstream iss(dateStr);
    iss >> d >> sep1 >> m >> sep2 >> y;
    if (sep1 == '/' && sep2 == '/') {
        setDate(d, m, y);
    }
}

Date Date::getCurrentDate() {
    time_t t = time(0);
    struct tm * now = localtime(& t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

int Date::differenceInDays(const Date& other) const {
    auto daysFromEpoch = [](int d, int m, int y) {
        int days = d;
        for (int i = 1; i < m; ++i) {
            if (i == 2) days += (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28;
            else if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
            else days += 31;
        }
        days += y * 365 + y / 4 - y / 100 + y / 400;
        return days;
    };
    
    int thisDays = daysFromEpoch(day, month, year);
    int otherDays = daysFromEpoch(other.day, other.month, other.year);
    
    return thisDays - otherDays;
}
