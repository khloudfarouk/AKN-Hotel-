#pragma once
#include"Room.h"
class Floor
{
public:
	int FloorNumber;
	int NumberOfRooms;
	Room** r;
public:
	Floor();
	void setFloorNumber(int FloorNumber);
	int getFloorNumber();
	void setNumberOfRooms(int NumberOfRooms);
	int getNumberOfRooms();
	void display();    //display rooms in one floor
	void AvailableRooms();     //display available rooms in one floor
	double calculateprofits();              //calculate the profits in one floor

};

