// 19CS30018 - Gaurav Madkaikar

#ifndef _DATE_H
#define _DATE_H

#include<iostream>
#include<string>
using namespace std;

// enumerate Months and Days
enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };

class Date
{
    unsigned int day_, year_;
    Month month_;

    public: 
    static const string sNameMonth[12];
    static const string sNameDays[7];
    Date(unsigned int d, unsigned int m, unsigned int y);
    Date(unsigned int d, Month m, unsigned int y);
    ~Date();
    static void UnitTestDate(); // testing function

    friend ostream& operator<<(ostream& os, const Date D);
};

#endif // _DATE_H