#include<iostream>
using namespace std;
#include "Standard.h"

Standard::Standard()
{
	NumberOfBeds = 0;
	BedPrice = 0.0;
}
void Standard::setNumberOfBeds(int NumberOfBeds)
{
	this->NumberOfBeds = NumberOfBeds;
}
int  Standard::getNumberOfBeds()
{
	return this->NumberOfBeds;
}
void  Standard::setBedPrice(double BedPrice)
{
	this->BedPrice = BedPrice;
}
double  Standard::getBedPrice()
{
	return this->BedPrice;
}
void  Standard::display()
{

	cout << "Kind           RoomNumber     DayOfReservation       IsReversed      NumberOfBeds           BedPrice\n";
	Room::display();
	cout << NumberOfBeds << "                   " << BedPrice << endl;
}
double  Standard::getTotalPrice()              //display total price per room standard
{
	return  NumberOfBeds * BedPrice * this->getDayOfReservation();
}
