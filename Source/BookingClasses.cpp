// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<string>
#include "Station.h"
#include "BookingClasses.h"
using namespace std;

// base class implementation
// initialisation of member variables passed on from the derived classes
BookingClasses::BookingClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers) : loadFactor_(lf), IsSitting_(IsSit), IsAC_(IsAC), Isluxury_(Islux), NoOfTiers_(nTiers){}

BookingClasses::~BookingClasses(){}

const double BookingClasses::GetLoadFactor() const {
    return loadFactor_;
}
    
const bool BookingClasses::IsSitting() const{
    return IsSitting_;
}
const bool BookingClasses::IsAC() const {
    return IsAC_;
}
const bool BookingClasses::Isluxury() const {
    return Isluxury_;
}
const int BookingClasses::GetNumberOfTiers() const{
    return NoOfTiers_;
}
 // constructor call to higher level
SeatClasses::SeatClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers) : BookingClasses(lf, IsSit, IsAC,  Islux, nTiers){}
SeatClasses::~SeatClasses(){}

 // constructor call to higher level
BerthClasses::BerthClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers):BookingClasses(lf, IsSit, IsAC,  Islux, nTiers){}
BerthClasses::~BerthClasses(){}

// implementation of individual classes

ACFirstClass::ACFirstClass() : BerthClasses(3.00, false, true, true, 2){}   // constructor call to higher level
ACFirstClass::~ACFirstClass(){}
    
const ACFirstClass& ACFirstClass::Type(){
    static const ACFirstClass obj;
    return obj;
}

const string ACFirstClass::GetName() const {
    return "AC First Class";
}

AC2Tier::AC2Tier(): BerthClasses(2.00, false, true, false, 2){}
AC2Tier::~AC2Tier(){}

const AC2Tier& AC2Tier::Type(){
    static const AC2Tier obj;
    return obj;
}
const string AC2Tier::GetName() const{
    return "AC 2 Tier";
}

FirstClass::FirstClass(): BerthClasses(2.00, false, false, true, 2){}
FirstClass::~FirstClass(){}
    
const FirstClass& FirstClass::Type(){
    static const FirstClass obj;
    return obj;
}
const string FirstClass::GetName() const {
    return "First Class";
}

AC3Tier::AC3Tier(): BerthClasses(1.75, false, true, false, 3){}
AC3Tier::~AC3Tier(){}

const AC3Tier& AC3Tier::Type(){
    static const AC3Tier obj;
    return obj;
}

const string AC3Tier::GetName() const {
    return "AC 3 Tier";
}

ACChairCar::ACChairCar() : SeatClasses(1.25, true, true, false, 0){}
ACChairCar::~ACChairCar(){}

const ACChairCar& ACChairCar::Type(){
    static const ACChairCar obj;
    return obj;
}
const string ACChairCar::GetName() const {
    return "AC Chair Car";
}

Sleeper::Sleeper(): BerthClasses(1.00, false, false, false, 3){}
Sleeper::~Sleeper(){}

const Sleeper& Sleeper::Type(){
    static const Sleeper obj;
    return obj;
}

const string Sleeper::GetName() const {
    return "Sleeper";
}

SecondSitting::SecondSitting(): SeatClasses(0.50, true, false, false, 0){}
SecondSitting::~SecondSitting(){}

const SecondSitting& SecondSitting::Type(){
    static const SecondSitting obj;
    return obj;
}

const string SecondSitting::GetName() const {
    return "Second Sitting";
}