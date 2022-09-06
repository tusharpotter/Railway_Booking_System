// 19CS30018 - Gaurav Madkaikar

#ifndef _BOOKING_H
#define _BOOKING_H

#include<iostream>
#include<vector>
#include<cmath>
#include "Station.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "Date.h"

using namespace std;

class Booking
{
    const Station fromStation;
    const Station toStation;
    int finFare;    // store the final fare
    const bool bookingStatus;
    const string bookingMessage;
    const BookingClasses& obj_; // store a reference of type BookingClasses
    const Date dateOfTravel_;

    public:
    static vector<Booking*> sBookings;
    static const double sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;
    static int sBookingPNRSerial;

    Booking(Station s1, Station s2, Date d, const BookingClasses &obj_new);
    ~Booking();
    int ComputeFare();      // return the final fare
    static const double GetDistance(const Station fStation, const Station tStation);
    friend ostream& operator<<(ostream& os, const Booking b) ;
};

#endif // _BOOKING_H