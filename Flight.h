#include <array>
#include "Seat.h"

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight{
  private:
    array<Seat, 10> seatList;
    int numPassengers;

    string flightNumber;

    //correspond to index in locations array
    int departurePlanet;
    int destinationPlanet;
    string departureTime;
    
  public:
    Flight(array<Seat, 10> seat);
    Flight(array<Seat, 10> seat, string flightNum, int dep, int dest);
    Flight(array<Seat, 10> seat, string flightNum, int dep, int dest, int hour, int minute);

    int getNumPass();
    void setPass(int num); //remove later - for testing

    //sorting algorithms
    int seatIndex(string seat);
    string capitalizeFullName(string name);

    //seating availability & diagrams
    void printSeatingDiagram();
    void printAvailableSeats();
    bool checkSeatAvailable(string seatNumber);

    //passenger manifests
    void printManifest(); //sorted by seat number, passengers only
    void printManifestFull(); //unreserved seats also included
    void printManifestAlphabetical(); //passengers shouldn't have same name

    //seats reservations
    void setSeat(string seatNumber, string passengerID);
    void setSeat(string seatNumber, string first, string last, string address, string phone);
    void emptySeat(string seatNumber);

    //seat information
    string findSeat(string passengerID); //OPTIMIZE using numObjects...
    string findSeat(string first, string last, string address, string phone);
    void printSeat(string seatNumber);

    //flight information attributes
    string getFlightNumber();
    string getDepPlanet();
    string getDestPlanet();
    string getDepTime();

    void setFlightNumber(string num);
    void setDestPlanet(int index);
    void setDepPlanet(int index);
    void setDepTime(int hr, int minute); //parameters
};

#endif
