// FILE: date.h
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
// CLASS PROVIDED: date
//
// CONSTRUCTORS
//    date();
//        POSTCONDTION: Date is set to 01/30/2017
//    date(int mo, int dy, int yr);
//        PRECONDITION: mo, dy, & yr are positive values.
//        POSTCONDTION: mo is month. dy is day. yr is year.
//
// MODIFICATION MEMBER FUNCTIONS
//    bool date::isLeapYear(int year);
//        PRECONDITION: year > 0
//        POSTCONDTION: Year is determined to be a leap year or not.
//
//    void increment ();
//        PRECONDITION: month, day, and year are all positive values.
//        POSTCONDTION: The value returned will be the date increased by the number of days.
//
//    void showDate();
//        PRECONDITION:
//        POSTCONDTION: This will display the date.
//
//    void showWithName();
//        PRECONDITION:
//        POSTCONDTION: This will display the date in words. Such as; 01/31/2017 will be
//                      January 31, 2017.
//
// CONSTANT MEMBER FUNCTIONS
//    int get_day() const;
//        PRECONDITION:
//        POSTCONDTION: This will return the day.
//
//    int get_month() const;
//        PRECONDITION:
//        POSTCONDTION: This will return the month.
//
//    int get_year() const;
//        PRECONDITION:
//        POSTCONDTION: This will return the year.


#ifndef _DATE_H_INCLUDED
#define _DATE_H_INCLUDED

#include <cassert>
#include <iostream>

using namespace std;

class date
{
public:
    // CONSTRUCTORS
    date();
    date(int mo, int dy, int yr);

    // MODIFICATION MEMBER FUNCTIONS
    bool isLeapYear(int year);
    void increment ();
    void showDate();
    void showWithName();

    // CONSTANT MEMBER FUNCTIONS
    int get_day() const;
    int get_month() const;
    int get_year() const;

private:
    int month;
    int day;
    int year;
};

#endif // BEEMISH_DATE_H_INCLUDED
