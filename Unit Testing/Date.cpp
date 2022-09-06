// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<string>
#include "Date.h"
using namespace std;

const string Date::sNameMonth[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string Date::sNameDays[7] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

// overloaded constructors
Date::Date(unsigned int d, unsigned int m, unsigned int y) : day_(d), month_(Month(m)), year_(y) {}
Date::Date(unsigned int d, Month m, unsigned int y) : day_(d), month_(m), year_(y) {}
Date::~Date(){}

ostream& operator<<(ostream& os, const Date D)
{
    os << D.day_ << "/" << Date::sNameMonth[D.month_ - 1] << "/" << D.year_;
    return os;
}
// Testing function
void Date::UnitTestDate()
{
    // create instances of the Date class
    Date d1(12, 10, 2019), d2(13, Apr, 2018);
    
    // print the corresponding date
    cout<<d1<<endl<<d2<<endl;
}
