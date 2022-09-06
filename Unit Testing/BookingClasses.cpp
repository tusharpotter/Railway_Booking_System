// 19CS30018 - Gaurav Madkaikar

#include<iostream>
#include<string>
#include "Station.h"
#include "BookingClasses.h"
using namespace std;

BookingClasses::BookingClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers) : loadFactor_(lf), IsSitting_(IsSit), IsAC_(IsAC), Isluxury_(Islux), NoOfTiers_(nTiers)
{
    cout<<"BookingClasses ctor"<<endl;
}
BookingClasses::~BookingClasses(){
    cout<<"BookingClasses dtor"<<endl;
}

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

SeatClasses::SeatClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers) : BookingClasses(lf, IsSit, IsAC,  Islux, nTiers){
    cout<<"SeatClasses ctor"<<endl;
}
SeatClasses::~SeatClasses(){
    cout<<"SeatClasses dtor"<<endl;
}

BerthClasses::BerthClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers):BookingClasses(lf, IsSit, IsAC,  Islux, nTiers){
    cout<<"BerthClasses ctor"<<endl;
}
BerthClasses::~BerthClasses(){
    cout<<"BerthClasses dtor"<<endl;
}

// individual classes

ACFirstClass::ACFirstClass() : BerthClasses(3.00, false, true, true, 2){
        cout<<"AC First Class ctor"<<endl;
    }
    ACFirstClass::~ACFirstClass(){
        cout<<"AC First Class dtor"<<endl;
    }
    
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

FirstClass::FirstClass(): BerthClasses(2.00, false, false, true, 2){
    cout<<"First Class ctor"<<endl;
}
    FirstClass::~FirstClass(){
        cout<<"First Class dtor"<<endl;
    }
    
    const FirstClass& FirstClass::Type(){
        static const FirstClass obj;
        return obj;
    }
    const string FirstClass::GetName() const {
        return "First Class";
    }

AC3Tier::AC3Tier(): BerthClasses(1.75, false, true, false, 3){
    cout<<"AC 3 Tier ctor"<<endl;
}
    AC3Tier::~AC3Tier(){
        cout<<"AC 3 Tier dtor"<<endl;
    }

    const AC3Tier& AC3Tier::Type(){
        static const AC3Tier obj;
        return obj;
    }
    const string AC3Tier::GetName() const {
        return "AC 3 Tier";
    }

ACChairCar::ACChairCar() : SeatClasses(1.25, true, true, false, 0){
    cout<<"AC Chair Car ctor"<<endl;
}
    ACChairCar::~ACChairCar(){
        cout<<"AC Chair Car dtor"<<endl;
    }
    const ACChairCar& ACChairCar::Type(){
        static const ACChairCar obj;
        return obj;
    }
    const string ACChairCar::GetName() const {
        return "AC Chair Car";
    }

Sleeper::Sleeper(): BerthClasses(1.00, false, false, false, 3){
    cout<<"Sleeper ctor"<<endl;
}
    Sleeper::~Sleeper(){
        cout<<"Sleeper dtor"<<endl;
    }

    const Sleeper& Sleeper::Type(){
        static const Sleeper obj;
        return obj;
    }
    const string Sleeper::GetName() const {
        return "Sleeper";
    }

SecondSitting::SecondSitting(): SeatClasses(0.50, true, false, false, 0){
    cout<<"Second Sitting ctor"<<endl;
}
    SecondSitting::~SecondSitting(){
        cout<<"Second Sitting dtor"<<endl;
    }

    const SecondSitting& SecondSitting::Type(){
        static const SecondSitting obj;
        return obj;
    }
    const string SecondSitting::GetName() const {
        return "Second Sitting";
    }

// Testing function
void BookingClasses::UnitTestBookingClasses()
{
    // We will test two classes each derived from SeatClasses and BerthClasses

    // reference of type BookingClasses pointing to a const derived class object (base class: SeatClasses)
    cout<<"Object 1 instantiated !"<<endl;
    const BookingClasses &obj1 = AC2Tier::Type();
    // reference of type BookingClasses pointing to a const derived class object (base class: BerthClasses)
    cout<<endl<<"Object 2 instantiated !"<<endl;
    const BookingClasses &obj2 = ACChairCar::Type();

    // Test the methods/attributes using the reference obj1
    if (obj1.GetName() != "AC 2 Tier")
    {
        cout<<"Incorrect class type returned !"<<endl;
    }
    if (obj1.GetLoadFactor() != 2.00)
    {
        cout<<"Incorrect class type returned !"<<endl;
    }
    if (obj1.Isluxury() != false)
    {
        cout<<"Incorrect data returned !"<<endl;
    }
    if (obj1.IsSitting() != false)
    {
        cout<<"Incorrect data returned !"<<endl;
    }

    // Test the methods/attributes using the reference obj2
    if (obj2.GetName() != "AC Chair Car")
    {
        cout<<"Incorrect class type returned !"<<endl;
    }
    if (obj2.GetLoadFactor() != 1.25)
    {
        cout<<"Incorrect class type returned !"<<endl;
    }
    if (obj2.IsSitting() != true)
    {
        cout<<"Incorrect data returned !"<<endl;
    }
    // Call the destructors in the reverse order
}