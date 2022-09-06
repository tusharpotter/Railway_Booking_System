// 19CS30018 - Gaurav Madkaikar

#ifndef _PASSENGER_H
#define _PASSENGER_H

#include<iostream>
#include<vector>
#include<cmath>
#include "Station.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Booking.h"
using namespace std;

class Passenger  // abstract base class (empty for now)
{
    public:
    static const Passenger nullPassenger;
};
const Passenger Passenger::nullPassenger;

#endif // _PASSENGER_H