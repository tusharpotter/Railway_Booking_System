// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include "Station.h"
#include "Railways.h"
using namespace std;

Station::Station(const string str) : name_(str) {}
Station::~Station() {}

Station::Station(const Station& s) : name_(s.name_) {}  // copy constructor

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
    return Railways::GetInstance().GetDistance(this->name_, s.name_);
}
// Testing function
void Station::UnitTestStation()
{
    // create two objects
    Station s1("Kolkata"), s2("Delhi");

    // check the methods with their corresponding golden outputs
    if (s1.GetName() != "Kolkata")
    {
        cout<<"Incorrect Construction of object"<<endl;
    }

    if (s1.GetDistance(s2) != 1472) 
    {
        cout<<"Incorrect data fed in the system"<<endl;
    }

    // print the Stations
    cout<<s1<<endl<<s2;
}