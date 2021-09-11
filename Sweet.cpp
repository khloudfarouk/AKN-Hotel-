#include<iostream>
#include<iostream>
using namespace std;
#include "Sweet.h"
Sweet::Sweet()
{
	PricePerNight = 0.0;
}
void  Sweet::setPricePerNight(double PricePerNight)
{
	this->PricePerNight = PricePerNight;
}
double  Sweet::getPricePerNight()
{
	return this->PricePerNight;
}
void  Sweet::display()                     //display one room
{
	cout << "Kind           RoomNumber     DayOfReservation       IsReversed      PricePerNight\n";
	Room::display();
	cout << PricePerNight << endl;
}
double  Sweet::getTotalPrice()
{
	return PricePerNight * this->getDayOfReservation();
}