#include "Seat.h"

extern vector<Passenger> passengerData;

Seat::Seat(string seatNum){//create a default seat
  setSeatNumber(seatNum);
  passengerID = "-";
}

Seat::Seat(string seatNum, string passengerID){//populate seat number and person
  setSeatNumber(seatNum);
  setPassengerID(passengerID);
}

bool Seat::validSeatNum(string seatNum){
  if (seatNum[1]!='A' && seatNum[1]!='B'){
    return false;
  }
  else if (seatNum[0]<49 || seatNum[0]>53){
    return false;}
  return true;
}

void Seat::setSeatNumber(string seatNumber){
  while (!validSeatNum(seatNumber)){
    cout << "Invalid. Please enter a valid seat number: ";
    cin >> seatNumber;
  }
  this->seatNumber = seatNumber;
}

bool Seat::checkNumbers(string id){
  for (int i=1; i<id.length(); i++){
    if(id[i]<48 || id[i]>57){
      return false;
    }
  }
  return true;
}

bool Seat::validID(string id){
  if (id.length() < 2){
    return false;
  }
  else if (id[0] != 'P'){
    return false;
  }
  else if (!checkNumbers(id)){
    return false;
  }
  else if ((stoi(id.substr(1,id.length())) > Passenger::numPassengerObjects) || (stoi(id.substr(1,id.length()))==0)){
    return false;
  }
  return true;
}

void Seat::setPassengerID(string id){
  int counter = 0;
  while (!validID(id) && counter<=3){
    cout << "Invalid. Please enter a valid passenger ID: ";
    cin >> id;
    counter++;
  }
  if (!validID(id)){
    cout << "Invalid." << endl;
    passengerID = "-";
    return;
  }
  else{
    passengerID = id;
    }
}

string Seat::getPassengerID(){
    return passengerID;
}

string Seat::getSeatNumber(){
    return seatNumber;
}

void Seat::setPassenger(string first, string last, string address, string phone){
  Passenger newPass(first, last, address, phone);
  passengerID = newPass.getID();
  //testing
  //cout << "PassID: " << passengerID << endl;
}

bool Seat::isReserved(){
  if ((passengerID == "-")){
    return false;
  }
  return true;
}

void Seat::clearSeat(){
  passengerID = "-";
}

void Seat::printSeatInfo(){
  int indexing = stoi(passengerID.substr(1,passengerID.length()))-1;
  cout << "----Seat " << getSeatNumber() << "----" << endl;
  //cout << "Seat: " << getSeatNumber() << endl;
  cout << "Passenger: " << passengerData[indexing].passengerInfo() << endl;
  cout << "Address: " << passengerData[indexing].getAddress() << endl;
  cout << "Phone #: " << passengerData[indexing].getPhoneNumber() << endl;
  cout << "Passenger ID: " << passengerData[indexing].getID() << endl;
}

string Seat::getFirstName(){
  return passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getFirstName();
}

string Seat::getLastName(){
  return passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getLastName();
}

string Seat::getFullName(){
  return passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getLastName() + ", " + passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getFirstName();
}

string Seat::getAddress(){
  return passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getAddress();
}

string Seat::getPhoneNum(){
  return passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].getPhoneNumber();
}
