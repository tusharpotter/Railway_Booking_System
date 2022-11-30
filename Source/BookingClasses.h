

#ifndef _BOOKINGCLASSES_H
#define _BOOKINGCLASSES_H

#include<iostream>
#include<string>
#include "Station.h"
using namespace std;

// Multilevel - Inheritance Hierarchy
class BookingClasses    // abstract base class
{
    protected :
    const double loadFactor_;
    const bool IsSitting_;
    const bool IsAC_;
    const bool Isluxury_ ;
    const int NoOfTiers_ ;

    BookingClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers);
    
    public :
    virtual ~BookingClasses();  // virtual destructor to prevent slicing
    virtual const string GetName() const = 0;   // ensures polymorphic hierarchy
    // non-virtual as const data involved
    const double GetLoadFactor() const;
    const bool IsSitting() const;
    const bool IsAC() const ;
    const bool Isluxury() const;
    const int GetNumberOfTiers() const;
};

class SeatClasses : public BookingClasses   // abstract class
{
    protected:
    SeatClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers);
    
    public:
    virtual ~SeatClasses();
    virtual const string GetName() const = 0;
};

class BerthClasses : public BookingClasses  // abstract class
{
    protected:
    BerthClasses(double lf, bool IsSit, bool IsAC, bool Islux, int nTiers);
    
    public:
    virtual ~BerthClasses();
    virtual const string GetName() const = 0;

};
// Implementation of Singletons with private constructors
class ACFirstClass : public BerthClasses
{
    ACFirstClass();
    
    public :
    ~ACFirstClass();
    static const ACFirstClass& Type();
    const string GetName() const;
};

class AC2Tier : public BerthClasses
{
    AC2Tier();
    
    public:
    ~AC2Tier();
    static const AC2Tier& Type();
    const string GetName() const;
};

class FirstClass : public BerthClasses
{
    FirstClass();
    
    public :
    ~FirstClass();
    static const FirstClass& Type();
    const string GetName() const;
};

class AC3Tier : public BerthClasses
{
    AC3Tier();
    
    public :
    ~AC3Tier();
    static const AC3Tier& Type();
    const string GetName() const;
};

class ACChairCar : public SeatClasses
{
    ACChairCar();
    
    public :
    ~ACChairCar();
    static const ACChairCar& Type();
    const string GetName() const;
};

class Sleeper : public BerthClasses
{
    Sleeper();
    
    public :
    ~Sleeper();
    static const Sleeper& Type();
    const string GetName() const;
};

class SecondSitting : public SeatClasses
{
    SecondSitting();
    
    public :
    ~SecondSitting();
    static const SecondSitting& Type();
    const string GetName() const;
};

#endif // _BOOKINGCLASSES_H
