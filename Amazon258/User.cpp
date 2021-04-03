#include "User.h"
#include <iostream>
#include<string.h>
using namespace std; 

User::User(string userName, string userPass, const Address& userAdress)
	: userAddress(userAdress)
{
	this->userName = userName;
	this->userPassword = userPass;
}

User::User(const User& userCopy)
	:userAddress(userCopy.userAddress)
{
	this->userName = userName;
	this->userPassword = userPassword;
}

User::User(ifstream& inFile):userAddress(inFile)
{
	inFile >> this->userName;
	inFile >> this->userPassword;
}

User::~User() { }

const string User:: getUserName()const
{
	return this->userName;
}

const Address& User::getAddress() 
{
	return userAddress;
}

void User::show()const 
{
	cout << this->userName << endl;
	userAddress.showAdress();
}

const string User::getPassword()const
{
	return this->userPassword;
}