// 19CS30018 - Gaurav Madkaikar

Brief Description of files contained in the folder "Source.zip" .

Files stated in the order of linking after compilation:

Station.cpp | Station.h : Includes the implementation of class Station with a single private attribute name_ 

Railways.cpp | Railways.h : Includes the implementation of class Railways with static members sStations and sDistStations which contains the table data
                            Implemented as Meyer's Singleton (only one instance allowed)     

Date.cpp | Date.h :  Includes the implementation of class Date with a private attributes day_, month_, year_
                     Months can be accessed in two dofferent formats as implemented by enums
                     Prints date in a specified format

BookingClasses.cpp | BookingClasses.h :  Includes the implementation of a multi-level inheritance hierarchy with polymorphic methods.
                                         - 3 abstract classes and 7 concrete classes (all 7 of which are singletons)      
                                         All attributes are defined in the base class                  

Booking.cpp | Booking.h :  Includes the implementation of the Booking class with static variable sBookings to store all the 
                           successful bookings
                           Also includes other static variables and attributes which help in computing the overall fare of the trip following
                           a well defined business logic
                           This file manages all the test output to be printed on the screen, thus being implementation heavy

Passenger.cpp | Passenger.h : Currently is an an empty class whose features will be further extended later.
                              It is initialised as a nullable parameter initialised by a function
                              
Main.cpp : Prototypes of test applications are provided here which will be used to test the entire application

Application.cpp : Includes the function definition of the sample test application provided in the problem statement

TestUserApplication.cpp : Includes the function definition of a newly created user-defined test application covering all possible scenarios

** run_cmds.txt : Includes the commands to compile and link all the files in Source.zip


