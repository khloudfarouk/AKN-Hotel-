
#include "Floor.h"
Floor::Floor()
{
	FloorNumber = 0;
	NumberOfRooms = 0;
	r = new Room * [NumberOfRooms];
}
void  Floor::setFloorNumber(int FloorNumber)
{
	this->FloorNumber = FloorNumber;
}
int  Floor::getFloorNumber()
{
	return this->FloorNumber;
}
void  Floor::setNumberOfRooms(int NumberOfRooms)
{
	this->NumberOfRooms = NumberOfRooms;
}
int  Floor::getNumberOfRooms()
{
	return this->NumberOfRooms;
}
void  Floor::display()    //display rooms in one floor
{
	for (int i = 0; i < this->getNumberOfRooms(); i++)
	{
		r[i]->display();
	}
}
void Floor::AvailableRooms()      //display available rooms in one floor
{
	for (int i = 0; i < this->getNumberOfRooms(); i++)
	{
		if (r[i]->getIsReversed() == false)
		{
			r[i]->display();
		}
	}
}
double Floor::calculateprofits()               //calculate the profits in one floor
{
	double sum = 0;
	for (int i = 0; i < this->getNumberOfRooms(); i++)
	{
		sum += r[i]->getTotalPrice();
	}
	return sum;
}