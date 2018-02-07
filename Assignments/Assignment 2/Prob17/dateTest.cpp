// FILE: dateTest.cpp
// AUTHOR: Cori Beemish
// DATE: 06/15/2017
// This program tests the date class.

#include "date.h"
#include <iostream>
#include <cassert>

int main()
{
    date today;

    assert (today.get_month() == 12);
    assert (today.get_day() == 25);
    assert (today.get_year() == 2017);

    today.showDate();
    std::cout << " " << endl;
    today.showWithName();

    date tomorrow;
    tomorrow.increment();

    assert (tomorrow.get_month() == 1);
    assert (tomorrow.get_day() == 1);
    assert (tomorrow.get_year() == 2018);

    std::cout << " " << endl << endl;
    tomorrow.showDate();
    std::cout << " " << endl;
    tomorrow.showWithName();
    std::cout << " " << endl;

    return 0;
}
