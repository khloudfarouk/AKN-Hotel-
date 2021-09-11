#pragma once
#include<string>
using namespace std;
class Room
{
protected:

	int RoomNumber;
	int DayOfReservation;
	bool IsReversed;
	string Kind;
public:
	Room();
	void setKind(string Kind);
	string getKind();
	void setRoomnumber(int RoomNumber);
	int getRoomNumber();
	void setDayOfReservation(int DayOfReservation);
	int getDayOfReservation();
	void setIsReversed(bool IsReversed);
	bool getIsReversed();
	virtual void display();
	virtual double getTotalPrice();

};

