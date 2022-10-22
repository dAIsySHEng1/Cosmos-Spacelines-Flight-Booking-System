### Cosmos Spacelines Booking System User Manual

Cosmos Spacelines is a space tourism company servicing various planetary locations. Each flight rocket contains 10-seats. This C++ text-based program allows crew members to add flights, edit flight information, book and cancel seat reservations, and view passenger manifests.

#### Running and Quitting the Booking System
Quit the Program: type QUIT when prompted (one word, no spaces, all caps) 

Running the Program: You may only input one action at a time. The program will allow you to continuously enter actions as long as you input anything other than QUIT.

*Note: if prompted to press any key to continue, the "Enter" button does not suffice

#### Overview of the System

Every flight has an available seating list for 10 passengers, in addition to a departure location, destination location, departure time, and flight number. All seats will initially be empty, and you will be able to fill them up with passengers by using this booking system.

When a new passenger registers, you will be asked to enter their first name, last name, address (i.e. for a house), and phone number. They will have a passenger ID assigned to them (format: P#) after the booking. For future bookings for this same passenger, inputting the passenger ID will assign the seat to them (so no need to input their personal information again). Seats have seat numbers from 1A to 5B, and passengers can choose to book the available ones. 

#### Booking System Selections
Input the corresponding number from 1 to 7 when prompted for your desired action selection. 

    Table of Actions
      1 = Make a Seat Booking
      2 = Cancel a Seat Booking
      3 = Print Manifest of a Flight 
      4 = Add a new Flight
      5 = Cancel an existing Flight 
      6 = Display Details of Existing Flights
      7 = Edit Flight Details (specifically: Departure Time)

*Note: always start by ADDING A FLIGHT or else most selections will be invalid.

**Note: only input numbers or your selection will be invalid (indicated in Console). 


#### Make a Booking (Input: 1)

*Flight Number*: enter a positive integer corresponding to an existing flight (i.e. already added). Do *NOT* include the preceding "CS" that is attached to all Cosmos Spacelines flight numbers.

The program will proceed to print the current seating diagram of the flight. For example:

    _  A   B
    1 [x] [ ]
    2 [ ] [x]
    3 [ ] [ ]
    4 [x] [x]
    5 [ ] [x]
Each spaceship has 5 rows of seats, as indicated by the numbering in the first column of the seating diagram above. Each row contains a seat A and a seat B. If a seat is *occupied*, the seat will be shown as [x]. If a seat is empty/available, the seat will be shown as [ ]. 

In addition to the seating diagram, the available seats on a flight will be printed to the console when you make a booking, making the process easier. Seats can also be entered with an uppercase or lowercase letter (1A and 1a indicate the same seat).

Seat is Available: You will be prompted to enter passenger information using a passenger ID or general information. You will see the below message asking you to select a method.

    [a] Passenger ID
    [b] Passenger Name, Address, and Phone

If the passenger has already booked a seat before, choose "a" and simply input their passenger id (ex. P1) to fill in all the contact information fields. Otherwise, choose "b" and you will be prompted for the passenger's first name, last name, address, and phone number. 

*Note: a valid *phone number* can only constitute of numbers and hyphens, though  the program will check that the input does not consist solely of hyphens

**Note: once you have filled out all the fields, a message will print the booking information. If it is incorrect, select **2** to cancel the booking and then select **1** afterwards to remake the booking.

#### Cancel a Booking (Input: 2)

*Flight Number*: enter a positive integer corresponding to an existing flight (ex. 1). Do *NOT* include the preceding "CS".

You will be given an option to find the passenger's seating information using their a) passenger ID or b) general passenger information.

*Passenger ID*: enter the passenger id with the preceding "P" (ex. P1).

*General Information*: All fields (first name, last name, address, phone number) must be an exact match so that the searching function can find the corresponding passenger. 

The Console will output a cancellation message informing you of the passenger information that has been removed from the seat.

#### Flight Passenger Manifest (Input: 3)

After inputting a flight number when prompted, you will be able to select one of three passenger manifest options:

    [a] Passenger Manifest (Sorted by SEAT Number)
    [b] Full Passenger Manifest (Sorted by SEAT Number and includes EMPTY seats)
    [c] Passenger Manifest (Sorted ALPHABETICALLY)

Upon selecting one of the options, the manifest will be appropriately printed. You will not be able to print to manifests of any flights that were cancelled.


#### Add a Flight (Input: 4)

The program will prompt you for a flight number, destination location, departure location, and departure time (specifically, hour & minute).

*Flight Number*: must be a positive integer (the program will check for invalid entries and also prevent duplicates of existing flight numbers)

*Departure and Destination Locations*: Enter a number between 0 and 7 that corresponds to the desired departure and destination locations. The destination and departure locations cannot be the same or outside this range. If they are, the program will prompt again for a number. If it is not a valid selection, you will be unable to add the flight and will need to try again.

    Table of Locations
      0 = Earth
      1 = Moon
      2 = Mars
      3 = Venus
      4 = Titan (Saturn)
      5 = Mercury
      6 = Europa (Jupiter)
      7 = International Space Station

*Departure Hour*: The program uses the 24-hour clock, so please enter the appropriate departure hour. For example, a departure time of 13:15 requires you to input 13 when prompted for the departure hour. If you input an invalid hour, the departure time will not be set for the flight.

*Departure Minute*: Enter the minute portion of the departure time. If you input a number less than 60 or containing invalid characters, the departure time will not be set for the flight. If the departure minutes exceed 60, the program will automatically adjust the number of hours to account for the extra.

*Note: a flight will be added if flight number, departure location, and destination location are valid, even if departure hour/minute are invalid. You will be able to edit the departure time of a flight by selecting **7** (Edit Flight Details).

#### Cancel Flight (Input: 5)

You will be prompted for a *flight number* (enter a valid integer). The passenger manifest, sorted by seat location, will be printed out. If no passengers made bookings for the flight, the passenger manifest will appear as NO PASSENGERS. You will also see a message telling you that a particular flight has been cancelled. 

#### Display Existing Flights (Input: 6)

All existing flights will be displayed on the screen, along with their departure/destination locations and times as well as number of passengers. The flights will be printed based on the order with which they were added. Flights with invalid departure times will have a "-" in place instead.

#### Edit Flight Departure Time (Input: 7)

You are able to edit the departure time of a flight. If a flight's initial departure time was invalid and currently has a "-" as a placeholder, use this selection to edit the information. If the departure time has already been set and you would like to change it, selecting **7** will also make that your desired time change given that the hour and minutes you enter are valid.
