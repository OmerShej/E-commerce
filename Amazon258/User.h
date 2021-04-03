#pragma once
#include "Address.h"
#include <string>

class User {

protected:
	Address userAddress;
	string userName;
	string userPassword;

	// user is an abstract class therefore we won't create object of user out of the inhert calsses 
	User(string userName, string userPass, const Address& userAdress);
	User(ifstream& inFile);
	User() {};
	
public:
	virtual ~User();
	const string getUserName()const;
	const Address& getAddress();
	const string getPassword()const;
	virtual void show()const=0;
	User(const User& userCopy);
};
