#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include "Address.h"
using namespace std;

Address BinarySearch(vector<Address>AddressList, string StreetName, int HouseNumber, int low, int high)
{
	Address result;
	int mid = (low + high) / 2;
	if (low > high)
	{
		return result;
	}
	else if (AddressList[mid].getStreetName() == StreetName)
	{
		if (AddressList[mid].getHouseNumber() == HouseNumber)
		{
			result = AddressList[mid];
			return result;
		}
		else if (AddressList[mid].getHouseNumber() > HouseNumber)
		{
			result = BinarySearch(AddressList, StreetName, HouseNumber, low, mid - 1);
		}
		else if (AddressList[mid].getHouseNumber() < HouseNumber)
		{
			result = BinarySearch(AddressList, StreetName, HouseNumber, mid + 1, high);
		}
	}
	else if (AddressList[mid].getStreetName() > StreetName)
	{
		result = BinarySearch(AddressList, StreetName, HouseNumber, low, mid - 1);
	}
	else if (AddressList[mid].getStreetName() < StreetName)
	{
		result = BinarySearch(AddressList, StreetName, HouseNumber, mid + 1, high);
	}
	return result;

}

int main()
{
	// Local variables
	float lat = 0;
	float lon = 0;
	int num = 0;
	int command = 0;
	int SearchHouse = 0;
	string street = "";
	string SearchStreet = "";
	Address address;
	Address SearchAddress;
	char ch = ' ';
	vector<Address>street_vector;
	int count = 0;

	// Open input file
	ifstream din;
	din.open("input1.txt");

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
			cout << "Please enter the Street that this house is located on." << endl;
			getline(cin, SearchStreet);
			cout << "Please enter the number of this house." << endl;
			cin >> SearchHouse;
			SearchAddress = BinarySearch(street_vector, SearchStreet, SearchHouse, 0, street_vector.size() - 1);
			if (SearchAddress.getStreetName() == SearchStreet && SearchAddress.getHouseNumber() == SearchHouse)
			{
				cout << "Here is the house you searched for." << endl;
				SearchAddress.print();
			}
			else
			{
				cout << "The house you entered was not in our list of houses." << endl;
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
