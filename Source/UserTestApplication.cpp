
// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<vector>
#include<cmath>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"
using namespace std;

// User Test application for booking
void UserTestApplication() 
{
    // <BookingClasses>::Type() returns the constant object of the respective type

    // Bookings with reversed Stations and different formats of Date
    Booking bt1(Station("Kolkata"), Station("Chennai"), Date(31, 12, 2021), Sleeper::Type());
    Booking bt2(Station("Chennai"), Station("Kolkata"), Date(15, May, 2021), Sleeper::Type());

    // Bookings of each BookingClass type
    Booking b1(Station("Delhi"), Station("Kolkata"), Date(5, 3, 2021), ACFirstClass::Type());
    Booking b2(Station("Bangalore"), Station("Mumbai"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Chennai"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Bangalore"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Mumbai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Kolkata"), Station("Bangalore"), Date(19, 5, 2021), SecondSitting::Type());
    
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator itr;

    for (itr = Booking::sBookings.begin(); itr < Booking::sBookings.end(); ++itr) 
    {
        cout << *(*itr);    // Print the details of each booking by calling operator<<
    }
    
    return;
}

