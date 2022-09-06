// 19CS30018 - Gaurav Madkaikar

#ifndef _STATION_H
#define _STATION_H

#include<iostream>
#include<string>
using namespace std;

//class Railways;
class Station
{
    const string name_;

    public:
    Station(const string str);
    Station(const Station& s);
    
    const string GetName() const;
    friend ostream& operator<<(ostream& os, const Station obj);

    const double GetDistance(Station s) const;
    static void UnitTestStation();
  
    ~Station();
};

#endif // _STATION_H