#include "Passenger.h"

//global vector to house passenger objects
vector<Passenger> passengerData = {};

int Passenger::numPassengerObjects = 0;

Passenger::Passenger(){
  firstName = "open";
  lastName = "open";
  address = "open";
  phoneNumber = "open";
  passengerID = "-";
}

Passenger::Passenger(string first, string last, string address, string phoneNumber){
  numPassengerObjects++;
  setFirstName(first);
  setLastName(last);
  setAddress(address);
  setPhoneNumber(phoneNumber);
  setID();
  passengerData.push_back(*this); //add object to passengerData vector
}

string Passenger::getFirstName(){
  return firstName;
}

string Passenger::getLastName(){
  return lastName;
}

string Passenger::getAddress(){
  return address;
}

string Passenger::getPhoneNumber(){
  return phoneNumber;
}

string Passenger::getID(){
  return passengerID;
}

bool Passenger::checkLetters(string name){
  for (int i=0; i<name.length(); i++){
    if ((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || (name[i] == 45)){
      continue;
    }
    else{
      return false;
    }
  }
  return true;
}

void Passenger::setFirstName(string name){
  //checks that name is valid
  while (name.length()<=0 && checkLetters(name)){
    cout << "Invalid. Please enter a valid name: ";
    cin >> name;
  }
  firstName = name;
}

void Passenger::setFirstName(string id, string name){
  //checks that name is valid
  while (name.length()<=0 && checkLetters(name)){
    cout << "Invalid. Please enter a valid name: ";
    cin >> name;
  }
  passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].setFirstName(name);
}

void Passenger::setLastName(string name){
  while (name.length()<=0 && checkLetters(name)){
    cout << "Invalid. Please enter a valid name: ";
    cin >> name;
  }
  lastName = name;
}

void Passenger::setLastName(string id, string name){
  //checks that name is valid
  while (name.length()<=0 && checkLetters(name)){
    cout << "Invalid. Please enter a valid name: ";
    cin >> name;
  }
  passengerData[stoi(passengerID.substr(1,passengerID.length()))-1].setLastName(name);
}

void Passenger::setAddress(string address){
  this->address = address;
}

void Passenger::setPhoneNumber(string num){
  while (!(checkPhoneNumber(num))){
    cout << "Invalid. Please enter a valid phone number: ";
    cin >> num;
  }
  this->phoneNumber = num;
}

bool Passenger::checkPhoneNumber(string num){
  //check that phone number is all numbers
  int hyphenCount = 0;
  for (int i=0; i<num.length(); i++){
    if (num[i]==45){
      hyphenCount+=1;
    }
    else if(num[i]<48 || num[i]>57){
      return false;
    }
  }
  //check that phone number is not entirely hyphens
  if (hyphenCount == num.length()){
    return false;
  }
  else{
    return true;
  }
}

void Passenger::setID(){
  passengerID = "P" + to_string(numPassengerObjects);
}

string Passenger::passengerInfo(){
  //return firstName + " " + lastName;
  return lastName + ", " + firstName;
}

//when reservation is cancelled
void Passenger::emptyPassenger(){
  firstName = "open";
  lastName = "open";
  address = "open";
  phoneNumber = "open";
  passengerID = "-";
}
