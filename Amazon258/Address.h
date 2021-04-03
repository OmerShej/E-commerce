#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
static const int MAX_LENGTH = 30;

class Address
{
private:
	string street;
	string city;
	int houseNum, zipCode;

public:
	Address(string street, string city, int houseNum, int zipCode);
	Address(const Address& adress);
	Address(ifstream& inFile);
	Address();

	friend ostream& operator<<(ostream& os, const Address& address);
	void showAdress()const;
	string getStreet()const;
	string getCity()const;
	int gethouseNum()const;
	int getzipCode()const;
};