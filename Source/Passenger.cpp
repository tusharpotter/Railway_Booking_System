// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<vector>
#include<cmath>
#include "Station.h"
#include "Railways.h"
#include "BookingClasses.h"
#include "Date.h"
#include "Booking.h"
#include "Passenger.h"
using namespace std;

const Passenger Passenger::nullPassenger;   // reference to be initilaised to NULL

void initialise(const Passenger& = Passenger::nullPassenger)
{
    return;
}