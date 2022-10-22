#include "Console.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

vector<Flight> currentFlights = {};

void Console::welcome(){
  string s;
  s = "---- Cosmos Spacelines Flight Booking System (CREW) ----\n\n";
  s+= "Allowable Number Selections:\n";
  s += "\t[1] Make Booking\n";
  s += "\t[2] Cancel Booking\n";
  s += "\t[3] Flight Passenger Manifest\n";
  //s += "\t[4] Display Customer Bookings\n";
  s += "\t[4] Add Flight\n";
  s += "\t[5] Cancel Flight\n";
  s += "\t[6] Display Existing Flights\n";
  s += "\t[7] Edit Flight Departure Time \n";
  cout<< s << endl;
}


void Console::selection(){
  cout << "*** Please input the appropriate number action:\n";

  string consoleInput;
  cin >> consoleInput;

  if (consoleInput.length() != 1 || !isdigit(consoleInput[0])){
    cout << "Selection Invalid." << endl;
    return;
  }
  int input = stoi(consoleInput);
  
  if (input == 6){
    existingFlights();
    return;
  }
  else if (!(input <= 7 && input >=1)){
    cout << "Selection Invalid." << endl;
    return;
  }
  
  string flightN; 
  cout << "Please enter flight number: ";
  cin >> flightN;//check if flight number is valid - i.e. not negative
  if (!validFlightNum(flightN)){
    cout << "Invalid flight number. Unable to process step." << endl;
    return;
  }
  
  if (input == 4){
    if (flightIndex(flightN)==-1){//not in array
      addFlight(flightN);
      return;
    }
    else{
      cout << "Flight number already used." << endl;
    }
  }
  else{
    if (flightIndex(flightN)==-1){
      cout << "Invalid flight number." << endl;
      return;
    }
  }
 
  if (input == 1){
    bookReservation(flightN);
    }
  else if (input == 2){
    cout << "Please select a passenger finding method:" << endl;
    cout << "\t[a] Passenger ID\n";
    cout << "\t[b] Passenger Name, Address, and Phone\n";
      
    char selection;
    cin >> selection;
    if (selection == 'a' || selection == 'A'){//passenger ID
      string id;
      cout << "Please enter passenger id (format: P#): ";
      cin >> id;
      cancelReservation(flightN, id);
    }
    else if (selection == 'b' || selection == 'B'){//passengerInfo
      string firstN, lastN, addr, phone;
      cout << "Enter First Name: ";
      cin >> firstN;
      cout << "Enter Last Name: ";
      cin >> lastN;
      cout << "Enter Address: ";
      //prevent line from stop reading due to space
      cin.ignore();
      getline(cin, addr);
      cout << "Enter Phone Number: ";
      cin >> phone;
      cancelReservation(flightN, firstN, lastN, addr, phone);
    }
    else{//invalid selection
      cout << "Invalid option. Cancellation unsuccessful." << endl;
    }
  }
  else if (input == 3){
    printManifest(flightN);
  }
  else if (input == 5){
    cancelFlight(flightN);
  }
  else if (input == 7){
    editFlight(flightN);
  }
}


bool Console::validFlightNum(string flightNumb){
  if (flightNumb.length() == 1 && flightNumb[0]=='0'){
    return false; //flight number cannot be 0
  }
  else{
    for (int i=0; i<flightNumb.length(); i++){
      if (flightNumb[i]<48 || flightNumb[i]>57){
        return false;
      }
    }
  }
  return true;
}

bool Console::validDeparture(string departure){
  if (departure.length()!=1){
    return false;
  }
  else{
    if (departure[0]>=48 && departure[0]<=55){
      return true;
    }
    return false;
  }
}

bool Console::validDestination(string destination){
  if (destination.length()!=1){
    return false;
  }
  else{
    if (destination[0]>=48 && destination[0]<=55){
      return true;
    }
    return false;
  }
}

void Console::addFlight(string flightNum){
  cout << "Numerical Indices Reference Sheet: Planet Locations" << endl;
  cout << "\t[0] Earth" << endl;
  cout << "\t[1] Moon" << endl;
  cout << "\t[2] Mars" << endl;
  cout << "\t[3] Venus" << endl;
  cout << "\t[4] Titan (Saturn)" << endl;
  cout << "\t[5] Mercury" << endl;
  cout << "\t[6] Europa (Jupiter)" << endl;
  cout << "\t[7] International Space Station" << endl;
  
  string depPlanet, destPlanet;
  
  cout << "Please enter departure planet index (number between 0-7): ";
  cin >> depPlanet;
  if (!validDeparture(depPlanet)){
    cout << "Invalid entry. Please enter the corresponding number between 0 and 7: " << endl;
    cin >> depPlanet;
    if (!validDeparture(depPlanet)){//if not valid, exit
      cout << "Departure planet invalid. Unable to add flight." << endl;
      return;
    }
  }
  
  cout << "Please enter destination planet index (number between 0-8): ";
  cin >> destPlanet;
  if (!validDestination(destPlanet) || (depPlanet.compare(destPlanet)==0)){//departure not same as destPlanet
    cout << "Invalid entry. Please try again: " << endl;
    cin >> destPlanet;
    if (!validDestination(destPlanet) || (depPlanet.compare(destPlanet)==0)){//if not valid, exit
      cout << "Destination planet invalid. Unable to add flight." << endl;
      return;
    }
  }

  //check if flight departure time is valid
  int depHour, depMin; //MUST be integer
  cout << "Please enter departure hour (number: 0-24): " << endl;
  cin >> depHour;
  cout << "Please enter departure minute (number: 0-60): " << endl;
  cin >> depMin;

  Seat a1("1A");
  Seat a2("1B");
  Seat a3("2A");
  Seat a4("2B");
  Seat a5("3A");
  Seat a6("3B");
  Seat a7("4A");
  Seat a8("4B");
  Seat a9("5A");
  Seat a10("5B");
  array<Seat, 10> emptySeating = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10};
  //Seat emptySeating[10] = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10};

  Flight f(emptySeating, flightNum, stoi(depPlanet), stoi(destPlanet), depHour, depMin);
  currentFlights.push_back(f);
  cout << "Flight CS" << flightNum << " ADDED." << endl;
  cout << "\t Departure Planet: " << currentFlights[currentFlights.size()-1].getDepPlanet() << endl;
    cout << "\t Destination Planet: " << currentFlights[currentFlights.size()-1].getDestPlanet() << endl;
    cout << "\t Departure Time: " << currentFlights[currentFlights.size()-1].getDepTime() << endl;
    cout << "\t Number of Passengers: " << currentFlights[currentFlights.size()-1].getNumPass() << endl;
}

//find index of flight object in currentFlights vector
int Console::flightIndex(string flightNumber){
  for (int i=0; i<currentFlights.size(); i++){
    //currentFlights[i]->getFlightNumber()==flightNumber
    if (currentFlights[i].getFlightNumber()==flightNumber){
      return i;
    }
  }
  return -1; //invalid
}

//cancel entire flight
void Console::cancelFlight(string flightNumber){
  //print contact info for passengers who reserved seats
  printManifest(flightNumber);
  currentFlights.erase(currentFlights.begin()+flightIndex(flightNumber));
  cout << "Flight CS" << flightNumber << " CANCELLED." << endl;
}

//cancel reservation using passengerID and flight number
void Console::cancelReservation(string flightNumber, string passengerID){
  int flight = flightIndex(flightNumber);
  string resp = currentFlights[flight].findSeat(passengerID);
  if (resp == "Seat not found."){
    cout << "Passenger booking not found on Flight " << flightNumber << "." << endl;
  }
  else{
    cout << "The following passenger booking has been CANCELLED on Flight " << flightNumber << "." << endl;
    currentFlights[flight].printSeat(resp);
    currentFlights[flight].emptySeat(resp);
  }
}

//cancel reservation using passenger information and flight number
void Console::cancelReservation(string flightNumber, string first, string last, string address, string phone){
  int flight = flightIndex(flightNumber);
  //if (flight ==-1){
  //  cout << "Flight number invalid." << endl;
  //}
  //else{
    //string resp = currentFlights[flight]->findSeat(first, last, address, phone);
    string resp = currentFlights[flight].findSeat(first, last, address, phone);
    if (resp == "Seat not found."){
      cout << "Passenger booking not found on Flight " << flightNumber << "." << endl;
    }
    else{
      cout << "The following passenger booking has been CANCELLED on Flight " << flightNumber << "." << endl;
      //print Info from seat class
      //currentFlights[flight]->printSeat(resp);
      //currentFlights[flight]->emptySeat(resp);
      currentFlights[flight].printSeat(resp);
      currentFlights[flight].emptySeat(resp);
    }
  //}
}

void Console::bookReservation(string flightNumber){
  int ind = flightIndex(flightNumber);
 
  if (currentFlights[ind].getNumPass()==10){
    cout << "Flight is full." << endl;
  }
  else{
    //show available seats and flight diagram
    currentFlights[ind].printSeatingDiagram();
    currentFlights[ind].printAvailableSeats();

    //prompt seat
    cout << "Please choose one of the available seats" << endl;
    string seatChoice, seat;
    cin >> seat;
    
    seatChoice += seat[0];
    seatChoice +=toupper(seat[1]);
    
    if (currentFlights[ind].checkSeatAvailable(seatChoice)){
      //seat is available
      cout << "Seat " << seatChoice << " is available. Please select a method to input passenger information:"<<endl;
      cout << "\t[a] Passenger ID\n";
      cout << "\t[b] Passenger Name, Address, and Phone\n";
      string method;
      cin >> method;
      if (method == "a" || method == "A"){
        cout << "Enter Passenger ID: ";
        string id;
        cin >> id;
        currentFlights[ind].setSeat(seatChoice, id);
        if (currentFlights[ind].checkSeatAvailable(seatChoice)){
          cout << "Booking Invalid." << endl;//passenger ID not set, booking not made
        }
        else{
          //print ticket info from seat class
          currentFlights[ind].printSeat(seatChoice);
        }
      }
      else if (method == "b" || method == "B"){
        string firstN, lastN, addr, phone;
        cout << "Enter First Name: ";
        cin >> firstN;
        cout << "Enter Last Name: ";
        cin >> lastN;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, addr);
        cout << "Enter Phone Number: ";
        cin >> phone;
        currentFlights[ind].setSeat(seatChoice, firstN, lastN, addr, phone);
        cout << "Passenger Booking CONFIRMATION for Flight " << flightNumber << ":" << endl;
        //print ticket info from seat class
        currentFlights[ind].printSeat(seatChoice);
      }
      else{
        cout << "Invalid option. Booking terminated." << endl;
      }
    }
    else{
      cout << "Seat is unavailable." << endl;
    }
  }
}

void Console::existingFlights(){
  if (currentFlights.size()==0){
    cout << "No existing flights." << endl;
  }
  else{
    cout << "EXISTING Flights" << endl;
    for (int i = 0; i<currentFlights.size(); i++){
    cout << "-- Flight CS" << currentFlights[i].getFlightNumber() << "--"<< endl;
    cout << "\t Departure Planet: " << currentFlights[i].getDepPlanet() << endl;
    cout << "\t Destination Planet: " << currentFlights[i].getDestPlanet() << endl;
    cout << "\t Departure Time: " << currentFlights[i].getDepTime() << endl;
    cout << "\t Number of Passengers: " << currentFlights[i].getNumPass() << endl;
  }
  }
}

void Console::editFlight(string flightNumb){
    int ind = flightIndex(flightNumb);
    cout << "-- Current Flight Information for CS" << currentFlights[ind].getFlightNumber() << "--"<< endl;
    cout << "\t Departure Planet: " << currentFlights[ind].getDepPlanet() << endl;
    cout << "\t Destination Planet: " << currentFlights[ind].getDestPlanet() << endl;
    cout << "\t Departure Time: " << currentFlights[ind].getDepTime() << endl;
    cout << "\t Number of Passengers: " << currentFlights[ind].getNumPass() << endl;

    int depHour, depMin; //MUST be integer
    cout << "Please enter UPDATED departure hour (number: 0-24): " << endl;
    cin >> depHour;
    cout << "Please enter UPDATED departure minute (number: 0-60): " << endl;
    cin >> depMin;
    currentFlights[ind].setDepTime(depHour, depMin);

    cout << "-- UPDATED Flight Information for CS" << currentFlights[ind].getFlightNumber() << "--"<< endl;
    cout << "\t Departure Planet: " << currentFlights[ind].getDepPlanet() << endl;
    cout << "\t Destination Planet: " << currentFlights[ind].getDestPlanet() << endl;
    cout << "\t Departure Time: " << currentFlights[ind].getDepTime() << endl;
    cout << "\t Number of Passengers: " << currentFlights[ind].getNumPass() << endl;
}


void Console::printManifest(string flightNumber){
  int ind = flightIndex(flightNumber);
  if (currentFlights[ind].getNumPass()==0){
    cout << "NO PASSENGERS." << endl;
  }
  else{
    cout << "Please select passenger manifest type:" << endl;
    cout << "\t[a] Passenger Manifest (Sorted by Seat Number)\n";
    cout << "\t[b] Full Passenger Manifest (Including Empty Seats)\n";
    cout << "\t[c] Passenger Manifest (Sorted Alphabetically)\n";
    string inp;
    cin >> inp;
    if (inp == "a"){
      currentFlights[ind].printManifest();
    }
    else if (inp == "b"){
      currentFlights[ind].printManifestFull();
    }
    else if (inp == "c"){
      currentFlights[ind].printManifestAlphabetical();
    }
    else{
      cout << "Selection invalid." << endl;
    }
  }
}
