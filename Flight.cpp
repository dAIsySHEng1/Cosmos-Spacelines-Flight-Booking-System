#include "Flight.h"

string seatNames[10] = {"1A", "1B", "2A", "2B", "3A", "3B", "4A", "4B", "5A", "5B"};

string flightLocations[8] = {"Earth", "Moon", "Mars", "Venus", "Titan", "Mercury", "Europa", "International Space Station"};

//always 10 objects - empty seats still store objects
Flight::Flight(array<Seat, 10> Seating): seatList(Seating){
  //seatList = &seatLst;
  numPassengers = 0;
}

Flight::Flight(array<Seat, 10> Seating, string flightNum, int dep, int dest): seatList(Seating){
  //use getters and setters for dep, dest, flightNum
  numPassengers = 0;

  setFlightNumber(flightNum);
  setDepPlanet(dep);
  setDestPlanet(dest);
}

Flight::Flight(array<Seat, 10> Seating, string flightNum, int dep, int dest, int depHour, int depMinute): seatList(Seating){
  //use getters and setters for dep, dest, flightNum
  numPassengers = 0;

  setFlightNumber(flightNum);
  setDepPlanet(dep);
  setDestPlanet(dest);
  setDepTime(depHour, depMinute);
}

int Flight::seatIndex(string seat){
  for (int i=0; i<10; i++){
    if (seatNames[i]==seat){
      return i;
    }
  }
  return -1; //invalid
}

int Flight::getNumPass(){
  return numPassengers;
}

void Flight::setPass(int num){
  numPassengers = num;
}

void Flight::printSeatingDiagram(){
  cout << "    A   B" << endl;
  bool ele1;
  for (int i=0; i<10; i+=2){
    cout << i/2 + 1 << "  ";
    ele1 = (seatList[i].getPassengerID()=="-");
    //seatList[i]->getPassengerID()=="-"
    if (ele1){
      cout << "[ ]";
      //cout << "[in here 1]";
    }
    else{
      cout << "[x]";
      //cout << "[in here 2]";
    }
    cout << " ";
    if (seatList[i+1].getPassengerID() == "-"){
      cout << "[ ]";
      //cout << "[in here 3]";
    }
    else{
      cout << "[x]";
    }
    cout << "\n";
  }
}

void Flight::printAvailableSeats(){
  string output = "";
  for (int i=0; i<10; i++){
    if (seatList[i].getPassengerID() == "-"){
      output += seatNames[i] + "  ";
    }
  }
  cout << "Available Seats: "; 
  if (output.length()!=0){
    cout << output << endl;
  }
  else{
    cout << "None"<<endl;
  } 
}


bool Flight::checkSeatAvailable(string seatNumber){
  if (seatIndex(seatNumber) == -1){
    return false;
  }
  else{
    Seat s = seatList[seatIndex(seatNumber)];
    if (!(s.validSeatNum(seatNumber))){
      return false;
    }
    return !(seatList[seatIndex(seatNumber)].isReserved());
  }
}

void Flight::printManifest(){
  //cout << "printManifest:\n";
  for (int i=0; i<10; i++){
    if (seatList[i].isReserved()){
      (seatList[i]).printSeatInfo();
      cout << "\n";
    }
  }
}

void Flight::printSeat(string seatNumber){
  seatList[seatIndex(seatNumber)].printSeatInfo();
}

void Flight::printManifestFull(){
  for (int i=0; i<10; i++){
    if (seatList[i].isReserved()){
      (seatList[i]).printSeatInfo();
    }
    else{
      cout << "----Seat " << seatList[i].getSeatNumber() << "----" << endl;
      cout << "Passenger: " << "-" << endl;
      cout << "Address: " << "-" << endl;
      cout << "Phone #: " << "-" << endl;
    }
    cout << "\n";
  }
}

void Flight::setSeat(string seatNumber, string passengerID){
  if (checkSeatAvailable(seatNumber)){
    seatList[seatIndex(seatNumber)].setPassengerID(passengerID);
    numPassengers +=1;
  }
  else{
    cout << "Seat " << seatNumber << " is currently unavailable." << endl;
  }
}

void Flight::setSeat(string seatNumber, string first, string last, string address, string phone){
  if (checkSeatAvailable(seatNumber)){
    seatList[seatIndex(seatNumber)].setPassenger(first, last, address, phone);
    numPassengers +=1;
  }
  else{
    cout << "Seat " << seatNumber << " is currently unavailable." << endl;
  }
}

void Flight::emptySeat(string seatNumber){
  seatList[seatIndex(seatNumber)].clearSeat();
  numPassengers -=1;
}

string Flight::findSeat(string passengerID){
  //check valid ID from Seat Class?
  string currID;
  for (int i=0; i<10; i++){
    currID = seatList[i].getPassengerID();
    if (currID == "-"){
      continue;
    }
    else if (currID == passengerID){
      return seatNames[i];
    }
  }
  return "Seat not found.";
}

string Flight::findSeat(string first, string last, string address, string phone){
  //string currID;
  for (int i=0; i<10; i++){
    //currID = seatList[i]->getPassengerID();
    if (seatList[i].getPassengerID() == "-"){
      continue;//seat is empty
    }
    else if ((seatList[i].getFirstName() == first) && (seatList[i].getLastName() == last) && (seatList[i].getAddress() == address) && (seatList[i].getPhoneNum() == phone)){
      return seatNames[i];
    }
  }
  return "Seat not found.";
}

string Flight::capitalizeFullName(string name){
  string out = "";
  for (int i=0; i<name.length(); i++){
    out += toupper(name[i]);
  }
  return out;
}


void Flight::printManifestAlphabetical(){
  //array with only non-empty passenger objects
  vector<Seat> occupiedSeats;
  //int index = 0;
  for (int i=0; i<10; i++){
    if (seatList[i].getPassengerID() != "-"){
      occupiedSeats.push_back(seatList[i]);
    }
  }

  //selection sort
  int counter;
  Seat temp("1A");
   //maxIndex stores index of largest element in unsorted portion of array
  int maxIndex;
  string n1, n2;
  //backwards for loop ensures that we can place largest elements at the end of the array
  for (int i=numPassengers-1; i > 0; i--) {  
    maxIndex = 0; //assume first element is largest 
    //compare value with any element in the list
    for (int j=1; j <= i; j++) {
      n1 = capitalizeFullName(occupiedSeats[j].getFullName());
      n2 = capitalizeFullName(occupiedSeats[maxIndex].getFullName());
      if (n1.compare(n2)>0){
        maxIndex=j; //if larger found, set new largest
      }
    }
    //swap element at end of unsorted array with the one at maxIndex
    temp = occupiedSeats[i];
    occupiedSeats[i] = occupiedSeats[maxIndex];
    occupiedSeats[maxIndex] = temp;
  }

  for (int i=0; i<numPassengers; i++){
    cout << "----Name: " << occupiedSeats[i].getFullName() << "----" << endl;
      cout << "Seat #: " << occupiedSeats[i].getSeatNumber() << endl;
      cout << "Address: " << occupiedSeats[i].getAddress() << endl;
      cout << "Phone #: " << occupiedSeats[i].getPhoneNum() << endl;
      cout << "Passenger ID: " << occupiedSeats[i].getPassengerID() << endl;
      cout << "\n";
  }
}

string Flight::getFlightNumber(){
  return flightNumber;
}

string Flight::getDepPlanet(){
  return flightLocations[departurePlanet];
}

string Flight::getDestPlanet(){
  return flightLocations[destinationPlanet];
}

string Flight::getDepTime(){
  return departureTime;
}


void Flight::setFlightNumber(string num){
  //ensure that flight number not already taken - implemented in Console class
  if (stoi(num)>0){
    flightNumber = num; 
  }
  else{
    cout << "Invalid flight number. Change not made.";
  }
}

void Flight::setDestPlanet(int ind){
  if (ind<0 || ind>=8){
    cout << "Location selection invalid." << endl;
  }
  else{
    destinationPlanet = ind;
  }
}

void Flight::setDepPlanet(int ind){
  //already checked in console
  if (ind<0 || ind>=8){
    cout << "Location selection invalid." << endl;
  }
  else{
    departurePlanet = ind;
  }
}

void Flight::setDepTime(int hr, int minute){
  //24-hour clock
  if (hr<0 || hr>24){
    cout << "Invalid time." << endl;
    departureTime = "-";
  }
  else if (minute<0){
    cout << "Invalid time." << endl;
    departureTime = "-";
  }
  else{
    hr += minute/60;
    hr = hr%24; //ensures that hours do not exceed 24
    minute%=60;
    //cout << "Minute: " << minute<< endl;
    //check if minute is single digit
    if (minute<10 && minute!=0){
      departureTime = to_string(hr) + ":0" + to_string(minute);
    }
    else if (minute == 0){
      departureTime = to_string(hr) + ":00";
    }
    else{//minute is double digit
      departureTime = to_string(hr) + ":" + to_string(minute);
    }
  }
}
