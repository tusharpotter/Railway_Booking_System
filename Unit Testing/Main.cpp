// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
using namespace std;

// Unit Testing done provided input arguments are correct
// Implemented according to Testplan.txt

int main()
{
    // Unit Testing of various classes
    // class Railways
    cout<<"Testing class Railways ......"<<endl;
    Railways::UnitTestRailways();
    cout<<endl;

    // class Station
    cout<<"Testing class Station ......"<<endl;
    Station::UnitTestStation();
    cout<<endl;

    // class Date
    cout<<"Testing class Date ......"<<endl;
    Date::UnitTestDate();
    cout<<endl;

    // class BookingClasses, SeatClasses, BerthClasses are abstract classes, thus they will be tested by their derived classes
    cout<<"Testing class BookingClasses, its derived classes SeatClasses, BerthClasses, and their derived classes......"<<endl;
    BookingClasses::UnitTestBookingClasses();
    cout<<endl;

    // class Booking
    cout<<"Testing class Booking ......"<<endl;
    Booking::UnitTestBooking();
    cout<<endl;

    return 0;
}