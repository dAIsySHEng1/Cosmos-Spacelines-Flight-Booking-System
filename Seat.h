#include "Passenger.h"

#ifndef SEAT_H
#define SEAT_H

class Seat{
  private:
    string passengerID;
    string seatNumber;
  public:
    Seat(string seatNum);
    Seat(string seatNum, string passengerID);

    void setSeatNumber(string seatNumber);
    void setPassengerID(string id); //returning passenger

    void setPassenger(string first, string last, string address, string phone); //new passenger

    string getPassengerID();
    string getSeatNumber();

    bool validSeatNum(string seatNum);
    bool validID(string id);
    bool checkNumbers(string id);

    bool isReserved();
    void clearSeat();

    void printSeatInfo();

    string getFirstName();
    string getLastName();
    string getAddress();
    string getPhoneNum();
    string getFullName();
};

#endif
