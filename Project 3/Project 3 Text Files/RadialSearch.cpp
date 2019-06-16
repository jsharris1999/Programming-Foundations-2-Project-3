#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include "Address.h"
using namespace std;

void RadialSearch(vector<Address>AddressList, vector<Address>&RadialResults, float latitude, float longitude, float radius, int low, int high)
{
	int i = 0;
	float LowRangeLatitude = latitude - radius;
	float HighRangeLatitude = latitude + radius;
	float LowRangeLongitude = longitude - radius;
	float HighRangeLongitude = longitude + radius;
	cout << LowRangeLatitude << endl;
	cout << HighRangeLatitude << endl;
	cout << LowRangeLongitude << endl;
	cout << LowRangeLongitude << endl;
	int mid = (low + high) / 2;
	if (low > high)
	{
		return;
	}
	else if (AddressList[mid].getLatitude() >= HighRangeLatitude)
	{
		i = mid;
		while (AddressList[i].getLatitude() >= LowRangeLatitude)
		{
			if (AddressList[i].getLatitude() >= LowRangeLatitude && AddressList[i].getLatitude() <= HighRangeLatitude)
			{
				if (AddressList[i].getLongitude() >= LowRangeLongitude && AddressList[i].getLongitude() <= HighRangeLongitude)
				{
					RadialResults.push_back(AddressList[i]);
				}
			}
			i--;
		}
	}
	else if (AddressList[mid].getLatitude() <= LowRangeLatitude)
	{
		i = mid;
		while (AddressList[i].getLatitude() < HighRangeLatitude)
		{
			if (AddressList[i].getLatitude() >= LowRangeLatitude && AddressList[i].getLatitude() <= HighRangeLatitude)
			{
				if (AddressList[i].getLongitude() >= LowRangeLongitude && AddressList[i].getLongitude() <= HighRangeLongitude)
				{
					RadialResults.push_back(AddressList[i]);
				}
			}
			i++;
		}
	}
	else if (AddressList[mid].getLatitude() > LowRangeLatitude && AddressList[mid].getLatitude() < HighRangeLatitude)
	{
		i = mid;
		while (AddressList[i].getLatitude() < HighRangeLatitude)
		{
			if (AddressList[i].getLatitude() >= LowRangeLatitude && AddressList[i].getLatitude() <= HighRangeLatitude)
			{
				if (AddressList[i].getLongitude() >= LowRangeLongitude && AddressList[i].getLongitude() <= HighRangeLongitude)
				{
					RadialResults.push_back(AddressList[i]);
				}
			}
			i++;
		}
		i = mid;
		while (AddressList[i].getLatitude() > LowRangeLatitude)
		{
			if (AddressList[i].getLatitude() >= LowRangeLatitude && AddressList[i].getLatitude() <= HighRangeLatitude)
			{
				if (AddressList[i].getLongitude() >= LowRangeLongitude && AddressList[i].getLongitude() <= HighRangeLongitude)
				{
					RadialResults.push_back(AddressList[i]);
				}
			}
			i--;
		}
	}
}

int main()
{
	// Local variables
	float lat = 0;
	float lon = 0;
	float radius = 0;
	int num = 0;
	int command = 0;
	string street = "";
	string SearchStreet = "";
	Address address;
	vector<Address>SearchAddress;
	char ch = ' ';
	vector<Address>street_vector;
	int count = 0;

	// Open input file
	ifstream din;
	din.open("input2.txt");

	// Loop reading address information
	while (din >> lat >> lon >> num)
	{
		// Skip space after num
		din.get(ch);

		// Read rest of line
		getline(din, street);

		address.setLatitude(lat);
		address.setLongitude(lon);
		address.setHouseNumber(num);
		address.setStreetName(street);

		// Add to end of street vector
		street_vector.push_back(address);

		/*Print debug info
		cout << count << ","
			<< lat << ","
			<< lon << ","
			<< num << ","
			<< street << ",\n";
		count++;
		*/

	}

	cout << "Welcome to our house searching service." << endl;
	while (command != 2)
	{
		cout << "Enter 1 if you would like to search for an address, or 2 if you would like to exit." << endl;
		cin >> command;
		cin.ignore();
		while ((command != 1) && (command != 2))
		{
			command = 0;
			cout << "That command is not valid." << endl;
			cin >> command;
			cin.ignore();
		}
		if (command == 1)
		{
			cout << "Please enter the initial latitude." << endl;
			cin >> lat;
			cout << "Please enter the initial longitude." << endl;
			cin >> lon;
			cout << "Please enter the search radius." << endl;
			cin >> radius;
			RadialSearch(street_vector, SearchAddress, lat, lon, radius, 0, street_vector.size() - 1);
			if (SearchAddress.size() < 1)
			{
				cout << "No houses were found within the specified range." << endl;
			}
			else
			{
				cout << "Here is the list of houses that were found within these parameters." << endl;
				for (int j = 0; j < SearchAddress.size(); j++)
				{
					SearchAddress[j].print();
					cout << endl;
					SearchAddress.erase(SearchAddress.begin() + 1);
				}
			}
			command = 0;
		}
		else if (command == 2)
		{
			cout << "Thank you for using our service." << endl;

		}
	}
	return 0;
}