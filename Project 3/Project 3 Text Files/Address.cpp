#include <string>
#include <iostream>
#include <cmath>
#include "Address.h"
using namespace std;

Address::Address()
{
	Latitude = 0.0;
	Longitude = 0.0;
	HouseNumber = 0;
	StreetName = "N/A";
}

Address::Address(float latitude, float longitude, int housenumber, string streetname)
{
	Latitude = latitude;
	Longitude = longitude;
	HouseNumber = housenumber;
	StreetName = streetname;
}

Address::Address(const Address& orig)
{
	Latitude = orig.Latitude;
	Longitude = orig.Longitude;
	HouseNumber = orig.HouseNumber;
	StreetName = orig.StreetName;
}

Address::~Address()
{

}

float Address::getLatitude()
{
	return Latitude;
}

float Address::getLongitude()
{
	return Longitude;
}

int Address::getHouseNumber()
{
	return HouseNumber;
}

string Address::getStreetName()
{
	return StreetName;
}

void Address::setLatitude(float latitude)
{
	Latitude = latitude;
}

void Address::setLongitude(float longitude)
{
	Longitude = longitude;
}

void Address::setHouseNumber(int housenumber)
{
	HouseNumber = housenumber;
}

void Address::setStreetName(string streetname)
{
	StreetName = streetname;
}

void Address::print() const
{
	cout << "Latitude: " << Latitude << endl;
	cout << "Longitude: " << Longitude << endl;
	cout << "House Number: " << HouseNumber << endl;
	cout << "Street Name: " << StreetName << endl;
}
