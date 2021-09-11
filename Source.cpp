#include"Room.h"
#include"Standard.h"
#include"Sweet.h"
#include"Conference.h"
#include"Floor.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void WriteFile();
void Menu(Floor*& f, int numberoffloors);
int main()
{
	WriteFile();
	ifstream input;
	input.open("configuration.txt");
	string n;
	int numberoffloors;
	input >> n;
	input >> numberoffloors;
	Floor* f = new Floor[numberoffloors];
	for (int i = 0; i < numberoffloors; i++)
	{

		int FloorNumber;
		input >> n;
		input >> FloorNumber;
		f[i].setFloorNumber(FloorNumber);
		input >> n;

		int NumberOfRooms;
		input >> NumberOfRooms;
		f[i].setNumberOfRooms(NumberOfRooms);
		for (int j = 0; j < f[i].getNumberOfRooms(); j++)
		{
			input >> n;

			if (n == "Standard,")
			{
				Standard* p = new Standard;
				f[i].r[j] = p;
				p->setKind("Standard");
				int x;
				input >> x;
				p->setRoomnumber(x);
				input >> n;
				input >> x;
				p->setNumberOfBeds(x);
				input >> n;
				double y;
				input >> y;
				p->setBedPrice(y);
				input >> n;
			}
			else if (n == "Sweet,")
			{
				Sweet* p = new Sweet;
				f[i].r[j] = p;
				p->setKind("Sweet");
				int x;
				input >> x;
				p->setRoomnumber(x);

				input >> n;
				double y;
				input >> y;
				p->setPricePerNight(y);
			}
			else if (n == "Conference,")
			{
				Conference* p = new Conference;
				f[i].r[j] = p;
				p->setKind("Conference");
				int x;
				input >> x;
				p->setRoomnumber(x);
				input >> n;
				input >> x;
				p->setNumberOfSeats(x);
				input >> n;
				double y;
				input >> y;
				p->setSeatPrice(y);
				input >> n;
			}
		}
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                                               ***********\n";
	cout << "                                               *AKN Hotel*\n";
	cout << "                                               ***********\n";
	system("pause");
	system("cls");
	Menu(f, numberoffloors);
	return 0;
}
void WriteFile()
{
	ofstream output;
	output.open("configuration.txt");
	output << "#floor: " << 3 << endl;
	output << "Floor# " << 1 << ",#Rooms: " << 3 << endl;
	output << "Standard, " << 101 << " , " << 2 << " , " << 25 << " . " << endl;
	output << "Standard, " << 102 << " , " << 3 << " , " << 25 << " . " << endl;
	output << "Conference, " << 103 << " , " << 30 << " , " << 5 << " . " << endl;
	output << "Floor# " << 2 << ",#Rooms: " << 2 << endl;
	output << "Standard, " << 201 << " , " << 1 << " , " << 25 << " . " << endl;
	output << "Sweet, " << 202 << " , " << 300 << endl;
	output << "Floor# " << 3 << ",#Rooms: " << 2 << endl;
	output << "Standard, " << 301 << " , " << 3 << " , " << 25 << " . " << endl;
	output << "Sweet, " << 302 << " , " << 400 << endl;
	output.close();
}
void displayallrooms(Floor*& f, int NumberOfFloors)
{
	for (int i = 0; i < NumberOfFloors; i++)
	{
		cout << endl;
		cout << "Floor" << i + 1 << endl;
		cout << endl;
		f[i].display();


	}
}
bool search(Floor*& f, int numberoffloors, string type, int& floornumber, int& roomnumber)
{
	for (int i = 0; i < numberoffloors; i++)
	{
		for (int j = 0; j < f[i].getNumberOfRooms(); j++)
		{
			if (f[i].r[j]->getKind() == type && f[i].r[j]->getIsReversed() == false)
			{
				floornumber = i;
				roomnumber = j;
				return true;
			}
		}
	}
	return false;
}
void Reserve(Floor*& fl, int numberoffloorss)
{
	int x;
	int Floornumber = 0;
	int Roomnumber = 0;
lets:
	system("cls");
	cout << "What Kind Of Rooms Do You Want To Reserve ?\n";
	cout << "For Standard click 1\n";
	cout << "For Sweet click 2\n";
	cout << "For Conference click 3\n";
	cin >> x;
	if (x == 1)
	{
		bool y = search(fl, numberoffloorss, "Standard", Floornumber, Roomnumber);
		if (y == true)
		{
			fl[Floornumber].r[Roomnumber]->setIsReversed(true);
			int z = 0;
			cout << "HoW Long Will You Stay\n";
			cin >> z;
			fl[Floornumber].r[Roomnumber]->setDayOfReservation(z);
			cout << "You Reseved Correctily\n\a";
			cout << "The PRice Of The Stay    " << fl[Floornumber].r[Roomnumber]->getTotalPrice() << endl;
		}
		else
		{
			cout << "There Is No Standard Rooms Available\n";
			cout << "Do You Want To Reserve Another Kind of Rooms Or Not \n";
			int k = 0;
			cout << "if Yes click 1\n";
			cin >> k;
			if (k == 1)
			{
				goto lets;
			}
		}

	}
	else if (x == 2)
	{
		bool y = search(fl, numberoffloorss, "Sweet", Floornumber, Roomnumber);
		if (y == true)
		{
			fl[Floornumber].r[Roomnumber]->setIsReversed(true);
			int z = 0;
			cout << "HoW Long Will You Stay\n";
			cin >> z;
			fl[Floornumber].r[Roomnumber]->setDayOfReservation(z);
			cout << "You Reseved Correctily\n\a";
			cout << "The PRice Of The Stay    " << fl[Floornumber].r[Roomnumber]->getTotalPrice() << endl;
		}
		else
		{
			cout << "There Is No Sweet Rooms Available\n";
			cout << "Do You Want To Reserve Another Kind of Rooms Or Not \n";
			int k = 0;
			cout << "if Yes click 1\n";
			cin >> k;
			if (k == 1)
			{
				goto lets;
			}
		}
	}
	else if (x == 3)
	{
		bool y = search(fl, numberoffloorss, "Conference", Floornumber, Roomnumber);
		if (y == true)
		{
			fl[Floornumber].r[Roomnumber]->setIsReversed(true);
			int z = 0;
			cout << "HoW Long Will You Stay\n";
			cin >> z;
			fl[Floornumber].r[Roomnumber]->setDayOfReservation(z);
			cout << "You Reseved Correctily\n\a";
			cout << "The PRice Of The Stay     " << fl[Floornumber].r[Roomnumber]->getTotalPrice() << endl;
		}
		else
		{
			cout << "There Is No Conference Rooms Available\n";
			cout << "Do You Want To Reserve Another Kind of Rooms Or Not \n";
			int k = 0;
			cout << "if Yes click 1\n";
			cin >> k;
			if (k == 1)
			{
				goto lets;
			}
		}
	}
	else
	{
		cout << "Wrong Input \n";
		system("pause");
		goto lets;
	}
}
void CancelReservation(Floor*& f, int floornumber, int numberofroom)
{
	for (int i = 0; i < f[floornumber - 1].getNumberOfRooms(); i++)
	{
		if (f[floornumber - 1].r[i]->getRoomNumber() == numberofroom)
		{
			f[floornumber - 1].r[i]->setIsReversed(false);
			f[floornumber - 1].r[i]->setDayOfReservation(0);
		}
	}

	cout << "You Cnceled The Reservation correctiy\n\a";
}
double HotelPrice(Floor*& f, int numberoffloors)
{
	double sum = 0;
	for (int i = 0; i < numberoffloors; i++)
	{
		for (int j = 0; j < f[i].getNumberOfRooms(); j++)
		{
			if (f[i].r[j]->getIsReversed() == true)
			{
				sum += f[i].r[j]->getTotalPrice();
			}
		}
	}
	return sum;
}
void Menu(Floor*& f, int numberoffloors)
{
	int N;
let:
	system("cls");
	cout << "Menu  \n";
	cout << "For Reservation click 1\n";
	cout << "For Cancel Reservation click 2\n";
	cout << "For Display All Rooms click 3\n";
	cout << "For Display Available Room In Particular Floor click 4\n";
	cout << "For Display Total Expected Profit Of Hotel click 5\n";
	cout << "For Leave The Application click 6\n";
	cin >> N;
	system("cls");
	if (N == 1)
	{
		Reserve(f, numberoffloors);
		system("pause");
		goto let;
	}
	else if (N == 2)
	{
		int floornumber;
		int roomnumber;
		cout << "Enter Floor Number Of The Room You Want To Cancel Its Reservation\n";
		cin >> floornumber;
		cout << "Enter Room Number You Want To Cancel Its Reservation\n";
		cin >> roomnumber;
		CancelReservation(f, floornumber, roomnumber);
		system("pause");
		goto let;
	}
	else if (N == 3)
	{
		displayallrooms(f, numberoffloors);
		system("pause");
		goto let;
	}
	else if (N == 4)
	{
		int floornumber;
		cout << "Enter Floor Number\n";
		cin >> floornumber;
		f[floornumber - 1].AvailableRooms();
		system("pause");
		goto let;
	}
	else if (N == 5)
	{
		cout << "Hotel Profit Is " << HotelPrice(f, numberoffloors) << endl;
		system("pause");
		goto let;
	}
	else if(N==6)
	{
		exit;
	}
	else
	{
		cout << "Wrong Input\n";
		system("pause");
		goto let;
	}
}