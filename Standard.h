#pragma once
#include "Room.h"
class Standard :
    public Room
{
private:
    int NumberOfBeds;
    double BedPrice;
public:
    Standard();
    void setNumberOfBeds(int NumberOfBeds);
    int getNumberOfBeds();
    void setBedPrice(double BedPrice);
    double getBedPrice();
    void display();
    double getTotalPrice();


};

