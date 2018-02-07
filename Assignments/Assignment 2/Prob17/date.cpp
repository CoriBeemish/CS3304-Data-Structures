// FILE: date.cpp
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
// CLASS IMPLEMENTED: date (See date.h for documentation.)

#include "date.h"

date::date()
{
    month = 12;
    day = 31;
    year = 2017;
}

date::date(int mo, int dy, int yr)
{
    assert(mo > 0 && dy > 0 && yr > 0);
    month = mo;
    day = dy;
    year = yr;
}

bool date::isLeapYear(int year)
{
    assert(year > 0);
    if( ((year%4) == 0) && (((year%100)!=0) || ((year%400) == 0)) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void date::increment ()
{
    assert ( month > 0 && day > 0 && year > 0);
    if (day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    {
        if (month == 12) //If last day is in December, tomorrow will be January 1st, year + 1
        {
            day = 1;
            month = 1;
            year = year + 1;
        }
        else //NOT DECEMBER
        {
            day = 1;
            month = month + 1;
        }
    }
    else if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        day = 1;
        month = month + 1;
    }
    else if(month == 2)
    {
        if (isLeapYear(year))
        {
            if (day == 29)
            {
                day = 1;
                month = month + 1;
            }
            else
            {
                day = day + 1;
            }
        }
        else //NOT LEAP YEAR
        {
            if (day == 28)
            {
                day = 1;
                month = month + 1;
            }
            else
            {
                day = day + 1;
            }
        }
    }
    else
    {
        day = day + 1;
    }
}


void date::showDate()
{
    std::cout << month << "/" << day << "/" << year;
}

void date::showWithName()
{
    switch (month)
    {
        case 1  : cout << "January ";
            break;
        case 2  : cout << "February ";
            break;
        case 3  : cout << "March ";
            break;
        case 4  : cout << "April ";
            break;
        case 5  : cout << "May ";
            break;
        case 6  : cout << "June ";
            break;
        case 7  : cout << "July ";
            break;
        case 8  : cout << "August ";
            break;
        case 9  : cout << "September ";
            break;
        case 10 : cout << "October ";
            break;
        case 11 : cout << "November ";
            break;
        case 12 : cout << "December ";
            break;
    }
    cout << day << ", " << year;
}

int date::get_month() const
{
    return month;
}

int date::get_day() const
{
    return day;
}

int date::get_year() const
{
    return year;
}

