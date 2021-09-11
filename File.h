#pragma once
#include"Room.h"

class File
{
public:
	int FloorNumber;
	int NumberOfRooms;
	Room** r;
public:
 	void setFloorNumber(int FloorNumber);
	int getFloorNumber();
	void setNumberOfRooms(int NumberOfRooms);
	int getNumberOfRooms();
	void display();    //display rooms in one floor
	void AvailableRooms();     //display available rooms in one floor
	double calculateprofits();
};

