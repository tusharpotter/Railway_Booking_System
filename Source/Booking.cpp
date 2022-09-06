// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<vector>
#include<cmath>
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
using namespace std;

// defining the static constants
vector<Booking*> Booking::sBookings;
int Booking::sBookingPNRSerial = 0;
const double Booking::sBaseFarePerKM = 0.5;
const double Booking::sACSurcharge = 50;
const double Booking::sLuxuryTaxPercent = 0.25;

Booking::Booking(Station s1, Station s2, Date d, const BookingClasses &obj_new) : bookingMessage("BOOKING SUCCEEDED"), bookingStatus(true), finFare(0), dateOfTravel_(d), fromStation(s1), toStation(s2), obj_(obj_new){
    Booking::sBookings.push_back(this);     // store the booking
    ComputeFare();  // compute the final fare involved in the trip
}

Booking::~Booking(){}

int Booking::ComputeFare()
{
    const Railways& IndianRailways = Railways::GetInstance();   // create IndianRailways instance
    double lfactor = this->obj_.GetLoadFactor();
    double distance = IndianRailways.GetDistance(fromStation.GetName(), toStation.GetName());
        
    // Implement the Fare Calculation logic
        double baseFare = distance * Booking::sBaseFarePerKM;
        double loadedFare = baseFare * lfactor;

        if (this->obj_.IsAC())        // AC surcharge
            loadedFare += Booking::sACSurcharge;

        if (this->obj_.Isluxury())    // Luxury Tax
            loadedFare *= (1 + Booking::sLuxuryTaxPercent);
        
        finFare = static_cast<int> (round(loadedFare)); // stroe the final fare
        return finFare;
}

const double Booking::GetDistance(const Station fStation, const Station tStation)
{
    return fStation.GetDistance(tStation);
}

ostream& operator<<(ostream& os, const Booking b) 
{
    // Print the final output
    os << b.bookingMessage << ":" << endl;
    os << "PNR Number = " << ++(Booking::sBookingPNRSerial) << endl;
    os << "From Station = " << b.fromStation.GetName() << endl;
    os << "To Station = "<< b.toStation.GetName() << endl;
    os << "Travel Date = " << b.dateOfTravel_ << endl;
    os << "Travel Class = " << b.obj_.GetName()<< endl;
    os << " : Mode: ";
    (b.obj_.IsSitting()) ? os << "Sitting" << endl : os << "Sleeping" << endl;
    os << " : Comfort: ";
    (b.obj_.IsAC()) ? os << "AC" << endl : os << "Non-AC" << endl;
    os << " : Bunks: " << b.obj_.GetNumberOfTiers() << endl;
    os << " : Luxury: ";
    (b.obj_.Isluxury()) ? os << "Yes" << endl : os << "No" << endl;
    os << "Fare = " << b.finFare << endl << endl;

    return os;
}
    