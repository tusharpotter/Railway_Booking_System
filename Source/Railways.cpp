// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include "Station.h"
#include "Railways.h"
using namespace std;

// defining the static members
vector<Station > Railways::sStations;
unordered_map<string, unordered_map<string, double > > Railways::sDistStations;

Railways::Railways()
{
    // Hard code the master data into the static members
    // Store all the stations
        sStations.push_back(Station("Mumbai"));
        sStations.push_back(Station("Delhi"));
        sStations.push_back(Station("Bangalore"));
        sStations.push_back(Station("Kolkata"));
        sStations.push_back(Station("Chennai"));

    // Store the distances between any two stations
        unordered_map<string, double> tmp;

        tmp.insert(make_pair("Delhi", 1447));
        tmp.insert(make_pair("Bangalore", 981));
        tmp.insert(make_pair("Kolkata", 2014));
        tmp.insert(make_pair("Chennai", 1338));

        sDistStations["Mumbai"] = tmp;
        tmp.clear();

        tmp.insert(make_pair("Mumbai", 1447));
        tmp.insert(make_pair("Bangalore", 2150));
        tmp.insert(make_pair("Kolkata", 1472));
        tmp.insert(make_pair("Chennai", 2180));

        sDistStations["Delhi"] = tmp;
        tmp.clear();

        tmp.insert(make_pair("Mumbai", 981));
        tmp.insert(make_pair("Delhi", 2150));
        tmp.insert(make_pair("Kolkata", 1871));
        tmp.insert(make_pair("Chennai", 350));

        sDistStations["Bangalore"] = tmp;
        tmp.clear();

        tmp.insert(make_pair("Mumbai", 2014));
        tmp.insert(make_pair("Delhi", 1472));
        tmp.insert(make_pair("Bangalore", 1871));
        tmp.insert(make_pair("Chennai", 1659));

        sDistStations["Kolkata"] = tmp;
        tmp.clear();

        tmp.insert(make_pair("Mumbai", 1338));
        tmp.insert(make_pair("Delhi", 2180));
        tmp.insert(make_pair("Bangalore", 350));
        tmp.insert(make_pair("Kolkata", 1659));

        sDistStations["Chennai"] = tmp;
        tmp.clear();
}

Railways::~Railways() {}

const Railways& Railways::GetInstance()
{
    static Railways IndianRailways;     // create the singleton Instance IndianRailways
    return IndianRailways;
}

double Railways::GetDistance(const string fStation, const string tStation) const
{
    return Railways::sDistStations[fStation][tStation];   // return the distance
}