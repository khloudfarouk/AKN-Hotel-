#pragma once
#include "Room.h"
class Sweet :
    public Room
{
private:
	double PricePerNight;
public:
	Sweet();
	void setPricePerNight(double PricePerNight);
	double getPricePerNight();
	void display();
	double getTotalPrice();
};

