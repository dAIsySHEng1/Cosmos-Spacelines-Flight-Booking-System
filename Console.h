#include "Flight.h"

#ifndef CONSOLE_H
#define CONSOLE_H

class Console{
private:
  //flight objects
  void addFlight(string flightNumber);
  void cancelFlight(string flightNumber);

  //reservations
  void bookReservation(string flightNumber);
  //void booking();

  void cancelReservation(string flightNumber, string passengerID);
  void cancelReservation(string flightNumber, string first, string last, string address, string phone);
  
  //printing functionalities
  void printManifest(string flightNumber); 

  //helper functions
  int flightIndex(string flightNumber);
  void existingFlights();
  bool validFlightNum(string flightNumb);
  bool validDeparture(string departure);
  bool validDestination(string destination);
  void editFlight(string flightNumb);
public:
  void welcome();
  void selection();
};

#endif
