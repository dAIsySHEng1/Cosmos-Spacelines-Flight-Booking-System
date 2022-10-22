//Class: Passenger

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger{
  private:
    string firstName;
    string lastName;
    string address;
    string phoneNumber;
    string passengerID;

  public:
    static int numPassengerObjects;
    Passenger();
    Passenger(string first, string last, string address, string phoneNumber);

    string getFirstName();
    string getLastName();
    string getAddress();
    string getPhoneNumber();
    string getID();

    //string getFirstName(string id);
    //string getLastName(string id);

//check that passenger id is not -
    void setFirstName(string name);
    void setLastName(string name);
    void setAddress(string address);
    void setPhoneNumber(string num);
    void setID();

    void setFirstName(string id, string name);
    void setLastName(string id, string name);

    bool checkLetters(string name);
    bool checkPhoneNumber(string num);

    string passengerInfo();
    //string passengerInfo(string id);

    void emptyPassenger();
};

#endif
