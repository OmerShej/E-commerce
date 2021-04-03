#include "Address.h"

void const getAddressForFile() {

}
Address::Address(ifstream& inFile)
{
	inFile >> this->city;
	inFile >> this->street;
	inFile >> this->houseNum;
	inFile >> this->zipCode;

}

Address::Address(string street, string city, int houseNum, int zipCode)
 {
	    this->city = city;
		this->street = street;
		this->houseNum = houseNum;
		this->zipCode = zipCode;
}

Address::Address(const Address& adress)
{
	this->city = adress.city;
	this->street = adress.street;
	this->houseNum = adress.houseNum;
	this->zipCode = adress.zipCode;
}

// default c'tor 
Address::Address()
{
	this->city = "defualt city";
	this->street = "defualt street";
	this->houseNum = 00000000;
	this->zipCode = 00000000;
}

void Address::showAdress()const
{
	cout << "street: "<< street << ", number: " << this->houseNum << ",city: " << this->city << endl;
}

ostream& operator<<(ostream& os, const Address& address)
{
	os << "Address: " << address.street << " " << address.houseNum << " " << address.city << " " << address.zipCode << endl;
	return os;
}

string Address::getStreet()const 
{
	return this->street;
}

string Address::getCity()const 
{
	return this->city;
}

int Address::gethouseNum()const 
{
	return this->houseNum;
}

int Address::getzipCode()const 
{
	return this->zipCode;
}
