// 19CS30018 - Gaurav Madkaikar

#ifndef _RAILWAYS_H
#define _RAILWAYS_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include "Station.h"
using namespace std;


class Railways  // Meyer's Singleton
{
    private :
    static vector<Station > sStations;
    static unordered_map<string, unordered_map<string, double > > sDistStations;
    
    Railways();
    ~Railways();

    public :
    static const Railways& GetInstance();
    double GetDistance(const string fStation, const string tStation) const;
    static void UnitTestRailways(); // testing fn.
};

#endif // _RAILWAYS_H