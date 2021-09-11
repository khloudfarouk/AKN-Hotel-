#pragma once
#include "Room.h"
class Conference :
    public Room
{
private:
	int NumberOfSeats;
	double SeatPrice;
public:
	Conference();
	void setNumberOfSeats(int NumberOfSeats);
	int getNumberOfSeats();
	void setSeatPrice(double SeatPrice);
	double getSeatPrice();
	void display();
	double getTotalPrice();

 
};

