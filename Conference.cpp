#include<iostream>
using namespace std;
#include "Conference.h"
Conference::Conference()
{
	NumberOfSeats = 0;
	SeatPrice = 0.0;
}
void   Conference::setNumberOfSeats(int NumberOfSeats)
{
	this->NumberOfSeats = NumberOfSeats;
}
int   Conference::getNumberOfSeats()
{
	return this->NumberOfSeats;
}
void   Conference::setSeatPrice(double SeatPrice)
{
	this->SeatPrice = SeatPrice;
}
double   Conference::getSeatPrice()
{
	return this->SeatPrice;
}
void   Conference::display()                        //display one room
{
	cout << "Kind           RoomNumber     DayOfReservation       IsReversed      NumberOfSeats           SeatPrice\n";
	Room::display();
	cout << NumberOfSeats << "                  " << SeatPrice << endl;
}
double   Conference::getTotalPrice()                      //display total price per room conference
{
	return NumberOfSeats * SeatPrice * this->getDayOfReservation();
}