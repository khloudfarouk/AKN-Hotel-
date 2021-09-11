#include<iostream>
using namespace std;
#include "Room.h"
Room::Room()
{
	Kind = " ";
	RoomNumber = 0;
	DayOfReservation = 0;
	IsReversed = false;
}
void Room::setKind(string Kind)
{
	this->Kind = Kind;
}
string Room::getKind()
{
	return this->Kind;
}
void Room::setRoomnumber(int RoomNumber)
{
	this->RoomNumber = RoomNumber;
}
int Room::getRoomNumber()
{
	return this->RoomNumber;
}
void Room::Room::setDayOfReservation(int DayOfReservation)
{
	this->DayOfReservation = DayOfReservation;
}
int Room::getDayOfReservation()
{
	return this->DayOfReservation;
}
void Room::setIsReversed(bool IsReversed)
{
	this->IsReversed = IsReversed;
}
bool Room::getIsReversed()
{
	return this->IsReversed;
}
void Room::display()
{
	if (Kind == "Standard")
		cout << Kind << "  ";
	else if (Kind == "Sweet")
		cout << Kind << "     ";
	else if (Kind == "Conference")
		cout << Kind;

	cout << "          " << RoomNumber << "                  " << DayOfReservation << "                  " << IsReversed << "                 ";
	//cout << Kind << "          " << RoomNumber << "                  " << DayOfReservation << "                  " << IsReversed << "                 ";
}
double Room::getTotalPrice()
{
	return 0.0;
}
