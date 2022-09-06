// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include "Station.h"
#include "Railways.h"
using namespace std;

Station::Station(const string str) : name_(str) {}
Station::~Station() {}

Station::Station(const Station& s) : name_(s.name_) {}  // copy constructor to ensure deep copy

ostream& operator<<(ostream& os, const Station obj)
{
    os<<obj.GetName()<<endl;
    return os;
}

const string Station::GetName() const
{
    return this->name_;
}

const double Station::GetDistance(Station s) const
{
    return Railways::GetInstance().GetDistance(this->name_, s.name_);   //make a call to IndianRailways to obtain the distance
}
