#include <string>
using namespace std;

#ifndef Address_H
#define Address_H

class Address
{
public:
	//Constructors and destructor
	Address();
	Address(float latitude, float longitude, int housenumber, string streetname);
	Address(const Address& orig);
	~Address();

	float getLatitude();
	float getLongitude();
	int getHouseNumber();
	string getStreetName();
	void setLatitude(float latitude);
	void setLongitude(float longitude);
	void setHouseNumber(int housenumber);
	void setStreetName(string streetname);
	void print() const;

private:
	float Latitude;
	float Longitude;
	int HouseNumber;
	string StreetName;

};

#endif
